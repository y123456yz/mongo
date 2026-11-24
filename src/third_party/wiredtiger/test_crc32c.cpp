// Copyright (c) MongoDB, Inc.
// SPDX-License-Identifier: SSPL-1.0

#include "mongo/unittest/unittest.h"

#include <array>
#include <atomic>
#include <cstddef>
#include <cstdint>
#include <thread>
#include <vector>

#include <wiredtiger.h>

namespace mongo {
namespace {

class ThreeStreamGuard {
public:
    explicit ThreeStreamGuard(bool enabled)
        : _previous(wiredtiger_crc32c_three_stream_enabled()) {
        wiredtiger_crc32c_three_stream_set_enabled(enabled);
    }
    ~ThreeStreamGuard() {
        wiredtiger_crc32c_three_stream_set_enabled(_previous);
    }

private:
    int _previous;
};

uint32_t referenceCRC(uint32_t seed, const uint8_t* data, size_t size) {
    uint32_t crc = ~seed;
    for (size_t i = 0; i < size; ++i) {
        crc ^= data[i];
        for (int bit = 0; bit < 8; ++bit) {
            crc = (crc >> 1) ^ ((crc & 1) ? 0x82f63b78u : 0u);
        }
    }
    return ~crc;
}

std::vector<uint8_t> makeBytes(size_t size) {
    std::vector<uint8_t> bytes(size);
    uint64_t state = 99;
    for (auto& byte : bytes) {
        state = state * 6364136223846793005ULL + 1442695040888963407ULL;
        byte = static_cast<uint8_t>(state >> 56);
    }
    return bytes;
}

TEST(WiredTigerCRC32C, MatchesReferenceForBothSettingsAndCachedFunctions) {
    const auto crc = wiredtiger_crc32c_func();
    const auto seededCRC = wiredtiger_crc32c_with_seed_func();
    constexpr std::array<size_t, 33> sizes{0, 1, 2, 7, 8, 9, 15, 16, 17, 511, 512, 1023,
                                         1024, 3071, 3072, 3073, 3080, 4095, 4096, 4097,
                                         6143, 6144, 6145, 6152, 9215, 9216, 9217, 12287,
                                         12288, 12289, 65536, 65537, 100003};
    for (size_t size : sizes) {
        const auto bytes = makeBytes(size + 64);
        for (size_t offset = 0; offset < 16; ++offset) {
            const auto* data = bytes.data() + offset;
            const auto expected = referenceCRC(0, data, size);
            const auto expectedSeeded = referenceCRC(0xdeadbeef, data, size);
            for (bool enabled : {true, false, true}) {
                ThreeStreamGuard guard(enabled);
                ASSERT_EQ(wiredtiger_crc32c_three_stream_enabled(), enabled);
                ASSERT_EQ(crc(data, size), expected) << "size=" << size << " offset=" << offset;
                ASSERT_EQ(seededCRC(0, data, size), expected);
                ASSERT_EQ(seededCRC(0xdeadbeef, data, size), expectedSeeded);
                ASSERT_EQ(wiredtiger_crc32c_func(), crc);
                ASSERT_EQ(wiredtiger_crc32c_with_seed_func(), seededCRC);
            }
        }
    }
}

TEST(WiredTigerCRC32C, ZeroLengthAndKnownVector) {
    for (bool enabled : {false, true}) {
        ThreeStreamGuard guard(enabled);
        const auto crc = wiredtiger_crc32c_func();
        const auto seededCRC = wiredtiger_crc32c_with_seed_func();
        ASSERT_EQ(crc(nullptr, 0), 0u);
        ASSERT_EQ(seededCRC(0xdeadbeef, nullptr, 0), 0xdeadbeefu);
        ASSERT_EQ(crc("123456789", 9), 0xe3069283u);
    }
}

TEST(WiredTigerCRC32C, ChainingAcrossSwitchAndBlockBoundaries) {
    const auto bytes = makeBytes(40000);
    const auto expected = referenceCRC(0, bytes.data(), bytes.size());
    const auto seededCRC = wiredtiger_crc32c_with_seed_func();
    for (size_t split : {size_t{0}, size_t{1}, size_t{7}, size_t{8}, size_t{3071}, size_t{3072},
                         size_t{3073}, size_t{6144}, size_t{12288}, size_t{20000}, size_t{39999},
                         bytes.size()}) {
        for (bool enabled : {false, true}) {
            ThreeStreamGuard guard(enabled);
            const auto first = seededCRC(0, bytes.data(), split);
            wiredtiger_crc32c_three_stream_set_enabled(!enabled);
            ASSERT_EQ(seededCRC(first, bytes.data() + split, bytes.size() - split), expected);
        }
    }
}

TEST(WiredTigerCRC32C, UniformBuffers) {
    for (uint8_t fill : {uint8_t{0}, uint8_t{0xff}, uint8_t{0x5a}}) {
        const std::vector<uint8_t> bytes(20000, fill);
        const auto expected = referenceCRC(0, bytes.data(), bytes.size());
        for (bool enabled : {false, true}) {
            ThreeStreamGuard guard(enabled);
            ASSERT_EQ(wiredtiger_crc32c_func()(bytes.data(), bytes.size()), expected);
        }
    }
}

TEST(WiredTigerCRC32C, ConcurrentSwitchKeepsChecksumValuesStable) {
    ThreeStreamGuard guard(true);
    const auto bytes = makeBytes(65537);
    const auto expected = referenceCRC(0xdeadbeef, bytes.data(), bytes.size());
    const auto seededCRC = wiredtiger_crc32c_with_seed_func();
    std::atomic<bool> valid{true};
    std::atomic<bool> start{false};
    std::vector<std::thread> readers;
    for (int i = 0; i < 4; ++i) {
        readers.emplace_back([&] {
            while (!start.load()) {
                std::this_thread::yield();
            }
            for (int j = 0; j < 1000; ++j) {
                if (seededCRC(0xdeadbeef, bytes.data(), bytes.size()) != expected) {
                    valid.store(false);
                }
            }
        });
    }
    start.store(true);
    for (int i = 0; i < 10000; ++i) {
        wiredtiger_crc32c_three_stream_set_enabled(i & 1);
    }
    for (auto& reader : readers) {
        reader.join();
    }
    ASSERT_TRUE(valid.load());
}

}  // namespace
}  // namespace mongo
