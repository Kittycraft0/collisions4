# 5/30/2023
# chat gpt
# CMakeLists.txt file for src/data
set(RENDER_DIR ${SRC_DIR}/render)
#message(STATUS ${SRC_DIR} AAAAA)
#message(STATUS ${RENDER_DIR})

# Add the source files for the data library
set(SOURCES_RENDER
    #data.cpp
    # Add more source files if needed
    ${RENDER_DIR}/initWindow.cpp
    ${RENDER_DIR}/render2d.cpp
)
#message(STATUS ${SOURCES_RENDER})
# !!! Create the render library
add_library(render ${SOURCES_RENDER})


# !!! 6/22/2023 Link the SFML .hpp's to the library's "include path"
target_include_directories(render PUBLIC ${ROOT_DIR}/include/GCC-SFML-2.5.1/include)

# 6/22/2023 Link the SFML .dll's to the library's "include path"
target_link_directories(render PUBLIC ${ROOT_DIR}/include/GCC-SFML-2.5.1/bin)

## Set the include directories for the render library
target_include_directories(render PUBLIC ${RENDER_DIR})

#
#    # Add the SFML include directories
#    target_include_directories(render PUBLIC ${PROJECT_ROOT}/include/${THE_OS}-SFML-2.5.1/include)
#
#    # Add the SFML library directories
#    target_link_directories(render PUBLIC ${PROJECT_ROOT}/include/${THE_OS}-SFML-2.5.1/bin)

# Link any dependencies for the data library
#target_link_libraries(render
#    # Add any dependencies if needed
#)
# !!! Link any dependencies for the data library
target_link_libraries(render
    # Add any dependencies if needed
    ${SFML_DLLS}
)
message("!!R SFML_LIBS: " ${SFML_DLLS})

#target_link_libraries(${AWESOME_PROJECT_EXECUTABLE} PUBLIC
#    render
#    # Add any dependencies if needed
#)

message("!!R INCLUDED_LIBRARIES: " ${INCLUDED_LIBRARIES})
# 6/19/2023 concatenate???
# 6/23/2023 Change the variable in the local scope
list(APPEND INCLUDED_LIBRARIES render)
# 6/23/2023 Update the variable in the global scope by replacing it with the newer variant in the local scope
set(INCLUDED_LIBRARIES ${INCLUDED_LIBRARIES} PARENT_SCOPE)
message("!!R INCLUDED_LIBRARIES: " ${INCLUDED_LIBRARIES})

message("!!R Render loaded!")