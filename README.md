Staticlibs Support headers library
==================================

This project is a part of [Staticlibs](http://staticlibs.net/).

This project contains a number of helper templates.

This library is header-only and depends on [staticlib_config](https://github.com/staticlibs/staticlib_config).

Link to the [API documentation](http://staticlibs.github.io/staticlib_support/docs/html/namespacestaticlib_1_1support.html).

Features
--------

Library include:

    #include "staticlib/support.hpp"

#### to_string template ####

Implements `to_string` template that calls `std::to_string` on all supported platforms except Android, 
where `std::to_string` is missed for some versions of NDK. `std::stringstream` implementation
is used for Android.

#### defer template ####

Implements a lambda function holder, that will execute specified lambda on destruction. 
It is similar in nature with [defer in golang](https://tour.golang.org/flowcontrol/12) and
with [finally in GSL.util](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#gslutil-utilities).

#### basic exception ####

Exception class that extends `std::exception` and implements constructor that takes `std::string`
and `what` method that returns that string. All module-specific exception classed in Staticlibs 
extends `sl::support::exception`.

#### optional template ####

Basic implementation of `optional` template [from C++17](http://en.cppreference.com/w/cpp/utility/optional).

#### observer_ptr template ####

Basic implementation of non-owning pointer template.

License information
-------------------

This project is released under the [Apache License 2.0](http://www.apache.org/licenses/LICENSE-2.0).

Changelog
---------

**2017-04-08**

 * version 1.0.0
 * templates moved here from [staticlib_config](https://github.com/staticlibs/staticlib_config)
