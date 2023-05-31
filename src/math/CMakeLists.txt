# 5/30/2023
# CMakeLists.txt file for src/data

# Add the source files for the data library
set(SOURCES_MATH
    #data.cpp
    # Add more source files if needed
    collisionMath.cpp
    gravityMath.cpp
    invsqrt.cpp
)

# Create the data library
# "No SOURCES" - Why are you yelling at me!?
add_library(maath ${SOURCES_MATH})

# Set the include directories for the data library
target_include_directories(maath PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Link any dependencies for the data library
target_link_libraries(${AWESOME_PROJECT_EXECUTABLE} maath
    # Add any dependencies if needed
)