#cmake_minimum_required(VERSION 3.0.0)
#project(thefirsttry VERSION 0.1.0)

#include(CTest)
#enable_testing()

#add_executable(thefirsttry main.cpp)

#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)


cmake_minimum_required(VERSION 3.0.0)
project(collisions3 VERSION 0.1.0)

include(CTest)
enable_testing()

# Find the SFML package
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)


# 5/9/2023
# The below like sets a variable of "main" to the 
# executable (.cpp without .h) for use in
# the cmake file here
# this (the first parameter thing) is 
# also probably the name of the created .exe file thing
add_executable(collisions3 main.cpp)

# 5/9/2023
# The below like sets the variable thing of "invsqrt" to the 
# library (.cpp with .h) for use in the cmake file here
add_library(invsqrt src/math/invsqrt.cpp)

# 5/9/2023
# The below connects the executable (first) 
# to the library (second and any more following)
target_link_libraries(collisions3 invsqrt)



# Link against the SFML libraries
#target_link_libraries(collisions3 sfml-graphics sfml-audio)

target_link_libraries(collisions3 sfml-graphics sfml-audio)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)