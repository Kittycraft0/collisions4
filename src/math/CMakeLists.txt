# 5/30/2023
# CMakeLists.txt file for src/data
set(MATH_DIR ${SRC_DIR}/math)
# Add the source files for the data library
set(SOURCES_MATH
    #data.cpp
    # Add more source files if needed
    ${MATH_DIR}/collisionMath.cpp
    ${MATH_DIR}/gravityMath.cpp
    ${MATH_DIR}/invsqrt.cpp
)

# Create the data library
# "No SOURCES" - Why are you yelling at me!?
add_library(maath ${SOURCES_MATH})

# Set the include directories for the data library
#target_include_directories(maath PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

#Link any dependencies for the data library
#target_link_libraries(maath
#    # Add any dependencies if needed
#    ${SFML_LIBS}
#)

target_link_libraries(${AWESOME_PROJECT_EXECUTABLE} PUBLIC
    maath
    # Add any dependencies if needed
)
message("!!M Math loaded!")

# 6/19/2023 concatenate???
#set(INCLUDED_DIRECTORIES ${INCLUDED_LIBRARIES} maath)