# CMakeLists.txt for Q2

# Project name
project(Q2)

# Create an executable for the question without the solution
add_executable(q2_executable q2.cpp)

# Link the Google Test libraries (which are fetched by the top-level CMakeLists.txt)
target_link_libraries(q2_executable GTest::gtest GTest::gtest_main)

# Register the test with CMake's testing framework
add_test(NAME Q2Test COMMAND q2_executable)