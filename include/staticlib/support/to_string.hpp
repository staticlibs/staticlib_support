/*
 * Copyright 2015, alex at staticlibs.net
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
 * File:   to_string.hpp
 * Author: alex
 *
 * Created on November 21, 2015, 7:02 PM
 */

#ifndef STATICLIB_SUPPORT_TO_STRING_HPP
#define STATICLIB_SUPPORT_TO_STRING_HPP

#include <sstream>
#include <string>

#include "staticlib/config.hpp"

namespace staticlib {
namespace support {

/**
 * Generic `to_string` implementation
 * 
 * @param obj object to stringify
 * @return string representation of specified value
 */
template<typename T>
std::string to_string_any(const T& obj) {
    std::stringstream ss{};
    ss << obj;
    return ss.str();
}

/**
 * Generic `to_string` implementation, already exists as `std::to_string`
 * in most C++11 compilers except GCC 4.8 on Android
 * 
 * @param obj object to stringify
 * @return string representation of specified value
 */
template<typename T>
std::string to_string(const T& obj) {
#ifndef STATICLIB_ANDROID
    return std::to_string(obj);
#else
    return to_string_any(obj);
#endif // STATICLIB_ANDROID
}

/**
 * Converts bool value to "true" or "false" string.
 * 
 * @param val boolean value
 * @return "true" or "false" string
 */
inline std::string to_string_bool(bool val) {
    return val ? "true" : "false";
}

} // namespace
}

#endif /* STATICLIB_SUPPORT_TO_STRING_HPP */

