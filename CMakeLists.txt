cmake_minimum_required(VERSION 3.0.0)
# Include the renamed CMakeListsRoot.txt file
# Set the project to use by commenting every line except the one to use

# 6/21/2023
# Options: helloworld, invSqrtTest, test1, test2, test3, test4
set(EXE_NAME test1)

# 6/19/2023 why
set(INCLUDED_LIBRARIES "")
# 6/19/2023 WHY? NO.
#if(COMMAND cmake_policy)
#    cmake_policy(SET CMP0003 NEW)
#endif(COMMAND cmake_policy)

# 6/21/2023 set the project root directory
set(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
message("!!! Project root: " ${PROJECT_ROOT})


# 5/31/2023
# According to ChatGPT, the include() basically acts as inputting the file
# directly into the location here. Using add_subdirectory() instead might work.
# Or maybe turning all add_subdirectory()s into include()s might work.


# 6/19/2023 either LINUX, GCC, LIB, vc15-32, vc15-64, gcc-7.3.0-mingw-32, or gcc-7.3.0-mingw-64
# 6/20/2023 8:36 PM CST:
set(THE_OS GCC)






# 6/19/2023 copied over from collisions3 folder to collisions4 folder in case something goes horribly wrong...

#






# 5/26/2023
# The stuff that makes it work
# Probably won't need modifying again



# Copy/paste

project(cppProject VERSION 0.1.0)

# ???
include(CTest)
# ???
enable_testing()


# Get the project files
# Remember: only allow ONE!!!
#include(projects/helloworld/CMakeLists.txt)
#include(projects/invSqrtTest/CMakeLists.txt)
#include(projects/test1/CMakeLists.txt)
#include(projects/test2/CMakeLists.txt)
#include(projects/test3/CMakeLists.txt)
#include(projects/test4/CMakeLists.txt)
#add_subdirectory(projects/test3)
include(projects/${EXE_NAME}/CMakeLists.txt)


# 5/26/2023
# 6/19/2023
if(${THE_OS} STREQUAL "GCC")
    message("!!! Using GCC SFML fetching")
    # 6/19/2023 set sfml directory environment variable
    #set(THE_SFML_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
    # 6/20/2023 REMEMBER THE "-" AAAAAAAAAAAAAAAAAAAAAA
    #set(THE_SFML_LIBRARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/${THE_OS}-SFML-2.5.1)

    #include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
    #target_include_directories(${AWESOME_PROJECT_EXECUTABLE} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/${THE_OS}-SFML-2.5.1/include)
    #link_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/${THE_OS}-SFML-2.5.1/bin)

    # Add the SFML include directories
    target_include_directories(${AWESOME_PROJECT_EXECUTABLE} PUBLIC ${PROJECT_ROOT}/include/${THE_OS}-SFML-2.5.1/include)
    #include_directories(${AWESOME_PROJECT_EXECUTABLE} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/${THE_OS}-SFML-2.5.1/include)

    # Add the SFML library directories
    target_link_directories(${AWESOME_PROJECT_EXECUTABLE} PUBLIC ${PROJECT_ROOT}/include/${THE_OS}-SFML-2.5.1/bin)
    #link_directories(${AWESOME_PROJECT_EXECUTABLE} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/${THE_OS}-SFML-2.5.1/bin)

    # Link SFML libraries to the executable
    #target_link_libraries(${AWESOME_PROJECT_EXECUTABLE} PUBLIC
    set(SFML_LIBS ${SFML_LIBS}
        sfml-system-2
        sfml-window-2
        sfml-graphics-2
        sfml-audio-2
        sfml-network-2
    )

elseif(${THE_OS} STREQUAL "LINUX")
#if(${THE_OS} STREQUAL "LINUX")
    message("!!! Using LINUX SFML fetching")
    ############
    # 6/19/2023 set sfml directory environment variable
    set(THE_SFML_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
    set(THE_SFML_LIBRARY_DIR ${THE_SFML_INCLUDE_DIR}/SFML-2.5.1/lib)
    #add_subdirectory(include/SFML-2.5.1)
    include_directories(${THE_SFML_INCLUDE_DIR})
    #include_directories(${THE_SFML_LIBRARY_DIR})

    # Find the SFML package


    # I just want to code and not have to deal with CMakeLists.txt files...
    # Eh, they seem to be working now though, so it's not all that bad anymore.

    # Link against the SFML libraries
    #target_link_libraries(collisions3 sfml-graphics sfml-audio)
    # 5/10/2023 explanation:
    # connect executable (first parameter, collisions3) 
    # with all following libraries (all parameters 
    # following the first, the names following)
    #target_link_libraries(${AWESOME_PROJECT_EXECUTABLE} PUBLIC sfml-graphics sfml-audio)

    # Replaced by - 6/19/2023

    # 6/19/2023 - updated
    target_link_libraries(${AWESOME_PROJECT_EXECUTABLE} PUBLIC 
        ${THE_SFML_LIBRARY_DIR}/libsfml-graphics.so
        ${THE_SFML_LIBRARY_DIR}/libsfml-audio.so
        ${THE_SFML_LIBRARY_DIR}/libsfml-network.so
        ${THE_SFML_LIBRARY_DIR}/libsfml-system.so
        ${THE_SFML_LIBRARY_DIR}/libsfml-window.so
        #${THE_SFML_INCLUDE_DIR}/libsfml-graphics.a
    )
    # Link SFML libraries to the executable
    set(SFML_LIBS ${SFML_LIBS}
        sfml-system
        sfml-window
        sfml-graphics
        sfml-audio
        sfml-network
    )
    message("!!! Files location: " ${THE_SFML_LIBRARY_DIR})
endif()


#message("Files location: " ${CMAKE_CURRENT_SOURCE_DIR}/include/${THE_OS}SFML-2.5.1/lib)

# 6/19/2023 - updated
target_link_libraries(${AWESOME_PROJECT_EXECUTABLE} PUBLIC 
    ${SFML_LIBS}
    ${INCLUDED_LIBRARIES}
)
#message("Files location: " ${THE_SFML_LIBRARY_DIR})
#message("Inclusions: " ${SFML_LIBS} ${INCLUDED_DIRECTORIES})

# 5/14/2023
# Setting the executable location
# "bin" both stands for "binaries" and also seems like a 
# physical bin you chuck stuff 
# into when you are done with it. Cool!
#set_target_properties(collisions3 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ~/bin)
# 5/24/2023
# fixed the error
#set_target_properties(collisions3 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
# YESS!!! IT WORKS!!!

set_target_properties(${AWESOME_PROJECT_EXECUTABLE} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
# 6/20/2023
message("!!! Compiled files will be saved in " ${CMAKE_CURRENT_SOURCE_DIR}/bin)








# 5/10/2023 explanatin:
# set the variables (first parameters)
# to the corresponding environment variables (second parameters)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# 5/10/2023 explanation:
# pack everything up i guess
include(CPack)