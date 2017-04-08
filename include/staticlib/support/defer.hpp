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
 * File:   defer.hpp
 * Author: alex
 *
 * Created on January 27, 2017, 12:07 PM
 */

#ifndef STATICLIB_SUPPORT_DEFER_HPP
#define	STATICLIB_SUPPORT_DEFER_HPP

#include <utility>

#include "staticlib/config.hpp"

namespace staticlib {
namespace support {

namespace detail_defer {

// http://stackoverflow.com/a/17356259/314015
/**
 * Holder object for a lambda, that will
 * be executed on destruction. Lambda must be "noexcept".
 */
template<typename T>
class defer_guard {
    T func;
    bool moved_out = false;
    
public:
    /**
     * Constructor
     * 
     * @param func lambda function to execute on destruction
     */
    explicit defer_guard(T func) :
    func(std::move(func)) { }

    /**
     * Deleted copy constructor
     */
    defer_guard(const defer_guard&) = delete;
    
    /**
     * Deleted copy-assignment operator
     */
    defer_guard& operator=(const defer_guard&) = delete;
    
    /**
     * Move constructor
     * 
     * @param other other instance
     */
    defer_guard(defer_guard&& other) STATICLIB_NOEXCEPT :
    func(std::move(other.func)) {
        other.moved_out = true;
    }

    /**
     * Deleted move-assignment operator
     */
    defer_guard& operator=(defer_guard&&) = delete;

    /**
     * Destructor, will execute lambda function
     */
    ~defer_guard() STATICLIB_NOEXCEPT {
#ifdef STATICLIB_NOEXCEPT_SUPPORTED
        static_assert(noexcept(func()),
                "Please check that the defer block cannot throw, "
                "and mark the lambda as 'noexcept'.");
#endif
        if (!moved_out) {
            func();
        }
    }
};

} // namespace

/**
 * Creates a "guard object", that will execute
 * specified lambda function on destruction.
 * Similar in nature with GSL's `finally`.
 * 
 * @param func lambda function to execute on destruction,
 *        must be "noexcept"
 * @return guard object
 */
template<typename T>
detail_defer::defer_guard<T> defer(T func) {
    return detail_defer::defer_guard<T>(std::move(func));
}

} // namespace
}

#endif	/* STATICLIB_SUPPORT_DEFER_HPP */

