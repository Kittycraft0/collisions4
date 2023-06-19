# Include the renamed CMakeListsRoot.txt file
# Set the project to use by commenting every line except the one to use

# Remember: only allow ONE!!!
#include(projects/test1/CMakeLists.txt)
#include(projects/invSqrtTest/CMakeLists.txt)
#include(projects/test2/CMakeLists.txt)
include(projects/test4/CMakeLists.txt)
#add_subdirectory(projects/test3)

# 5/31/2023
# According to ChatGPT, the include() basically acts as inputting the file
# directly into the location here. Using add_subdirectory() instead might work.
# Or maybe turning all add_subdirectory()s into include()s might work.








# 6/19/2023 copied over from collisions3 folder to collisions4 folder in case something goes horribly wrong...








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

# ChatGPT:
# CMakeLists.txt in the root directory

# 6/19/2023 set sfml directory environment variable
set(THE_SFML_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(THE_SFML_LIBRARY_DIR ${THE_SFML_INCLUDE_DIR}/SFML-2.5.1/lib)
#add_subdirectory(include/SFML-2.5.1)
include_directories(${THE_SFML_INCLUDE_DIR})
include_directories(${THE_SFML_LIBRARY_DIR})

# Find the SFML package
# Commented out because this requires outside-the-project-folder dependancies
#find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)



# 6/19/2023 - Failed attempt at copy/paste from the render MakeLists.txt file
#set(THE_SFML_LIB_DIR ${THE_SFML_INCLUDE_DIR}/SFML-2.5.1/include/SFML)
#message(STATUS ${SRC_DIR} AAAAA)
#message(STATUS ${RENDER_DIR})

# Add the source files for the data library
#set(SOURCES_THE_SFML
    # Add more source files if needed
#    ${THE_SFML_LIB_DIR}/initWindow.cpp
#    ${THE_SFML_LIB_DIR}/render2d.cpp
#)
#message(STATUS ${SOURCES_RENDER})
# Create the render library
#add_library(thesfml ${SOURCES_THE_SFML})

# Set the include directories for the render library
#target_include_directories(thesfml PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Link the library
#target_link_libraries(${AWESOME_PROJECT_EXECUTABLE} PUBLIC
#thesfml
    # Add any dependencies if needed
#)




# I just want to code and not have to deal with CMakeLists.txt files...
# Eh, they seem to be working now though, so it's not all that bad anymore.

# Link against the SFML libraries
#target_link_libraries(collisions3 sfml-graphics sfml-audio)
# 5/10/2023 explanation:
# connect executable (first parameter, collisions3) 
# with all following libraries (all parameters 
# following the first, the names following)
#target_link_libraries(${AWESOME_PROJECT_EXECUTABLE} PUBLIC sfml-graphics sfml-audio)
# 6/19/2023 - updated
target_link_libraries(${AWESOME_PROJECT_EXECUTABLE} PUBLIC 
    ${THE_SFML_LIBRARY_DIR}/libsfmlgraphics.so
    ${THE_SFML_LIBRARY_DIR}/libsfmlaudio.so
    #${THE_SFML_INCLUDE_DIR}/libsfml-graphics.a
)
message("Files location: " ${THE_SFML_LIBRARY_DIR})


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









# 5/10/2023 explanatin:
# set the variables (first parameters)
# to the corresponding environment variables (second parameters)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# 5/10/2023 explanation:
# pack everything up i guess
include(CPack)