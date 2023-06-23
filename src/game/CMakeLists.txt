# 5/30/2023
# !!! CMakeLists.txt file for src/data
set(GAME_DIR ${SRC_DIR}/game)
# Add the source files for the data library
set(SOURCES_GAME
    #data.cpp
    # Add more source files if needed
    ${GAME_DIR}/script.cpp
    ${GAME_DIR}/loop.cpp
)

# !!! Create the data library
# "No SOURCES" - Why are you yelling at me!?
add_library(game ${SOURCES_GAME})

# 6/22/2023 Link the SFML .hpp's to the library's "include path"
target_include_directories(game PUBLIC ${ROOT_DIR}/include/GCC-SFML-2.5.1/include)

# 6/22/2023 Link the SFML .dll's to the library's "include path"
target_link_directories(game PUBLIC ${ROOT_DIR}/include/GCC-SFML-2.5.1/bin)


# !!! Set the include directories for the data library
target_include_directories(game PUBLIC ${GAME_DIR})

#add_library(invsqrt ../src/math/invsqrt.cpp)
#target_link_libraries(${AWESOME_PROJECT_EXECUTABLE} PUBLIC invsqrt)

# !!! Link any dependencies for the data library
target_link_libraries(game
    # Add any dependencies if needed
    ${SFML_DLLS}
)

#target_link_libraries(${AWESOME_PROJECT_EXECUTABLE} PUBLIC
#    game
#    # Add any dependencies if needed
#)

# !!! 6/19/2023 concatenate???
# 6/23/2023 Change the variable in the local scope
list(APPEND INCLUDED_LIBRARIES game)
# 6/23/2023 Update the variable in the global scope by replacing it with the newer variant in the local scope
set(INCLUDED_LIBRARIES ${INCLUDED_LIBRARIES} PARENT_SCOPE)

message("!!G Game loaded!")