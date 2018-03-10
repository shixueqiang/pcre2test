# configure import libs
set(distribution_DIR ${CMAKE_SOURCE_DIR}/pcre)

# Specifies a library name, specifies whether the library is STATIC or
# SHARED, and provides relative paths to the source code. You can
# define multiple libraries by adding multiple add.library() commands,
# and CMake builds them for you. When you build your app, Gradle
# automatically packages shared libraries with your APK.

add_library( # Specifies the name of the library.
             pcre2cpp

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             ${distribution_DIR}/pcrecpp/pcrecpp.cc
             ${distribution_DIR}/pcrecpp/pcre_scanner.cc
             ${distribution_DIR}/pcrecpp/pcre_stringpiece.cc)
target_include_directories(pcre2cpp PRIVATE
                            ${distribution_DIR}/pcrecpp/include)
add_library(pcre2 STATIC IMPORTED)
set_target_properties(pcre2 PROPERTIES IMPORTED_LOCATION
    ${distribution_DIR}/lib/${ANDROID_ABI}/libpcre2.a)
target_link_libraries( pcre2cpp pcre2 )