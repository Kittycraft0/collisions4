# Include the renamed CMakeListsRoot.txt file
# Set the project to use by commenting every line except the one to use

# 6/19/2023 why
set(INCLUDED_LIBRARIES "")
# 6/19/2023 WHY? NO.
#if(COMMAND cmake_policy)
#    cmake_policy(SET CMP0003 NEW)
#endif(COMMAND cmake_policy)

# Remember: only allow ONE!!!
include(projects/helloworld/CMakeLists.txt)
#include(projects/invSqrtTest/CMakeLists.txt)
#include(projects/test1/CMakeLists.txt)
#include(projects/test2/CMakeLists.txt)
#include(projects/test3/CMakeLists.txt)
#include(projects/test4/CMakeLists.txt)
#add_subdirectory(projects/test3)

# 5/31/2023
# According to ChatGPT, the include() basically acts as inputting the file
# directly into the location here. Using add_subdirectory() instead might work.
# Or maybe turning all add_subdirectory()s into include()s might work.


# 6/19/2023 either LINUX, GCC, LIB, vc15-32, vc15-64, gcc-7.3.0-mingw-32, or gcc-7.3.0-mingw-64
set(THE_OS gcc-7.3.0-mingw-32)






# 6/19/2023 copied over from collisions3 folder to collisions4 folder in case something goes horribly wrong...

#






# 5/26/2023
# The stuff that makes it work
# Probably won't need modifying again



# Copy/paste

cmake_minimum_required(VERSION 3.0.0)
project(cppProject VERSION 0.1.0)

# ???
include(CTest)
# ???
enable_testing()

# 5/26/2023
# 6/19/2023

# 6/19/2023 set sfml directory environment variable
set(THE_SFML_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
# 6/20/2023 REMEMBER THE "-" AAAAAAAAAAAAAAAAAAAAAA
set(THE_SFML_LIBRARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/${THE_OS}-SFML-2.5.1)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/${THE_OS}-SFML-2.5.1/include)
target_include_directories(${AWESOME_PROJECT_EXECUTABLE} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/${THE_OS}-SFML-2.5.1/include)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/${THE_OS}-SFML-2.5.1/bin)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

# 6/19/2023 - file structures with if statement things
if(${THE_OS} STREQUAL "LIB")
    message("running LIB")
    set(SFML_LIBS
        ${THE_SFML_LIBRARY_DIR}/bin/openal32.dll
        ${THE_SFML_LIBRARY_DIR}/bin/sfml-audio-2.dll
        ${THE_SFML_LIBRARY_DIR}/bin/sfml-graphics-2.dll
        ${THE_SFML_LIBRARY_DIR}/bin/sfml-network-2.dll
        ${THE_SFML_LIBRARY_DIR}/bin/sfml-system-2.dll
        ${THE_SFML_LIBRARY_DIR}/bin/sfml-window-2.dll
    )
elseif(${THE_OS} STREQUAL "LINUX")
    message("running LINUX")
    set(SFML_LIBS
        ${THE_SFML_LIBRARY_DIR}/lib/libsfml-graphics.so
        ${THE_SFML_LIBRARY_DIR}/lib/libsfml-audio.so
        ${THE_SFML_LIBRARY_DIR}/lib/libsfml-network.so
        ${THE_SFML_LIBRARY_DIR}/lib/libsfml-system.so
        ${THE_SFML_LIBRARY_DIR}/lib/libsfml-window.so
    )
elseif(${THE_OS} STREQUAL "GCC")
    message("running GCC")
    set(SFML_LIBS
        ${THE_SFML_LIBRARY_DIR}/bin/openal32.dll
        ${THE_SFML_LIBRARY_DIR}/bin/sfml-audio-2.dll
        ${THE_SFML_LIBRARY_DIR}/bin/sfml-graphics-2.dll
        ${THE_SFML_LIBRARY_DIR}/bin/sfml-network-2.dll
        ${THE_SFML_LIBRARY_DIR}/bin/sfml-system-2.dll
        ${THE_SFML_LIBRARY_DIR}/bin/sfml-window-2.dll
    )
elseif(${THE_OS} STREQUAL "vc15-32")
    message("running vc15-32")
    set(SFML_LIBS
        ${THE_SFML_LIBRARY_DIR}/bin/openal32.dll
        ${THE_SFML_LIBRARY_DIR}/bin/sfml-audio-2.dll
        ${THE_SFML_LIBRARY_DIR}/bin/sfml-graphics-2.dll
        ${THE_SFML_LIBRARY_DIR}/bin/sfml-network-2.dll
        ${THE_SFML_LIBRARY_DIR}/bin/sfml-system-2.dll
        ${THE_SFML_LIBRARY_DIR}/bin/sfml-window-2.dll
    )
elseif(${THE_OS} STREQUAL "vc15-64")
    message("running vc15-64")
    set(SFML_LIBS
        ${THE_SFML_LIBRARY_DIR}/bin/openal32.dll
        ${THE_SFML_LIBRARY_DIR}/bin/sfml-audio-2.dll
        ${THE_SFML_LIBRARY_DIR}/bin/sfml-graphics-2.dll
        ${THE_SFML_LIBRARY_DIR}/bin/sfml-network-2.dll
        ${THE_SFML_LIBRARY_DIR}/bin/sfml-system-2.dll
        ${THE_SFML_LIBRARY_DIR}/bin/sfml-window-2.dll
    )
elseif(${THE_OS} STREQUAL "gcc-7.3.0-mingw-32")
    message("running GCC")
    set(SFML_LIBS
        ${THE_SFML_LIBRARY_DIR}/bin/openal32.dll
        ${THE_SFML_LIBRARY_DIR}/bin/sfml-audio-2.dll
        ${THE_SFML_LIBRARY_DIR}/bin/sfml-graphics-2.dll
        ${THE_SFML_LIBRARY_DIR}/bin/sfml-network-2.dll
        ${THE_SFML_LIBRARY_DIR}/bin/sfml-system-2.dll
        ${THE_SFML_LIBRARY_DIR}/bin/sfml-window-2.dll
    )
elseif(${THE_OS} STREQUAL "gcc-7.3.0-mingw-64")
    message("running GCC")
    set(SFML_LIBS
        ${THE_SFML_LIBRARY_DIR}/bin/openal32.dll
        ${THE_SFML_LIBRARY_DIR}/bin/sfml-audio-2.dll
        ${THE_SFML_LIBRARY_DIR}/bin/sfml-graphics-2.dll
        ${THE_SFML_LIBRARY_DIR}/bin/sfml-network-2.dll
        ${THE_SFML_LIBRARY_DIR}/bin/sfml-system-2.dll
        ${THE_SFML_LIBRARY_DIR}/bin/sfml-window-2.dll
    )
endif()


# 6/19/2023 - updated
target_link_libraries(${AWESOME_PROJECT_EXECUTABLE} PUBLIC 
    ${SFML_LIBS}
    ${INCLUDED_LIBRARIES}
)


set_target_properties(${AWESOME_PROJECT_EXECUTABLE} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
# 6/20/2023
message("Compiled files will be saved in " ${CMAKE_CURRENT_SOURCE_DIR}/bin)








# 5/10/2023 explanatin:
# set the variables (first parameters)
# to the corresponding environment variables (second parameters)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# 5/10/2023 explanation:
# pack everything up i guess
include(CPack)