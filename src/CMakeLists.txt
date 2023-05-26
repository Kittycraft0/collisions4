# 5/26/2023

# include the subdirectories

# ???
cmake_minimum_required(VERSION 3.0)
project(MyProject)

# Include subdirectories
add_subdirectory(src)

target_link_libraries(collisions3 sfml-graphics sfml-audio)
