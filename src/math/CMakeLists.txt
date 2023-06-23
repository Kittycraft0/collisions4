# 5/30/2023
# !!! CMakeLists.txt file for src/data
set(MATH_DIR ${SRC_DIR}/math)
# !!! Add the source files for the data library
set(SOURCES_MATH
    #data.cpp
    # Add more source files if needed
    ${MATH_DIR}/collisionMath.cpp
    ${MATH_DIR}/gravityMath.cpp
    ${MATH_DIR}/invsqrt.cpp
)

# !!! Create the data library
add_library(maath ${SOURCES_MATH})

# !!! Set the include directories for this folder library's header files
target_include_directories(maath PUBLIC ${MATH_DIR})

# !!! Link any dependencies for the data library
target_link_libraries(maath
    # Add any dependencies if needed
    ${SFML_LIBS}
)

#target_link_libraries(${AWESOME_PROJECT_EXECUTABLE} PUBLIC
#    maath
#    # Add any dependencies if needed
#)

# !!! 6/19/2023 Concatenate
set(INCLUDED_LIBRARIES ${INCLUDED_LIBRARIES} maath)

message("!!M Math loaded!")