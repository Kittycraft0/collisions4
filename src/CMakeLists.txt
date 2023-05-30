# 5/26/2023

# include the subdirectories

# ???
cmake_minimum_required(VERSION 3.0)
project(MyProject)

# Include subdirectories
add_subdirectory(data)
add_subdirectory(game)
add_subdirectory(math)
add_subdirectory(render)

# To include this one: -5/30/2023
#add_subdirectory(src)
#add_subdirectory(../../src)

target_link_libraries(collisions3 sfml-graphics sfml-audio)
