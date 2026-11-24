/*-
 * Public Domain 2014-present MongoDB, Inc.
 * Public Domain 2008-2014 WiredTiger, Inc.
 *
 * This is free and unencumbered software released into the public domain.
 *
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 *
 * In jurisdictions that recognize copyright laws, the author or authors
 * of this software dedicate any and all copyright interest in the
 * software to the public domain. We make this dedication for the benefit
 * of the public at large and to the detriment of our heirs and
 * successors. We intend this dedication to be an overt act of
 * relinquishment in perpetuity of all present and future rights to this
 * software under copyright law.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#include <wiredtiger_config.h>
#if defined(_M_AMD64)
#include <intrin.h>
#endif
#include <inttypes.h>
#include <stddef.h>

#if !defined(HAVE_NO_CRC32_HARDWARE)
#if (defined(__amd64) || defined(__x86_64))
#include "crc32-x86-consts.h"

#if WT_CRC32C_STREAM_WORDS <= 0
#error "WT_CRC32C_STREAM_WORDS must be greater than zero"
#endif

extern int wiredtiger_crc32c_three_stream_enabled(void);

/*
 * The CRC32C instruction has a dependent-chain latency of about three cycles. Run three
 * independent chains over adjacent regions and combine their registers with GF(2) zero shifts.
 * The lookup tables and stream length are generated together; checksum formats do not change.
 */
static inline uint32_t
__crc32c_step_u64(uint32_t crc, uint64_t value)
{
    __asm__ __volatile__(".byte 0xF2, 0x48, 0x0F, 0x38, 0xF1, 0xF1"
      : "=S"(crc)
      : "0"(crc), "c"(value));
    return (crc);
}

static inline uint32_t
__crc32c_step_u8(uint32_t crc, uint8_t value)
{
    __asm__ __volatile__(".byte 0xF2, 0x0F, 0x38, 0xF0, 0xF1" : "=S"(crc) : "0"(crc), "c"(value));
    return (crc);
}

static inline uint32_t
__crc32c_shift_apply(const uint32_t table[4][256], uint32_t crc)
{
    return (table[0][crc & 0xff] ^ table[1][(crc >> 8) & 0xff] ^ table[2][(crc >> 16) & 0xff] ^
      table[3][crc >> 24]);
}

static __attribute__((noinline)) uint32_t
__crc32c_large(uint32_t seed, const void *chunk, size_t len)
{
    const uint64_t *p1, *p2, *p64;
    const uint8_t *p;
    size_t i, nqwords;
    uint32_t crc, crc_a, crc_b, crc_c;

    crc = ~seed;
    for (p = chunk; ((uintptr_t)p & (sizeof(uint64_t) - 1)) != 0 && len > 0; ++p, --len)
        crc = __crc32c_step_u8(crc, *p);
    p64 = (const uint64_t *)p;

    for (; len >= WT_CRC32C_BLOCK_BYTES; len -= WT_CRC32C_BLOCK_BYTES) {
        p1 = p64 + WT_CRC32C_STREAM_WORDS;
        p2 = p64 + 2 * WT_CRC32C_STREAM_WORDS;
        crc_a = crc;
        crc_b = crc_c = 0;
        for (i = 0; i < WT_CRC32C_STREAM_WORDS; ++i) {
            crc_a = __crc32c_step_u64(crc_a, p64[i]);
            crc_b = __crc32c_step_u64(crc_b, p1[i]);
            crc_c = __crc32c_step_u64(crc_c, p2[i]);
        }
        crc = __crc32c_shift_apply(__crc32c_shift_two, crc_a) ^
          __crc32c_shift_apply(__crc32c_shift_one, crc_b) ^ crc_c;
        p64 += 3 * WT_CRC32C_STREAM_WORDS;
    }

    for (nqwords = len / sizeof(uint64_t); nqwords; nqwords--)
        crc = __crc32c_step_u64(crc, *p64++);
    p = (const uint8_t *)p64;
    for (len &= 0x7; len > 0; ++p, len--)
        crc = __crc32c_step_u8(crc, *p);
    return (~crc);
}

/*
 * __checksum_with_seed_hw --
 *     Return a checksum for a chunk of memory, computed in hardware using 8 byte steps. Start with
 *     the given seed.
 */
