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
 * File:   tribool_test.cpp
 * Author: alex
 *
 * Created on May 11, 2017, 11:27 PM
 */

#include "staticlib/support/tribool.hpp"

#include <iostream>
#include <stdexcept>

#include "staticlib/config/assert.hpp"

void test_tribool() {
    sl::support::tribool b{true};
    slassert(b);
    b = false;
    slassert(!b);
    b = sl::support::indeterminate;
    sl::support::tribool b2(b);
    (void) b2;
}

int main() {
    try {
        test_tribool();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}
