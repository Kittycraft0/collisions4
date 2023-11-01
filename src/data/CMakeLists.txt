# 5/14/2023
# CMakeLists.txt file for src/data
#cmake_minimum_required(VERSION 3.0.0)
#project(thefirsttry VERSION 0.1.0)

#include(CTest)
#enable_testing()

#add_executable(thefirsttry main.cpp)

#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)


#cmake_minimum_required(VERSION 3.0.0)
#project(collisions3 VERSION 0.1.0)

#include(CTest)
#enable_testing()

# Find the SFML package
#find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)


# 5/9/2023
# The below like sets a variable of "main" to the 
# executable (.cpp without .h) for use in
# the cmake file here
# this (the first parameter thing) is 
# also probably the name of the created .exe file thing
#add_executable(collisions3 main.cpp)

# 5/14/2023 set the sources


# 5/9/2023
# The below like sets the variable thing of "invsqrt" to the 
# library (.cpp with .h) for use in the cmake file here
#add_library(initData initData.cpp)
#add_library(modelData modeldata.cpp)
#add_library(modelnd modelnd.cpp)
#add_library(objectnd objectnd.cpp)
#add_library(settings settings.cpp)

# 5/30/2023
# chat gpt
# CMakeLists.txt file for src/data
#set(DATA_DIR ${SRC_DIR}/data)
# Add the source files for the data library
#set(SOURCES_DATA
#    #data.cpp
#    # Add more source files if needed
#    ${DATA_DIR}/initData.cpp
#    ${DATA_DIR}/modeldata.cpp
#    ${DATA_DIR}/modelnd.cpp
#    ${DATA_DIR}/objectnd.cpp
#    ${DATA_DIR}/settings.cpp
#)

# Create the data library
#add_library(daata ${SOURCES_DATA})

# Set the include directories for the data library
#target_include_directories(daata PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Below is link, above is include. Notice the diferences!

# Link any dependencies for the data library
#target_link_libraries(
#    daata
#    # Add any dependencies if needed
#)

# 5/30/2023
# !!! CMakeLists.txt file for src/data
set(DATA_DIR ${SRC_DIR}/data)
# !!! Add the source files for the data library
set(SOURCES_DATA
    #data.cpp
    # Add more source files if needed
    ${DATA_DIR}/initData.cpp
    ${DATA_DIR}/modeldata.cpp
    ${DATA_DIR}/modelnd.cpp
    ${DATA_DIR}/objectnd.cpp
    ${DATA_DIR}/settings.cpp
    ${DATA_DIR}/fonts.cpp
    ${DATA_DIR}/drawText.cpp
)

# !!! Create the data library
# "No SOURCES" - Why are you yelling at me!?
add_library(daata ${SOURCES_DATA})

# 6/22/2023 Link the SFML .hpp's to the library's "include path"
target_include_directories(daata PUBLIC ${ROOT_DIR}/include/GCC-SFML-2.5.1/include)

# 6/22/2023 Link the SFML .dll's to the library's "include path"
target_link_directories(daata PUBLIC ${ROOT_DIR}/include/GCC-SFML-2.5.1/bin)

message("!!D ROOT_DIR: " ${ROOT_DIR})

# !!! Set the include directories for the data library
#target_include_directories(daata PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
#target_include_directories(daata PUBLIC ${DATA_DIR})

# !!! Link any dependencies for the data library
target_link_libraries(daata
    # Add any dependencies if needed
    ${SFML_DLLS}
)

#target_link_libraries(${AWESOME_PROJECT_EXECUTABLE} PUBLIC
#    daata
#    # Add any dependencies if needed
#)

# !!! 6/19/2023 concatenate???
# 6/23/2023 Change the variable in the local scope
list(APPEND INCLUDED_LIBRARIES daata)
# 6/23/2023 Update the variable in the global scope by replacing it with the newer variant in the local scope
set(INCLUDED_LIBRARIES ${INCLUDED_LIBRARIES} PARENT_SCOPE)

# list(APPEND INCLUDED_LIBRARIES ${INCLUDED_LIBRARIES} daata)
message("!!D Data loaded!")

#add_library(data SHARED ${SOURCES})

#target_link_libraries(${AWESOME_PROJECT_EXECUTABLE} initData)
#target_link_libraries(${AWESOME_PROJECT_EXECUTABLE} modelData)
#target_link_libraries(${AWESOME_PROJECT_EXECUTABLE} modelnd)
#target_link_libraries(${AWESOME_PROJECT_EXECUTABLE} objectnd)
#target_link_libraries(${AWESOME_PROJECT_EXECUTABLE} settings)

# 5/9/2023
# The below connects the executable (first) 
# to the library (second and any more following)
#target_link_libraries(collisions3 invsqrt)



# Link against the SFML libraries
#target_link_libraries(collisions3 sfml-graphics sfml-audio)
# 5/10/2023 explanation:
# connect executable (first parameter, collisions3) 
# with all following libraries (all parameters 
# following the first, the names following)
#target_link_libraries(collisions3 sfml-graphics sfml-audio)


# 5/10/2023 explanatin:
# set the variables (first parameters)
# to the corresponding environment variables (second parameters)
#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# 5/10/2023 explanation:
# pack everything up i guess
#include(CPack)