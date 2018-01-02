/*
 * Copyright 2016, alex at staticlibs.net
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* 
 * File:   int_utils_test.cpp
 * Author: alex
 *
 * Created on June 13, 2016, 10:41 PM
 */

#include "staticlib/support/is_integer.hpp"

#include <iostream>

#include "staticlib/config/assert.hpp"

void test_is_int32() {
    slassert(sl::support::is_int32(-1));
    slassert(sl::support::is_int32(0));
    slassert(sl::support::is_int32(1));
    slassert(!sl::support::is_int32(std::numeric_limits<uint32_t>::max()));
    slassert(!sl::support::is_int32(static_cast<int64_t> (std::numeric_limits<uint32_t>::max())));
    slassert(sl::support::is_int32(std::numeric_limits<int32_t>::min()));
    slassert(!sl::support::is_int32(static_cast<int64_t> (std::numeric_limits<int32_t>::min()) - 1));
}

void test_is_uint32() {
    slassert(sl::support::is_uint32(0));
    slassert(sl::support::is_uint32(1));
    slassert(sl::support::is_uint32(static_cast<int64_t>(std::numeric_limits<uint32_t>::max())));
    slassert(sl::support::is_uint32(static_cast<uint64_t>(std::numeric_limits<uint32_t>::max())));
    slassert(!sl::support::is_uint32(static_cast<uint64_t>(std::numeric_limits<uint32_t>::max()) + 1));
}

void test_is_uint32_positive() {
    slassert(!sl::support::is_uint32_positive(0));
    slassert(sl::support::is_uint32_positive(1));
    slassert(sl::support::is_uint32_positive(static_cast<int64_t> (std::numeric_limits<uint32_t>::max())));
    slassert(sl::support::is_uint32_positive(static_cast<uint64_t> (std::numeric_limits<uint32_t>::max())));
    slassert(!sl::support::is_uint32_positive(static_cast<uint64_t> (std::numeric_limits<uint32_t>::max()) + 1));
}

void test_is_int16() {
    slassert(sl::support::is_int16(-1));
    slassert(sl::support::is_int16(0));
    slassert(sl::support::is_int16(1));
    slassert(!sl::support::is_int16(std::numeric_limits<uint16_t>::max()));
    slassert(!sl::support::is_int16(static_cast<int32_t> (std::numeric_limits<uint16_t>::max())));
    slassert(sl::support::is_int16(std::numeric_limits<int16_t>::min()));
    slassert(!sl::support::is_int16(static_cast<int32_t> (std::numeric_limits<int16_t>::min()) - 1));
}

void test_is_uint16() {
    slassert(sl::support::is_uint16(0));
    slassert(sl::support::is_uint16(1));
    slassert(sl::support::is_uint16(static_cast<int32_t> (std::numeric_limits<uint16_t>::max())));
    slassert(sl::support::is_uint16(static_cast<uint32_t> (std::numeric_limits<uint16_t>::max())));
    slassert(!sl::support::is_uint16(static_cast<uint32_t> (std::numeric_limits<uint16_t>::max()) + 1));
}

void test_is_uint16_positive() {
    slassert(!sl::support::is_uint16_positive(0));
    slassert(sl::support::is_uint16_positive(1));
    slassert(sl::support::is_uint16_positive(static_cast<int32_t> (std::numeric_limits<uint16_t>::max())));
    slassert(sl::support::is_uint16_positive(static_cast<uint32_t> (std::numeric_limits<uint16_t>::max())));
    slassert(!sl::support::is_uint16_positive(static_cast<uint32_t> (std::numeric_limits<uint16_t>::max()) + 1));
}

void test_is_int64() {
    slassert(sl::support::is_int64(-1));
    slassert(sl::support::is_int64(0));
    slassert(sl::support::is_int64(1));
    slassert(!sl::support::is_int64(std::numeric_limits<uint64_t>::max()));
    slassert(sl::support::is_int64(std::numeric_limits<int64_t>::min()));
    slassert(sl::support::is_int64(std::numeric_limits<int64_t>::max()));
}

void test_is_uint64() {
    slassert(sl::support::is_uint64(0));
    slassert(sl::support::is_uint64(1));
    slassert(!sl::support::is_uint64(-1));
    slassert(sl::support::is_uint64(std::numeric_limits<uint64_t>::min()));
    slassert(sl::support::is_uint64(std::numeric_limits<uint64_t>::max()));
}

void test_is_uint64_positive() {
    slassert(!sl::support::is_uint64_positive(0));
    slassert(sl::support::is_uint64_positive(1));
    slassert(!sl::support::is_uint64_positive(-1));
    slassert(!sl::support::is_uint64_positive(std::numeric_limits<uint64_t>::min()));
    slassert(sl::support::is_uint64_positive(std::numeric_limits<uint64_t>::max()));
}

void test_is_streamsize() {
    slassert(sl::support::is_streamsize(-1));
    slassert(sl::support::is_streamsize(0));
    slassert(sl::support::is_streamsize(1));
    // false on 32-bit
    // slassert(!sl::support::is_streamsize(std::numeric_limits<size_t>::max()));
    slassert(sl::support::is_streamsize(std::numeric_limits<std::streamsize>::min()));
}

void test_is_sizet() {
    slassert(sl::support::is_sizet(0));
    slassert(sl::support::is_sizet(1));
    slassert(!sl::support::is_sizet(-1));
    slassert(sl::support::is_sizet(std::numeric_limits<size_t>::max()));
    slassert(sl::support::is_sizet(std::numeric_limits<size_t>::min()));
}

void test_is_sizet_positive() {
    slassert(!sl::support::is_sizet_positive(0));
    slassert(sl::support::is_sizet_positive(1));
    slassert(!sl::support::is_sizet_positive(-1));
    slassert(sl::support::is_sizet_positive(std::numeric_limits<size_t>::max()));
    slassert(!sl::support::is_sizet_positive(std::numeric_limits<size_t>::min()));
}

int main() {
    try {
        test_is_int32();
        test_is_uint32();
        test_is_uint32_positive();
        test_is_int16();
        test_is_uint16();
        test_is_uint16_positive();
        test_is_int64();
        test_is_uint64();
        test_is_uint64_positive();
        test_is_streamsize();
        test_is_sizet();
        test_is_sizet_positive();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}
