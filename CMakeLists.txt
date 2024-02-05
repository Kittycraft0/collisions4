# 6/22/2023 This works!
# 6/22/2023 Use compiler GCC 7.3.0 x86_64-w64-mingw32


# 6/22/2023 Set project variables - change these!

# 6/22/2023 Name of the executable & project directory name
# 1/23/2024 - https://code.visualstudio.com/docs/cpp/config-mingw
# 1/23/2024 - do >CMAKE:Select a kit and select GCC - 13.2.0
# 1/23/2024 - https://www.sfml-dev.org/download/sfml/2.5.1/
# 2/1/2024 - https://github.com/brechtsanders/winlibs_mingw/releases/download
# /12.2.0-16.0.0-10.0.0-msvcrt-r5
# /winlibs-x86_64-posix-seh-gcc-12.2.0-mingw-w64msvcrt-10.0.0-r5.7z
# the above is the compiler download link for windows 11 spread over 3 lines
# select GCC 7.3.0 x86_64-w64-mingw32
# or 12.2.0 x86_64-w64-mingw32 (mingw64)
# whichever one shows up
# and it works!!!!!!!!
# 2/5/2024 - remember to also delete build/CMakeCache.txt because it holds the project
# directory in there and it's probably not the same
set(EXE_NAME test4)
# 6/22/2023 Compiler used, or something - either LINUX or GCC
set(COMPILER GCC)


# 9/5/2023
#IF(what STREQUAL what)
#message(WHAT)
#endif()
#message(OH)


# 6/22/2023 Set project root
set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})



# 6/22/2023 Initialize project details
cmake_minimum_required(VERSION 3.5.0)
project(cppProject VERSION 0.1.0)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# 6/22/2023 Enable test help
#include(CTest)
#enable_testing()

# 6/22/2023 Add the main executable
add_executable(${EXE_NAME} projects/${EXE_NAME}/main.cpp)
#add_library(invsqrt ../src/math/invsqrt.cpp)
#target_link_libraries(${EXE_NAME} PUBLIC invsqrt)

# 6/22/2023 Link the SFML .hpp's to the executable's "include path"
target_include_directories(${EXE_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/GCC-SFML-2.5.1/include)

# 6/22/2023 Link the SFML .dll's to the executable's "include path"
target_link_directories(${EXE_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/GCC-SFML-2.5.1/bin)

# 9/05/2023 Check "compiler"
IF(${COMPILER} STREQUAL GCC)
# 6/22/2023 Set the SFML .dll file names
set(SFML_DLLS
    sfml-system-2
    sfml-window-2
    sfml-graphics-2
    sfml-audio-2
    sfml-network-2
)
ELSEIF(${COMPILER} STREQUAL LINUX)
#set(SFML_DIR include/LINUX-SFML-2.5.1/lib)
set(SFML_DLLS
    sfml-system
    sfml-window
    sfml-graphics
    sfml-audio
    sfml-network
)
ENDIF()

# 6/22/2023 Define the included libraries variable
set(INCLUDED_LIBRARIES "")

# 6/22/2023 Add the project subdirectory, reading the root CMakeListst.txt of the file adding dependencies to the INCLUDED_LIBRARIES variable defined above
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/projects/${EXE_NAME})
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src)

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