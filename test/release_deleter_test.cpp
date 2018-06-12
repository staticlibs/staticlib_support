/*
 * Copyright 2018, alex at staticlibs.net
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
 * File:   release_deleter_test.cpp
 * Author: alex
 *
 * Created on June 12, 2018, 11:20 AM
 */
#include "staticlib/support/release_deleter.hpp"

#include <iostream>

#include "staticlib/config/assert.hpp"

void test_release() {
    // create
    auto orig = std::unique_ptr<int>(new int(42));
    slassert(nullptr != orig.get());
    slassert(42 == *orig);
    // share
    auto shared = sl::support::make_shared_with_release_deleter(orig.release());
    slassert(nullptr == orig.get());
    slassert(nullptr != shared.get());
    slassert(42 == *shared);
    // copy
    auto copy = shared;
    // release
    auto dest = sl::support::make_unique_from_shared_with_release_deleter(shared);
    slassert(nullptr != dest.get());
    slassert(nullptr == sl::support::make_unique_from_shared_with_release_deleter(copy).get());
    slassert(nullptr == sl::support::make_unique_from_shared_with_release_deleter(shared).get());
    // copy after release
    auto copy_after = copy;
    slassert(42 == *dest);
    shared.reset();
    slassert(nullptr == shared.get());
    slassert(42 == *dest);
    copy.reset();
    slassert(nullptr == copy.get());
    slassert(42 == *dest);
    copy_after.reset();
    slassert(nullptr == copy.get());
    slassert(42 == *dest);
}

int main() {
    try {
        test_release();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}
