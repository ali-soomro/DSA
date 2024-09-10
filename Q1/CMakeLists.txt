# # CMakeLists.txt for Q1

# # Project name
# project(Q1)

# # Create an executable for the question without the solution
# add_executable(q1_executable q1.cpp)

# CMakeLists.txt for Q1

# Project name
project(Q1)

# Create an executable for the question
add_executable(q1_executable q1.cpp)

# Link the Google Test libraries (which are fetched by the top-level CMakeLists.txt)
target_link_libraries(q1_executable GTest::gtest GTest::gtest_main)

# Register the test with CMake's testing framework
add_test(NAME Q1Test COMMAND q1_executable)