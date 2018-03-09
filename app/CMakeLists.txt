# Sets the minimum version of CMake required to build your native library.
# This ensures that a certain set of CMake features is available to
# your build.

cmake_minimum_required(VERSION 3.4.1)

# configure import libs
set(distribution_DIR ${CMAKE_SOURCE_DIR}/src/main/cpp)

# build application's shared lib
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

# Specifies a library name, specifies whether the library is STATIC or
# SHARED, and provides relative paths to the source code. You can
# define multiple libraries by adding multiple add.library() commands,
# and CMake builds them for you. When you build your app, Gradle
# automatically packages shared libraries with your APK.

add_library( # Specifies the name of the library.
             phone_util

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             src/main/cpp/phone_util.cpp)
target_include_directories(phone_util PRIVATE
                            ${distribution_DIR}/pcre/include)
# Searches for a specified prebuilt library and stores the path as a
# variable. Because system libraries are included in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.
find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

add_library( pcre2
             SHARED
             IMPORTED )
set_target_properties( # Specifies the target library.
                       pcre2

                       # Specifies the parameter you want to define.
                       PROPERTIES IMPORTED_LOCATION

                       # Provides the path to the library you want to import.
                       ${distribution_DIR}/pcre/lib/${ANDROID_ABI}/libpcre2.so )
add_library( pcrecpp
             SHARED
             IMPORTED )
set_target_properties( # Specifies the target library.
                       pcrecpp

                       # Specifies the parameter you want to define.
                       PROPERTIES IMPORTED_LOCATION

                       # Provides the path to the library you want to import.
                       ${distribution_DIR}/pcre/lib/${ANDROID_ABI}/libpcrecpp.so )

target_link_libraries( phone_util pcre2 pcrecpp ${log-lib} )