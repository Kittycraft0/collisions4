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

# ChatGPT 5/9/2023
# Generate a list of all source files in the folder
#file(GLOB SOURCES "*.cpp")

# chatgpt 5/9/2023
#add_library(math src/math/invsqrt.cpp)
#add_library(math src/math/*) does not work


# Add a target to compile all source files
#add_executable(MyExecutable ${SOURCES})

#sadly all by hand??? wait what??? oh maybe not??? nice. what????????
#add_executable(invsqrttest invsqrttest.cpp)
#add_executable(invsqrttest invsqrttest.cpp src/math/invsqrt.cpp)
add_executable(invsqrttest invsqrttest.cpp)

add_library(invsqrt src/math/invsqrt.cpp)
target_link_libraries(invsqrttest invsqrt)

#add_executable(collisions3 "src/math/invsqrt.cpp")
#add_executable(gravity1 main.cpp)

#chatgpt 5/9/2023
#add_executable(collisions3 main.cpp)



# Link against the SFML libraries
#target_link_libraries(collisions3 sfml-graphics sfml-audio)

target_link_libraries(invsqrttest sfml-graphics sfml-audio)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)