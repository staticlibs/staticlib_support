/*
 * Copyright 2019, alex at staticlibs.net
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
 * File:   windows_test.cpp
 * Author: alex
 *
 * Created on April 4, 2019, 9:57 PM
 */

#include "staticlib/config.hpp"
#ifdef STATICLIB_WINDOWS

#include "staticlib/support/windows.hpp"

#include <iostream>

#include "staticlib/config/assert.hpp"

void test_pid() {
    auto pid = ::GetCurrentProcessId();
    slassert(pid > 0);
}

int main() {
    try {
        test_pid();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}

#else // !STATICLIB_WINDOWS

int main() {
    return 0;
}

#endif // STATICLIB_WINDOWS
