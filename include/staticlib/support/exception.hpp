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
 * File:   exception.hpp
 * Author: alex
 *
 * Created on January 2, 2015, 11:49 AM
 */

#ifndef STATICLIB_SUPPORT_STATICLIB_EXCEPTION_HPP
#define	STATICLIB_SUPPORT_STATICLIB_EXCEPTION_HPP

#include <exception>
#include <string>

#include "staticlib/config.hpp"

namespace staticlib {
namespace support {

/**
 * Base exception class for various exceptions in staticlib modules
 */
class exception : public std::exception {
protected:
    /**
     * Error message
     */
    std::string message;

public:
    /**
     * Default constructor
     */
    exception() = default;
    
    /**
     * Constructor with message
     * 
     * @param msg error message
     */
    exception(const std::string& message) : 
    message(message.data(), message.length()) { }
    
    /**
     * Returns error message
     * 
     * @return error message
     */
    virtual const char* what() const STATICLIB_NOEXCEPT {
        return message.c_str();
    }
};

} //namespace
}

#endif	/* STATICLIB_SUPPORT_STATICLIB_EXCEPTION_HPP */

