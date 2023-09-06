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
    ${MATH_DIR}/wallCollide.cpp
)

# !!! Create the data library
add_library(maath ${SOURCES_MATH})

# 6/22/2023 Link the SFML .hpp's to the library's "include path"
target_include_directories(maath PUBLIC ${ROOT_DIR}/include/GCC-SFML-2.5.1/include)

# 6/22/2023 Link the SFML .dll's to the library's "include path"
target_link_directories(maath PUBLIC ${ROOT_DIR}/include/GCC-SFML-2.5.1/bin)

# !!! Set the include directories for this folder library's header files
target_include_directories(maath PUBLIC ${MATH_DIR})

# !!! Link any dependencies for the data library
target_link_libraries(maath
    # Add any dependencies if needed
    ${SFML_DLLS}
)

#target_link_libraries(${AWESOME_PROJECT_EXECUTABLE} PUBLIC
#    maath
#    # Add any dependencies if needed
#)

# !!! 6/19/2023 Concatenate
# 6/23/2023 Change the variable in the local scope
list(APPEND INCLUDED_LIBRARIES maath)
# 6/23/2023 Update the variable in the global scope by replacing it with the newer variant in the local scope
set(INCLUDED_LIBRARIES ${INCLUDED_LIBRARIES} PARENT_SCOPE)

message("!!M Math loaded!")