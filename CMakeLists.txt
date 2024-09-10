# Top-level CMakeLists.txt

cmake_minimum_required(VERSION 3.10)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Enable C++20 standard
set(CMAKE_CXX_STANDARD 20)

# Try to find Google Test on the system
find_package(GTest QUIET)

# If Google Test is not found, use FetchContent to download and build it
if(NOT GTest_FOUND)
    message(STATUS "Google Test not found. Fetching Google Test from repository...")
    
    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.11.0
    )
    
    # Set to build Google Test without installing
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    # Set variables for linking GTest::GTest and GTest::Main
    set(GTest_LIBRARIES GTest::gtest GTest::gtest_main)
else()
    message(STATUS "Google Test found on system.")
    
    # If found, set the libraries to link
    set(GTest_LIBRARIES GTest::GTest GTest::Main)
endif()

enable_testing()

# Add subdirectories for each problem
add_subdirectory(Q1)
add_subdirectory(Q2)

# Define custom target for each problem (e.g., 'make 1' for Q1)
add_custom_target(1 DEPENDS q1_executable)
add_custom_target(2 DEPENDS q2_executable)