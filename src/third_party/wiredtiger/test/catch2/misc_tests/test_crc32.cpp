/*-
 * Copyright (c) 2014-present MongoDB, Inc.
 * Copyright (c) 2008-2014 WiredTiger, Inc.
 *	All rights reserved.
 *
 * See the file LICENSE for redistribution information.
 */

#include <catch2/catch.hpp>
#include <ctime>
#include <cmath>

#include "wt_internal.h"

TEST_CASE("CRC calculations: crc32c", "[crc32c]")
{
    auto crc32c = wiredtiger_crc32c_func();
    auto crc32c_with_seed = wiredtiger_crc32c_with_seed_func();

    REQUIRE(crc32c(nullptr, 0) == 0);
    REQUIRE(crc32c("", 0) == 0);
    REQUIRE(crc32c("non-empty", 0) == 0);

    std::srand((unsigned int)time(nullptr));
    uint32_t rnd_seed = std::rand();
    REQUIRE(crc32c_with_seed(rnd_seed, nullptr, 0) == rnd_seed);
    REQUIRE(crc32c_with_seed(rnd_seed, "", 0) == rnd_seed);
    REQUIRE(crc32c_with_seed(rnd_seed, "non-empty", 0) == rnd_seed);

    const std::vector<uint8_t> no_bits_set = {0x00, 0x00, 0x00, 0x00};
    REQUIRE(crc32c(&no_bits_set[0], no_bits_set.size()) == 0x48674bc7);

    const uint32_t zero_point = 0x9BE09BAB;
    REQUIRE(crc32c(&zero_point, sizeof(zero_point)) == 0);

    const std::vector<uint8_t> all_bits_set = {0xff, 0xff, 0xff, 0xff};
    REQUIRE(crc32c(&all_bits_set[0], all_bits_set.size()) == 0xffffffff);

    const std::string chunk = "this is a really long string";
    std::string lots_of_data = chunk;
    for (int i = 0; i < 10; i++)
        lots_of_data += lots_of_data;
    REQUIRE(crc32c(lots_of_data.c_str(), lots_of_data.length()) == 0x47a00ee5);

    // Compute CRC in chunks
    uint32_t crc_val = 0;
    crc_val = crc32c_with_seed(crc_val, lots_of_data.c_str(), chunk.length());
    for (int i = 0; i < 10; i++) {
        uint64_t size = chunk.length() * (uint64_t)pow(2, i);
        crc_val = crc32c_with_seed(crc_val, lots_of_data.c_str() + size, size);
    }
    REQUIRE(crc_val == 0x47a00ee5);
}

namespace {
uint32_t
reference_crc32c_with_seed(uint32_t seed, const uint8_t *data, size_t len)
{
    uint32_t crc = ~seed;
    for (size_t i = 0; i < len; ++i) {
        crc ^= data[i];
        for (int bit = 0; bit < 8; ++bit)
            crc = (crc >> 1) ^ ((crc & 1) ? 0x82F63B78U : 0U);
    }
    return (~crc);
}

std::vector<uint8_t>
make_crc_bytes(size_t size)
{
    std::vector<uint8_t> bytes(size);
    uint64_t state = 99;
    for (auto &b : bytes) {
        state = state * 6364136223846793005ULL + 1442695040888963407ULL;
        b = (uint8_t)(state >> 56);
    }
    return (bytes);
}

struct CRCThreeStreamGuard {
    int previous = wiredtiger_crc32c_three_stream_enabled();
    ~CRCThreeStreamGuard()
    {
        wiredtiger_crc32c_three_stream_set_enabled(previous);
    }
};
} // namespace

TEST_CASE("CRC calculations: three-stream switch matches bit-serial reference", "[crc32c]")
{
    CRCThreeStreamGuard guard;
    auto crc32c = wiredtiger_crc32c_func();
    auto seeded = wiredtiger_crc32c_with_seed_func();
    const size_t sizes[] = {0, 1, 2, 7, 8, 9, 15, 16, 17, 511, 512, 1023, 1024, 3071, 3072,
      3073, 3080, 4095, 4096, 4097, 6143, 6144, 6145, 6152, 9215, 9216, 9217, 12287, 12288,
      12289, 65536, 65537, 100003};
    for (size_t size : sizes) {
        const auto bytes = make_crc_bytes(size + 64);
        for (size_t offset = 0; offset < 16; ++offset) {
            const auto *p = bytes.data() + offset;
            const auto expected = reference_crc32c_with_seed(0, p, size);
            const auto expected_seeded = reference_crc32c_with_seed(0xdeadbeef, p, size);
            INFO("size=" << size << " offset=" << offset);
            for (int enabled : {0, 1, 0}) {
                wiredtiger_crc32c_three_stream_set_enabled(enabled);
                REQUIRE(wiredtiger_crc32c_three_stream_enabled() == enabled);
                REQUIRE(crc32c(p, size) == expected);
                REQUIRE(seeded(0, p, size) == expected);
                REQUIRE(seeded(0xdeadbeef, p, size) == expected_seeded);
            }
        }
    }
}

TEST_CASE("CRC calculations: chaining across three-stream switch", "[crc32c]")
{
    CRCThreeStreamGuard guard;
    auto crc32c = wiredtiger_crc32c_func();
    auto seeded = wiredtiger_crc32c_with_seed_func();
    const auto bytes = make_crc_bytes(40000);
    const auto expected = reference_crc32c_with_seed(0, bytes.data(), bytes.size());
    const size_t splits[] = {1, 7, 8, 3071, 3072, 3073, 6144, 12288, 20000, 39999};
    for (size_t split : splits) {
        for (int enabled : {0, 1}) {
            wiredtiger_crc32c_three_stream_set_enabled(enabled);
            REQUIRE(crc32c(bytes.data(), bytes.size()) == expected);
            const auto first = seeded(0, bytes.data(), split);
            wiredtiger_crc32c_three_stream_set_enabled(!enabled);
            REQUIRE(seeded(first, bytes.data() + split, bytes.size() - split) == expected);
        }
    }
}

TEST_CASE("CRC calculations: three-stream uniform buffers", "[crc32c]")
{
    CRCThreeStreamGuard guard;
    auto crc32c = wiredtiger_crc32c_func();
    for (uint8_t fill : {(uint8_t)0x00, (uint8_t)0xff, (uint8_t)0x5a}) {
        const std::vector<uint8_t> bytes(20000, fill);
        const auto expected = reference_crc32c_with_seed(0, bytes.data(), bytes.size());
        for (int enabled : {0, 1}) {
            wiredtiger_crc32c_three_stream_set_enabled(enabled);
            REQUIRE(crc32c(bytes.data(), bytes.size()) == expected);
        }
    }
}
