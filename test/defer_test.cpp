/*
 * Copyright 2017, alex at staticlibs.net
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
 * File:   defer_test.cpp
 * Author: alex
 *
 * Created on January 27, 2017, 12:14 PM
 */

#include "staticlib/support/defer.hpp"

#include <iostream>

#include "staticlib/config/assert.hpp"

void test_defer() {
    int a = 0;
    {
        auto deferred = sl::support::defer([&a]() STATICLIB_NOEXCEPT {
            a += 1;
        });
        a += 1;
        slassert(1 == a);
    }
    slassert(2 == a);
}

int main() {
    try {
        test_defer();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}
