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
 * File:   int_utils.hpp
 * Author: alex
 *
 * Created on June 13, 2016, 10:39 PM
 */

#ifndef STATICLIB_SUPPORT_IS_INTEGER_HPP
#define	STATICLIB_SUPPORT_IS_INTEGER_HPP

#include <cstdint>
#include <ios>
#include <limits>
#include <type_traits>

namespace staticlib {
namespace support {

/**
 * Checks that specified unsigned integer lies between `<int32_t>::min()` and `<int32_t>::max()`
 * 
 * @param val integer
 * @return true if check successful, false otherwise
 */
template <typename T>
typename std::enable_if<std::is_unsigned<T>::value, bool>::type is_int32(T val) {
    return val <= static_cast<uint32_t>(std::numeric_limits<int32_t>::max());
}

/**
 * Checks that specified signed integer lies between `<int32_t>::min()` and `<int32_t>::max()`
 * 
 * @param val integer
 * @return true if check successful, false otherwise
 */
template <typename T>
typename std::enable_if<!std::is_unsigned<T>::value, bool>::type is_int32(T val) {
    return val >= std::numeric_limits<int32_t>::min() && val <= std::numeric_limits<int32_t>::max();
}

/**
 * Checks that specified unsigned integer lies between `0` (inclusive) and `<uint32_t>::max()`
 * 
 * @param val integer
 * @return true if check successful, false otherwise
 */
template <typename T>
typename std::enable_if<std::is_unsigned<T>::value, bool>::type is_uint32(T val) {
    return val <= std::numeric_limits<uint32_t>::max();
}

/**
 * Checks that specified signed integer lies between `0` (inclusive) and `<uint32_t>::max()`
 * 
 * @param val integer
 * @return true if check successful, false otherwise
 */
template <typename T>
typename std::enable_if<!std::is_unsigned<T>::value, bool>::type is_uint32(T val) {
    return val >= 0 && val <= static_cast<int64_t> (std::numeric_limits<uint32_t>::max());
}

/**
 * Checks that specified integer lies between `0` (exclusive) and `<uint32_t>::max()`
 * 
 * @param val integer
 * @return true if check successful, false otherwise
 */
template <typename T>
bool is_uint32_positive(T val) {
    return 0 != val && is_uint32(val);
}

/**
 * Checks that specified unsigned integer lies between `<int16_t>::min()` and `<int16_t>::max()`
 * 
 * @param val integer
 * @return true if check successful, false otherwise
 */
template <typename T>
typename std::enable_if<std::is_unsigned<T>::value, bool>::type is_int16(T val) {
    return val <= static_cast<uint16_t> (std::numeric_limits<int16_t>::max());
}

/**
 * Checks that specified signed integer lies between `<int16_t>::min()` and `<int16_t>::max()`
 * 
 * @param val integer
 * @return true if check successful, false otherwise
 */
template <typename T>
typename std::enable_if<!std::is_unsigned<T>::value, bool>::type is_int16(T val) {
    return val >= std::numeric_limits<int16_t>::min() && val <= std::numeric_limits<int16_t>::max();
}

/**
 * Checks that specified unsigned integer lies between `0` (inclusive) and `<uint16_t>::max()`
 * 
 * @param val integer
 * @return true if check successful, false otherwise
 */
template <typename T>
typename std::enable_if<std::is_unsigned<T>::value, bool>::type is_uint16(T val) {
    return val <= std::numeric_limits<uint16_t>::max();
}

/**
 * Checks that specified signed integer lies between `0` (inclusive) and `<uint16_t>::max()`
 * 
 * @param val integer
 * @return true if check successful, false otherwise
 */
template <typename T>
typename std::enable_if<!std::is_unsigned<T>::value, bool>::type is_uint16(T val) {
    return val >= 0 && val <= static_cast<int32_t> (std::numeric_limits<uint16_t>::max());
}

/**
 * Checks that specified integer lies between `0` (exclusive) and `<uint16_t>::max()`
 * 
 * @param val integer
 * @return true if check successful, false otherwise
 */
template <typename T>
bool is_uint16_positive(T val) {
    return 0 != val && is_uint16(val);
}

/**
 * Checks that specified unsigned integer lies between `<int64_t>::min()` and `<int64_t>::max()`
 * 
 * @param val integer
 * @return true if check successful, false otherwise
 */
template <typename T>
typename std::enable_if<std::is_unsigned<T>::value, bool>::type is_int64(T val) {
    return val <= static_cast<uint64_t> (std::numeric_limits<int64_t>::max());
}

/**
 * Checks that specified signed integer lies between `<int64_t>::min()` and `<int64_t>::max()`
 * 
 * @param val integer
 * @return true if check successful, false otherwise
 */
template <typename T>
typename std::enable_if<!std::is_unsigned<T>::value, bool>::type is_int64(T val) {
    return val >= std::numeric_limits<int64_t>::min() && val <= std::numeric_limits<int64_t>::max();
}

/**
 * Checks that specified unsigned integer lies between `0` (inclusive) and `<uint64_t>::max()`
 * 
 * @param val integer
 * @return true if check successful, false otherwise
 */
template <typename T>
typename std::enable_if<std::is_unsigned<T>::value, bool>::type is_uint64(T val) {
    return val <= std::numeric_limits<uint64_t>::max();
}

/**
 * Checks that specified signed integer lies between `0` (inclusive) and `<uint64_t>::max()`
 * 
 * @param val integer
 * @return true if check successful, false otherwise
 */
template <typename T>
typename std::enable_if<!std::is_unsigned<T>::value, bool>::type is_uint64(T val) {
    return val >= 0 && val <= std::numeric_limits<int64_t>::max();
}

/**
 * Checks that specified integer lies between `0` (exclusive) and `<uint64_t>::max()`
 * 
 * @param val integer
 * @return true if check successful, false otherwise
 */
template <typename T>
bool is_uint64_positive(T val) {
    return 0 != val && is_uint64(val);
}

/**
 * Checks that specified unsigned integer lies between `<streamsize>::min()` and `<streamsize>::max()`
 * 
 * @param val integer
 * @return true if check successful, false otherwise
 */
template <typename T>
typename std::enable_if<std::is_unsigned<T>::value, bool>::type is_streamsize(T val) {
    return val <= static_cast<std::size_t> (std::numeric_limits<std::streamsize>::max());
}

/**
 * Checks that specified signed integer lies between `<streamsize>::min()` and `<streamsize>::max()`
 * 
 * @param val integer
 * @return true if check successful, false otherwise
 */
template <typename T>
typename std::enable_if<!std::is_unsigned<T>::value, bool>::type is_streamsize(T val) {
    return val >= std::numeric_limits<std::streamsize>::min() && val <= std::numeric_limits<std::streamsize>::max();
}

/**
 * Checks that specified unsigned integer lies between `0` (inclusive) and `<size_t>::max()`
 * 
 * @param val integer
 * @return true if check successful, false otherwise
 */
template <typename T>
typename std::enable_if<std::is_unsigned<T>::value, bool>::type is_sizet(T val) {
    return val <= std::numeric_limits<size_t>::max();
}

/**
 * Checks that specified signed integer lies between `0` (inclusive) and `<size_t>::max()`
 * 
 * @param val integer
 * @return true if check successful, false otherwise
 */
template <typename T>
typename std::enable_if<!std::is_unsigned<T>::value, bool>::type is_sizet(T val) {
    if (val < 0) {
        return false;
    }
    return static_cast<uint64_t>(val) <= std::numeric_limits<size_t>::max();
}

/**
 * Checks that specified integer lies between `0` (exclusive) and `<uint32_t>::max()`
 * 
 * @param val integer
 * @return true if check successful, false otherwise
 */
template <typename T>
bool is_sizet_positive(T val) {
    return 0 != val && is_sizet(val);
}

} // namespace
}

#endif	/* STATICLIB_SUPPORT_IS_INTEGER_HPP */

