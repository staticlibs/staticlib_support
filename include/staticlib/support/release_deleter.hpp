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
 * File:   release_deleter.hpp
 * Author: alex
 *
 * Created on June 12, 2018, 11:13 AM
 */

#ifndef STATICLIB_SUPPORT_RELEASE_DELETER_HPP
#define STATICLIB_SUPPORT_RELEASE_DELETER_HPP

#include <atomic>
#include <memory>

namespace staticlib {
namespace support {

/**
 * Deleter implementation for `std::shared_ptr` that allows to
 * release the owned object from `shared_ptr`
 */
template<typename T, typename Deleter = typename std::default_delete<T>>
class release_deleter : private Deleter {
    std::shared_ptr<std::atomic_flag> released;

public:

    /**
     * Constructor
     */
    release_deleter() :
    released(std::make_shared<std::atomic_flag>()) {
        released->clear();
    }

    /**
     * Copy constructor
     * 
     * @param other other instance
     */
    release_deleter(const release_deleter& other):
    Deleter(other),
    released(other.released) { }

    /**
     * Deleted copy-assignment operator
     * 
     * @param other other instance
     * @return this instance
     */
    release_deleter& operator=(const release_deleter& other) = delete;

    /**
     * Delete operator, is a no-op if this deleter was released before
     * 
     * @param ptr pointer to delete
     */
    void operator()(T* ptr) {
        if (!released->test_and_set(std::memory_order_acq_rel)) {
            Deleter::operator()(ptr);
        }
    }

    /**
     * Releases the owned object from the `shared_ptr`
     * 
     * @return true if object was successfully released, false otherwise
     */
    bool release() {
        return !released->test_and_set(std::memory_order_acq_rel);
    }
};

template<typename T>
std::shared_ptr<T> make_shared_with_release_deleter(T* ptr) {
    return std::shared_ptr<T>(ptr, release_deleter<T>());
}

template<typename T>
std::unique_ptr<T> make_unique_from_shared_with_release_deleter(std::shared_ptr<T> ptr) {
    release_deleter<T>* deleter = std::get_deleter<release_deleter<T>>(ptr);
    if (nullptr != deleter) {
        bool released = deleter->release();
        if (released) {
            return std::unique_ptr<T>(ptr.get());
        } else {
            return std::unique_ptr<T>();
        }
    } else {
        return std::unique_ptr<T>();
    }
}

} // namespace
}

#endif /* STATICLIB_SUPPORT_RELEASE_DELETER_HPP */

