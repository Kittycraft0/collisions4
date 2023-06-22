# 5/26/2023

# include the subdirectories

# ???
cmake_minimum_required(VERSION 3.0)
project(MyProject)

# Include something -5/30/2023
# include_directories({CMAKE_CURRENT_SOURCE_DIR})

#if(${THE_OS} STREQUAL "LINUX")
#    message("Using LINUX src directories")
#    set(SRC_DIR src)
#else()
#    message("Using WINDOWS src directories")
#    set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})
#endif()
# 6/21/2023 why does this one work and not the other!? ok whatver i have my own thing then
#if(NOT ${THE_OS} STREQUAL "LINUX")
#    message("Using WINDOWS src directories")
#    set(SRC_DIR src)
#else()
#    message("Using LINUX src directories")
#    set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
#endif()

set(SRC_DIR ${PROJECT_ROOT}/src)
message("!!0 SRC directory: " ${SRC_DIR})

# Include subdirectories
add_subdirectory(${SRC_DIR}/data)
add_subdirectory(${SRC_DIR}/game)
add_subdirectory(${SRC_DIR}/math)
add_subdirectory(${SRC_DIR}/render)
# INCLUDE subdirectories
#include(${SRC_DIR}/game/CMakeLists.txt)
#include(${SRC_DIR}/data/CMakeLists.txt)
#include(${SRC_DIR}/render/CMakeLists.txt)
#include(${SRC_DIR}/math/CMakeLists.txt)
# Add them to an src libary -5/31/2023
#add_library(src INTERFACE)

# Link the libaries
#target_link_libraries(src INTERACE maath render game data)
#target_link_libraries(src INTERACE maath)
#add_library(invsqrt ../src/math/invsqrt.cpp)
#target_link_libraries(${AWESOME_PROJECT_EXECUTABLE} PUBLIC invsqrt)


# what
#add_library(invsqrt math/invsqrt.cpp)
#target_link_libraries(${AWESOME_PROJECT_EXECUTABLE} PUBLIC invsqrt)


# To include this one: -5/30/2023
#add_subdirectory(src)
#add_subdirectory(../../src)

#target_link_libraries(collisions3 sfml-graphics sfml-audio)
