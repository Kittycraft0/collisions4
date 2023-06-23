cmake_minimum_required(VERSION 3.0.0)
project(MyProject)
# Set the output directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
# Add the main.cpp file to the project
add_executable(test1 main.cpp)
add_library(invsqrt ${CMAKE_CURRENT_SOURCE_DIR}/../../src/math/invsqrt.cpp)
target_link_libraries(test1 PUBLIC invsqrt)