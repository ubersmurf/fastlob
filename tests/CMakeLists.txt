include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip)
FetchContent_MakeAvailable(googletest)

add_executable(fastlob_tests fix_parser_test.cpp)
target_link_libraries(fastlob_tests PRIVATE fastlob GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(fastlob_tests)