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
# Create the render library
add_library(render ${SOURCES_RENDER})

# Set the include directories for the render library
target_include_directories(render PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

    # Add the SFML include directories
    target_include_directories(render PUBLIC ${PROJECT_ROOT}/include/${THE_OS}-SFML-2.5.1/include)

    # Add the SFML library directories
    target_link_directories(render PUBLIC ${PROJECT_ROOT}/include/${THE_OS}-SFML-2.5.1/bin)

# Link any dependencies for the data library
#target_link_libraries(render
#    # Add any dependencies if needed
#)
# Link any dependencies for the data library
target_link_libraries(render
    # Add any dependencies if needed
    ${SFML_LIBS}
)


#target_link_libraries(${AWESOME_PROJECT_EXECUTABLE} PUBLIC
#    render
#    # Add any dependencies if needed
#)

# 6/19/2023 concatenate???
set(INCLUDED_DIRECTORIES ${INCLUDED_LIBRARIES} render)