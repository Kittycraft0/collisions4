# 5/30/2023
# !!! CMakeLists.txt file for src/data
set(INIT_DIR ${SRC_DIR}/init)
# !!! Add the source files for the data library
set(SOURCES_INIT
    #data.cpp
    # Add more source files if needed
    ${INIT_DIR}/initObjects1.cpp
)

# !!! Create the data library
add_library(iniit ${SOURCES_INIT})

# 6/22/2023 Link the SFML .hpp's to the library's "include path"
target_include_directories(iniit PUBLIC ${ROOT_DIR}/include/GCC-SFML-2.5.1/include)

# 6/22/2023 Link the SFML .dll's to the library's "include path"
target_link_directories(iniit PUBLIC ${ROOT_DIR}/include/GCC-SFML-2.5.1/bin)

# !!! Set the include directories for this folder library's header files
target_include_directories(iniit PUBLIC ${INIT_DIR})

# !!! Link any dependencies for the data library
target_link_libraries(iniit
    # Add any dependencies if needed
    ${SFML_DLLS}
)

#target_link_libraries(${AWESOME_PROJECT_EXECUTABLE} PUBLIC
#    maath
#    # Add any dependencies if needed
#)

# !!! 6/19/2023 Concatenate
# 6/23/2023 Change the variable in the local scope
list(APPEND INCLUDED_LIBRARIES iniit)
# 6/23/2023 Update the variable in the global scope by replacing it with the newer variant in the local scope
set(INCLUDED_LIBRARIES ${INCLUDED_LIBRARIES} PARENT_SCOPE)

message("!!I Init loaded!")