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
 * File:   observer_ptr.hpp
 * Author: alex
 *
 * Created on February 4, 2017, 9:01 PM
 */

#ifndef STATICLIB_SUPPORT_OBSERVER_PTR_HPP
#define	STATICLIB_SUPPORT_OBSERVER_PTR_HPP

#include "staticlib/support/exception.hpp"

namespace staticlib {
namespace support {

/**
 * Observer-specific exception
 */
class bad_observed_pointer_access_exception : public exception {
public:

    /**
     * Default constructor
     */
    bad_observed_pointer_access_exception() :
    exception("Invalid attempt to access empty observed pointer") { }
};


/**
 * Non-owning pointer
 */
template<typename T>
class observer_ptr {
    /**
     * Target pointer
     */
    T* target = nullptr;
    
public:
    /**
     * Constructs empty instance
     */
    observer_ptr() { }
    
    /**
     * Constructor
     * 
     * @param target pointer to store in this instance
     */
    explicit observer_ptr(T* target) :
    target(target) { }

    /**
     * Constructor
     * 
     * @param target reference to store in this instance
     */
    explicit observer_ptr(T& target) :
    target(std::addressof(target)) { }

    /**
     * Copy constructor
     * 
     * @param other other instance
     */
    observer_ptr(const observer_ptr& other) :
    target(other.target) { }

    /**
     * Copy assignment operator
     * 
     * @param other other instance
     * @return  this instance
     */
    observer_ptr& operator=(const observer_ptr& other) {
        target = other.target;
        return *this;
    };

    /**
     * Overloaded `bool` operator
     * 
     * @return true if this instance stores value, false otherwise
     */
    explicit operator bool() const {
        return has_value();
    }

    /**
     * Check whether this instance stores value
     * 
     * @return true if this instance stores value, false otherwise
     */
    bool has_value() const {
        return nullptr != target;
    }

    /**
     * Returns reference to stored object
     * 
     * @return reference to stored object
     * @throws bad_observed_pointer_access_exception if this instance is empty
     */
    T& operator*() const {
        if (has_value()) {
            return *target;
        } else {
            throw bad_observed_pointer_access_exception();
        }
    }

    /**
     * Returns stored pointer
     * 
     * @return stored pointer
     * @throws bad_observed_pointer_access_exception if this instance is empty
     */
    T* operator->() const {
        if (has_value()) {
            return target;
        } else {
            throw bad_observed_pointer_access_exception();
        }
    }

    /**
     * Returns stored pointer
     * 
     * @return stored pointer
     * @throws bad_observed_pointer_access_exception if this instance is empty
     */
    T* get() const {
        if (has_value()) {
            return target;
        } else {
            throw bad_observed_pointer_access_exception();
        }
    }
    
    /**
     * Make this instance empty
     */
    void reset() {
        target = nullptr;
    }
};


/**
 * Helper function, constructs new observer instance
 * 
 * @param target target pointer
 * @return observer instance
 */
template<typename T>
observer_ptr<T> make_observer_ptr(T* target) {
    return observer_ptr<T>(target);
}

/**
 * Helper function, constructs new observer instance
 * 
 * @param target target reference
 * @return observer instance
 */
template<typename T>
observer_ptr<T> make_observer_ptr(T& target) {
    return observer_ptr<T>(target);
}

} // namespace
} 

#endif	/* STATICLIB_SUPPORT_OBSERVER_PTR_HPP */

