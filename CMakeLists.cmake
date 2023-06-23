cmake_minimum_required(VERSION 3.0.0)
# Include the renamed CMakeListsRoot.txt file
# Set the project to use by commenting every line except the one to use

# 6/21/2023
# Options: helloworld, invSqrtTest, test1, test2, test3, test4
set(EXE_NAME test1)
set(AWESOME_PROJECT_EXECUTABLE ${EXE_NAME})

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


# 6/19/2023 either LINUX, GCC
# 6/20/2023 8:36 PM CST:
set(THE_OS GCC)






# 6/19/2023 copied over from collisions3 folder to collisions4 folder in case something goes horribly wrong...
# 6/22/2023 might as well do it again since it's so different!!!!!!!! although, it's all hooked up to github now, 
# so there's now not really much to worry about






# 5/26/2023
# The stuff that makes it work
# Probably won't need modifying again
# 6/22/2023 oh you were so wrong...


project(cppProject VERSION 0.1.0)

# 6/22/2023 Includes things to supposedly help with testing
include(CTest)
# 6/22/2023 Enables said testing I guess
enable_testing()

# 6/22/2023 - Define the main executable
#if(EXISTS ${PROJECT_ROOT}/projects/${EXE_NAME}/main.cpp)
#    message("!!! FOUND MAIN FILE: [PROJECT_ROOT]/projects/${EXE_NAME}/main.cpp")
#    add_executable(${AWESOME_PROJECT_EXECUTABLE} ${PROJECT_ROOT}/projects/${EXE_NAME}/main.cpp)
#elseif(EXISTS ${PROJECT_ROOT}/projects/${EXE_NAME}/${EXE_NAME}.cpp)
#    message("!!! FOUND MAIN FILE: [PROJECT_ROOT]/projects/${EXE_NAME}/${EXE_NAME}.cpp")
#    add_executable(${AWESOME_PROJECT_EXECUTABLE} ${PROJECT_ROOT}/projects/${EXE_NAME}/${EXE_NAME}.cpp)
#else()
#    message(FATAL_ERROR "!!! MAIN FILE NOT FOUND: not found in ${EXE_NAME} directory!")
#endif()

# 6/22/2023 - Remember to have awesome_project_executable defined first!!!!!!!!
#add_executable(${AWESOME_PROJECT_EXECUTABLE} ${PROJECT_ROOT}/projects/${EXE_NAME}/main.cpp)


include(projects/${EXE_NAME}/CMakeLists.txt)

# 5/26/2023
# 6/19/2023
# Set the SFML_LIBS environment variable and maybe try to actually link SFML to the executable and maybe hopefully libraries as well
if(${THE_OS} STREQUAL "GCC")
    message("!!! Using GCC SFML fetching")
    # Add the SFML include directories
    target_include_directories(${AWESOME_PROJECT_EXECUTABLE} PUBLIC ${PROJECT_ROOT}/include/${THE_OS}-SFML-2.5.1/include)
    
    # Link the SFML library binaries for use
    target_link_directories(${AWESOME_PROJECT_EXECUTABLE} PUBLIC ${PROJECT_ROOT}/include/${THE_OS}-SFML-2.5.1/bin)

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
    message("!!! Using LINUX SFML fetching")
    # 6/19/2023 set sfml directory environment variable
    set(THE_SFML_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
    set(THE_SFML_LIBRARY_DIR ${THE_SFML_INCLUDE_DIR}/SFML-2.5.1/lib)
    #add_subdirectory(include/SFML-2.5.1)
    include_directories(${THE_SFML_INCLUDE_DIR})
    #include_directories(${THE_SFML_LIBRARY_DIR})

    # Find the SFML package


    # I just want to code and not have to deal with CMakeLists.txt files...
    # Eh, they seem to be working now though, so it's not all that bad anymore.
    # 6/22/2023 nevermind you dumb CMake files requiring like over 20 hours of work...

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

# Get the project files
# Remember: only allow ONE!!!
#include(projects/helloworld/CMakeLists.txt)
#include(projects/invSqrtTest/CMakeLists.txt)
#include(projects/test1/CMakeLists.txt)
#include(projects/test2/CMakeLists.txt)
#include(projects/test3/CMakeLists.txt)
#include(projects/test4/CMakeLists.txt)
#add_subdirectory(projects/test3)
# 6/22/2023
#include(projects/${EXE_NAME}/CMakeLists.txt)
#add_subdirectory(${PROJECT_ROOT}/src)

#message("Files location: " ${CMAKE_CURRENT_SOURCE_DIR}/include/${THE_OS}SFML-2.5.1/lib)

# 6/19/2023 - updated
# !!! 6/22/2023 Link libraries to the main executable
# However, the SFML library things are supposedly pre-compiled (only on GCC, but not on LINUX), while my own library files are not.
# Is this what is causing all of my issues here!? Nope!?
target_link_libraries(${AWESOME_PROJECT_EXECUTABLE} PUBLIC 
    # !!! Include the DLL files
    ${SFML_LIBS}
    # !!! Include the src files
    ${INCLUDED_LIBRARIES}
)
#message("Files location: " ${THE_SFML_LIBRARY_DIR})
#message("Inclusions: " ${SFML_LIBS} ${INCLUDED_DIRECTORIES})

# 5/14/2023
# Setting the executable location
set_target_properties(${AWESOME_PROJECT_EXECUTABLE} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
# 6/20/2023
message("!!! Compiled files will be saved in " ${CMAKE_CURRENT_SOURCE_DIR}/bin)








# 5/10/2023 explanation:
# set the variables (first parameters)
# to the corresponding environment variables (second parameters)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# 5/10/2023 explanation:
# pack everything up i guess
include(CPack)