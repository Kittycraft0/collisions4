# 5/30/2023
# chat gpt
# CMakeLists.txt file for src/data

# Add the source files for the data library
set(SOURCES_RENDER
    #data.cpp
    # Add more source files if needed
    initWindow.cpp
)

# Create the render library
add_library(render ${SOURCES_RENDER})

# Set the include directories for the render library
target_include_directories(render PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Link any dependencies for the data library
target_link_libraries(render
    # Add any dependencies if needed
)