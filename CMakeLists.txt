cmake_policy(SET CMP0135 NEW)
cmake_minimum_required(VERSION 3.20)
project(fastlob LANGUAGES CXX)

set(CMAKE_CXX STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(FASTLOB_SANITIZE "Enable ASan + UBSan" OFF)
option(FASTLOB_BUILD_TESTS "Build tests" ON)

add_library(fastlob_flags INTERFACE)
target_compile_options(fastlob_flags INTERFACE -Wall -Wextra -Wpedantic -Wconversion -Wshadow)
if (FASTLOB_SANITIZE)
    target_compile_options(fastlob_flags INTERFACE -fsanitize=address,undefined -fno-omit-frame-pointer)
    target_link_options(fastlob_flags INTERFACE -fsanitize=address,undefined)
endif()

add_library(fastlob src/fix_parser.cpp)
target_include_directories(fastlob PUBLIC include)
target_link_libraries(fastlob PUBLIC fastlob_flags)

if (FASTLOB_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()