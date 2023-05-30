# 5/30/2023
# set the project name
set(AWESOME_PROJECT_EXECUTABLE test1)
# Add the project executable
add_executable(${AWESOME_PROJECT_EXECUTABLE} projects/test2/main.cpp)

# add the src libary
#add_library(src ../src)

#target_link_libraries(${AWESOME_PROJECT_EXECUTABLE} src)


add_subdirectory(src)
include_directories({CMAKE_CURRENT_SOURCE_DIR}/src)