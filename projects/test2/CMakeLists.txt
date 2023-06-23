# 5/30/2023
# set the project name
#set(AWESOME_PROJECT_EXECUTABLE test2)
# Add the project executable
#add_executable(${AWESOME_PROJECT_EXECUTABLE} projects/test2/main.cpp)

# add the src libary
#add_library(src ../src)

#target_link_libraries(${AWESOME_PROJECT_EXECUTABLE} src)

# Revised 6/22/2023
#add_subdirectory(src)
#message("!!2 ROOT_DIR: " ${ROOT_DIR})
#add_subdirectory(${ROOT_DIR})
#add_subdirectory(${ROOT_DIR}/src)
#include_directories({CMAKE_CURRENT_SOURCE_DIR}/src) #6/22/2023 what!? why!??
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
#include_directories(${ROOT_DIR}/src)