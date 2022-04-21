cmake_minimum_required(VERSION 3.14)
project(RaytracingChallenge)

# minimum required for GoogleTest
set(CMAKE_CXX_STANDARD 11)

# might be used later
# set(RTC_SRCS src/*.cpp)

set(RTC_TEST_DIR test)

# CMake module
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/8ccdb9d56d07b9169ecd17f1164f251a637c250e.zip
)

FetchContent_MakeAvailable(googletest)

# enable testing in CMake
enable_testing()

# declare the binary that you want to test
add_executable(
    tuple_test
    test/tuple_test.cpp
)

target_include_directories(tuple_test PUBLIC include)

target_link_libraries(
    tuple_test
    gtest_main
    )

# include the GoogleTest CMake module
include(GoogleTest)
gtest_discover_tests(tuple_test)