static uint32_t
__checksum_with_seed_hw(uint32_t seed, const void *chunk, size_t len)
{
    uint32_t crc;
    size_t nqwords;
    const uint8_t *p;
    const uint64_t *p64;

    if (len >= WT_CRC32C_BLOCK_BYTES && wiredtiger_crc32c_three_stream_enabled())
        return (__crc32c_large(seed, chunk, len));

    crc = ~seed;

    /* Checksum one byte at a time to the first 8B boundary. */
    for (p = chunk; ((uintptr_t)p & (sizeof(uint64_t) - 1)) != 0 && len > 0; ++p, --len) {
        __asm__ __volatile__(".byte 0xF2, 0x0F, 0x38, 0xF0, 0xF1" : "=S"(crc) : "0"(crc), "c"(*p));
    }

    p64 = (const uint64_t *)p;
    /* Checksum in 8B chunks. */
    for (nqwords = len / sizeof(uint64_t); nqwords; nqwords--) {
        __asm__ __volatile__(".byte 0xF2, 0x48, 0x0F, 0x38, 0xF1, 0xF1"
          : "=S"(crc)
          : "0"(crc), "c"(*p64));
        p64++;
    }

    /* Checksum trailing bytes one byte at a time. */
    p = (const uint8_t *)p64;
    for (len &= 0x7; len > 0; ++p, len--) {
        __asm__ __volatile__(".byte 0xF2, 0x0F, 0x38, 0xF0, 0xF1" : "=S"(crc) : "0"(crc), "c"(*p));
    }
    return (~crc);
}

/*
 * __checksum_hw --
 *     Return a checksum for a chunk of memory, computed in hardware using 8 byte steps.
 */
static uint32_t
__checksum_hw(const void *chunk, size_t len)
{
    return (__checksum_with_seed_hw(0, chunk, len));
}
#endif

#if defined(_M_AMD64)
/*
 * __checksum_with_seed_hw --
 *     Return a checksum for a chunk of memory, computed in hardware using 8 byte steps. Start with
 *     the given seed.
 */
static uint32_t
__checksum_with_seed_hw(uint32_t seed, const void *chunk, size_t len)
{
    uint32_t crc;
    size_t nqwords;
    const uint8_t *p;
    const uint64_t *p64;

    crc = ~seed;

    /* Checksum one byte at a time to the first 4B boundary. */
    for (p = chunk; ((uintptr_t)p & (sizeof(uint32_t) - 1)) != 0 && len > 0; ++p, --len) {
        crc = _mm_crc32_u8(crc, *p);
    }

    p64 = (const uint64_t *)p;
    /* Checksum in 8B chunks. */
    for (nqwords = len / sizeof(uint64_t); nqwords; nqwords--) {
        crc = (uint32_t)_mm_crc32_u64(crc, *p64);
        p64++;
    }

    /* Checksum trailing bytes one byte at a time. */
    p = (const uint8_t *)p64;
    for (len &= 0x7; len > 0; ++p, len--) {
        crc = _mm_crc32_u8(crc, *p);
    }

    return (~crc);
}

/*
 * __checksum_hw --
 *     Return a checksum for a chunk of memory, computed in hardware using 8 byte steps.
 */
static uint32_t
__checksum_hw(const void *chunk, size_t len)
{
    return (__checksum_with_seed_hw(0, chunk, len));
}
#endif
#endif

extern uint32_t __wt_checksum_sw(const void *chunk, size_t len);
extern uint32_t __wt_checksum_with_seed_sw(uint32_t, const void *chunk, size_t len);
#if defined(__GNUC__)
extern uint32_t (*wiredtiger_crc32c_func(void))(const void *, size_t)
  __attribute__((visibility("default")));
extern uint32_t (*wiredtiger_crc32c_with_seed_func(void))(uint32_t, const void *, size_t)
  __attribute__((visibility("default")));
#else
extern uint32_t (*wiredtiger_crc32c_func(void))(const void *, size_t);
extern uint32_t (*wiredtiger_crc32c_with_seed_func(void))(uint32_t, const void *, size_t);
#endif

#if defined(__GNUC__)
#define WT_CRC32C_CACHE_LOAD(cache) __atomic_load_n(&(cache), __ATOMIC_RELAXED)
#define WT_CRC32C_CACHE_STORE(cache, value) \
    (__atomic_store_n(&(cache), (value), __ATOMIC_RELAXED), (value))
