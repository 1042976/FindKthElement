cmake_minimum_required(VERSION 3.23)
project(FindKthLargest CXX C)

include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(CMAKE_CXX_STANDARD 14 CMAKE_C_STANDARD 99)
SET(CMAKE_BUILD_TYPE Debug)

#add_library(mainlib SHARED main.c)
add_executable(FindKthLargest test.cpp main.c)

target_link_libraries(FindKthLargest gtest_main)

add_test(NAME FindKthLargest_test COMMAND FindKthLargest)
