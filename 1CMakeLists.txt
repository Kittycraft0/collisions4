#cmake_minimum_required(VERSION 3.0.0)
#project(thefirsttry VERSION 0.1.0)

#include(CTest)
#enable_testing()

#add_executable(thefirsttry main.cpp)

#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)


cmake_minimum_required(VERSION 3.0.0)
project(thefirsttry VERSION 0.1.0)

include(CTest)
enable_testing()

# Find the SFML package
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(thefirsttry main.cpp)
#add_executable(gravity1 main.cpp)

# Link against the SFML libraries
target_link_libraries(thefirsttry sfml-graphics sfml-audio)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)