#else
#define WT_CRC32C_CACHE_LOAD(cache) (cache)
#define WT_CRC32C_CACHE_STORE(cache, value) ((cache) = (value))
#endif

/*
 * wiredtiger_crc32c_func --
 *     WiredTiger: detect CRC hardware and return the checksum function.
 */
uint32_t (*wiredtiger_crc32c_func(void))(const void *, size_t)
{
    static uint32_t (*crc32c_func)(const void *, size_t);
    uint32_t (*cached)(const void *, size_t);
#if !defined(HAVE_NO_CRC32_HARDWARE)
#if (defined(__amd64) || defined(__x86_64))
    unsigned int eax, ebx, ecx, edx;
#endif
#endif

    cached = WT_CRC32C_CACHE_LOAD(crc32c_func);
    if (cached != NULL)
        return (cached);

#if !defined(HAVE_NO_CRC32_HARDWARE)
#if (defined(__amd64) || defined(__x86_64))
    __asm__ __volatile__("cpuid" : "=a"(eax), "=b"(ebx), "=c"(ecx), "=d"(edx) : "a"(1));

#define CPUID_ECX_HAS_SSE42 (1 << 20)
    if (ecx & CPUID_ECX_HAS_SSE42)
        return (WT_CRC32C_CACHE_STORE(crc32c_func, __checksum_hw));
    return (WT_CRC32C_CACHE_STORE(crc32c_func, __wt_checksum_sw));

#elif defined(_M_AMD64)
    int cpuInfo[4];

    __cpuid(cpuInfo, 1);

#define CPUID_ECX_HAS_SSE42 (1 << 20)
    if (cpuInfo[2] & CPUID_ECX_HAS_SSE42)
        return (WT_CRC32C_CACHE_STORE(crc32c_func, __checksum_hw));
    return (WT_CRC32C_CACHE_STORE(crc32c_func, __wt_checksum_sw));
#else
    return (WT_CRC32C_CACHE_STORE(crc32c_func, __wt_checksum_sw));
#endif
#else
    return (WT_CRC32C_CACHE_STORE(crc32c_func, __wt_checksum_sw));
#endif
}

/*
 * wiredtiger_crc32c_with_seed_func --
 *     WiredTiger: detect CRC hardware and return the checksum function that accepts a starting
 *     seed.
 */
uint32_t (*wiredtiger_crc32c_with_seed_func(void))(uint32_t, const void *, size_t)
{
    static uint32_t (*crc32c_func)(uint32_t, const void *, size_t);
    uint32_t (*cached)(uint32_t, const void *, size_t);
#if !defined(HAVE_NO_CRC32_HARDWARE)
#if (defined(__amd64) || defined(__x86_64))
    unsigned int eax, ebx, ecx, edx;
#endif
#endif

    cached = WT_CRC32C_CACHE_LOAD(crc32c_func);
    if (cached != NULL)
        return (cached);

#if !defined(HAVE_NO_CRC32_HARDWARE)
#if (defined(__amd64) || defined(__x86_64))
    __asm__ __volatile__("cpuid" : "=a"(eax), "=b"(ebx), "=c"(ecx), "=d"(edx) : "a"(1));

#define CPUID_ECX_HAS_SSE42 (1 << 20)
    if (ecx & CPUID_ECX_HAS_SSE42)
        return (WT_CRC32C_CACHE_STORE(crc32c_func, __checksum_with_seed_hw));
    return (WT_CRC32C_CACHE_STORE(crc32c_func, __wt_checksum_with_seed_sw));

#elif defined(_M_AMD64)
    int cpuInfo[4];

    __cpuid(cpuInfo, 1);

#define CPUID_ECX_HAS_SSE42 (1 << 20)
    if (cpuInfo[2] & CPUID_ECX_HAS_SSE42)
        return (WT_CRC32C_CACHE_STORE(crc32c_func, __checksum_with_seed_hw));
    return (WT_CRC32C_CACHE_STORE(crc32c_func, __wt_checksum_with_seed_sw));
#else
    return (WT_CRC32C_CACHE_STORE(crc32c_func, __wt_checksum_with_seed_sw));
#endif
#else
    return (WT_CRC32C_CACHE_STORE(crc32c_func, __wt_checksum_with_seed_sw));
#endif
}
