# 5/30/2023
# set the project name
#set(AWESOME_PROJECT_EXECUTABLE test3)
# Add the project executable
#add_executable(${AWESOME_PROJECT_EXECUTABLE} main.cpp)
#add_executable(${AWESOME_PROJECT_EXECUTABLE} projects/test3/main.cpp)

# add the src libary
#add_library(src ../src)

#target_link_libraries(${AWESOME_PROJECT_EXECUTABLE} src)

# what? the below works here!? oh what
#add_library(invsqrt ../src/math/invsqrt.cpp)
#target_link_libraries(${AWESOME_PROJECT_EXECUTABLE} PUBLIC invsqrt)

#add_subdirectory(src)
include(src/CMakeLists.txt)
#add_subdirectory({CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories({CMAKE_CURRENT_SOURCE_DIR}/src)