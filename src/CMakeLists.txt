# 5/26/2023

# include the subdirectories

# ???
cmake_minimum_required(VERSION 3.0)
project(MyProject)

# Include something -5/30/2023
# include_directories({CMAKE_CURRENT_SOURCE_DIR})
set(SRC_DIR src)
# Include subdirectories
#add_subdirectory({SRC_DIRECTORY}/data)
#add_subdirectory(game)
#add_subdirectory(math)
#add_subdirectory(render)

# INCLUDE subdirectories
include(${SRC_DIR}/data/CMakeLists.txt)
include(${SRC_DIR}/game/CMakeLists.txt)
include(${SRC_DIR}/math/CMakeLists.txt)
include(${SRC_DIR}/render/CMakeLists.txt)

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
