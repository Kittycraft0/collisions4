# 6/22/2023 stupid errors...
#cmake_minimum_required(VERSION 3.0.0)

#add_executable(test1 main.cpp)
#project(cppProject VERSION 0.1.0)
#include(CTest)
#enable_testing()


cmake_minimum_required(VERSION 3.0.0)
project(MyProject)

# Set the output directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# Add the main.cpp file to the project
add_executable(MyExecutable main.cpp)



#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)