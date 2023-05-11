/**
 *    Copyright (C) 2018-present MongoDB, Inc.
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the Server Side Public License, version 1,
 *    as published by MongoDB, Inc.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    Server Side Public License for more details.
 *
 *    You should have received a copy of the Server Side Public License
 *    along with this program. If not, see
 *    <http://www.mongodb.com/licensing/server-side-public-license>.
 *
 *    As a special exception, the copyright holders give permission to link the
 *    code of portions of this program with the OpenSSL library under certain
 *    conditions as described in each individual source file and distribute
 *    linked combinations including the program with the OpenSSL library. You
 *    must comply with the Server Side Public License in all respects for
 *    all of the code used other than as permitted herein. If you modify file(s)
 *    with this exception, you may extend this exception to your version of the
 *    file(s), but you are not obligated to do so. If you do not wish to do so,
 *    delete this exception statement from your version. If you delete this
 *    exception statement from all source files in the program, then also delete
 *    it in the license file.
 */

#include <vector>

#include "mongo/base/string_data.h"

// This file is expanded by a Scons generator as a detail of version_impl.cpp.
// Access this information via the VersionInfoInterface singleton.

namespace mongo::version {

constexpr auto kVersion = "5.0.7"_sd;
constexpr int kMajorVersion = 5;
constexpr int kMinorVersion = 0;
constexpr int kPatchVersion = 7;
constexpr int kExtraVersion = 0;
constexpr auto kVersionExtraStr = ""_sd;
constexpr auto kGitVersion = "nogitversion"_sd;
constexpr auto kAllocator = "tcmalloc"_sd;
constexpr auto kJsEngine = "mozjs"_sd;

inline std::vector<StringData> modulesList() {
    return {

    };
}

inline std::vector<VersionInfoInterface::BuildInfoField> buildEnvironment() {
    return {
{R"(distmod)"_sd, R"()"_sd, true, true},
{R"(distarch)"_sd, R"(x86_64)"_sd, true, true},
{R"(cc)"_sd, R"(gcc: gcc (GCC) 8.2.0)"_sd, true, false},
{R"(ccflags)"_sd, R"(-Werror -include mongo/platform/basic.h -fasynchronous-unwind-tables -ggdb -Wall -Wsign-compare -Wno-unknown-pragmas -Winvalid-pch -fno-omit-frame-pointer -fno-strict-aliasing -O2 -march=sandybridge -mtune=generic -mprefer-vector-width=128 -Wno-unused-local-typedefs -Wno-unused-function -Wno-deprecated-declarations -Wno-unused-const-variable -Wno-unused-but-set-variable -Wno-missing-braces -fstack-protector-strong -Wa,--nocompress-debug-sections -fno-builtin-memcmp)"_sd, true, false},
{R"(cxx)"_sd, R"(g++: g++ (GCC) 8.2.0)"_sd, true, false},
{R"(cxxflags)"_sd, R"(-Woverloaded-virtual -Wno-maybe-uninitialized -fsized-deallocation -std=c++17)"_sd, true, false},
{R"(linkflags)"_sd, R"(-Wl,--fatal-warnings -pthread -Wl,-z,now -fuse-ld=gold -fstack-protector-strong -Wl,--no-threads -Wl,--build-id -Wl,--hash-style=gnu -Wl,-z,noexecstack -Wl,--warn-execstack -Wl,-z,relro -Wl,--compress-debug-sections=none -Wl,-z,origin -Wl,--enable-new-dtags)"_sd, true, false},
{R"(target_arch)"_sd, R"(x86_64)"_sd, true, true},
{R"(target_os)"_sd, R"(linux)"_sd, true, false},
{R"(cppdefines)"_sd, R"(SAFEINT_USE_INTRINSICS 0 PCRE_STATIC NDEBUG _XOPEN_SOURCE 700 _GNU_SOURCE _FORTIFY_SOURCE 2 BOOST_THREAD_VERSION 5 BOOST_THREAD_USES_DATETIME BOOST_SYSTEM_NO_DEPRECATED BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS BOOST_ENABLE_ASSERT_DEBUG_HANDLER BOOST_LOG_NO_SHORTHAND_NAMES BOOST_LOG_USE_NATIVE_SYSLOG BOOST_LOG_WITHOUT_THREAD_ATTR ABSL_FORCE_ALIGNED_ACCESS)"_sd, true, false}
    };
}

}  // namespace mongo::version
