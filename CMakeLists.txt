# 6/22/2023 This works!
# 6/22/2023 Use compiler GCC 7.3.0 x86_64-w64-mingw32


# 6/22/2023 Set project variables - change these!

# 6/22/2023 Name of the executable & project directory name
set(EXE_NAME test1)
# 6/22/2023 Compiler used, or something - either LINUX or GCC
set(COMPILER GCC)






# 6/22/2023 Set project root
set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})



# 6/22/2023 Initialize project details
cmake_minimum_required(VERSION 3.0.0)
project(cppProject VERSION 0.1.0)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# 6/22/2023 Enable test help
include(CTest)
enable_testing()

# 6/22/2023 Add the main executable
add_executable(${EXE_NAME} projects/test1/main.cpp)
#add_library(invsqrt ../src/math/invsqrt.cpp)
#target_link_libraries(${EXE_NAME} PUBLIC invsqrt)

# 6/22/2023 Link the SFML .hpp'sto the executable's "include path"
target_include_directories(${EXE_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/GCC-SFML-2.5.1/include)

# 6/22/2023 Link the SFML .dll's to the executable's "include path"
target_link_directories(${EXE_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/GCC-SFML-2.5.1/bin)

# 6/22/2023 Set the SFML .dll file names
set(SFML_DLLS
    sfml-system-2
    sfml-window-2
    sfml-graphics-2
    sfml-audio-2
    sfml-network-2
)

# 6/22/2023 Define the included libraries variable
set(INCLUDED_LIBRARIES "")

# 6/22/2023 Add the project subdirectory, adding dependencies to the INCLUDED_LIBRARIES variable defined above
add_subdirectory(projects/${EXE_NAME})

# 6/19/2023 - updated
target_link_libraries(${EXE_NAME} PUBLIC 
    # 6/22/2023 Link SFML .dll's to the executable's code
    ${SFML_DLLS}
    # 6/22/2023 Link the SRC libraries to the executable's code
    ${INCLUDED_LIBRARIES}
)

message("!!! INCLUDED_LIBRARIES: ${INCLUDED_LIBRARIES}")
message("!!! SFML_DLLs: ${SFML_DLLS}")
message("!!! testwhat: " ${testwhat})