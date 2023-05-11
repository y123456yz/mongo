
#include <atomic>
#include <mutex>
#include <cstddef>

static_assert(alignof(std::max_align_t) < 64, "whatever");

alignas(64) std::mutex aligned_mutex;
alignas(64) std::atomic<int> aligned_atomic;

struct alignas(64) aligned_struct_mutex {
    std::mutex m;
};

struct alignas(64) aligned_struct_atomic {
    std::atomic<int> m;
};

struct holds_aligned_mutexes {
    alignas(64) std::mutex m1;
    alignas(64) std::mutex m2;
} hm;

struct holds_aligned_atomics {
    alignas(64) std::atomic<int> a1;
    alignas(64) std::atomic<int> a2;
} ha;
