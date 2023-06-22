













# 6/22/2023
# Because I am currently having so much trouble, 
# seemingly mostly due to a lack of understanding of what does what, 
# I am making this file here today to help sort out definitions 
# and what certain code commands do.

# 6/22/2023
# ChatGPT partially helped

# 6/22/2023
# Basically takes code directly from another file 
# and reads it as if it were in the original file.
include(my_functions.cmake)

# 6/22/2023
# Adds directories to the include path during compilation.
# Is not recursive.
# Does not read actual file contents.
# Does not read child folders.
# Does not read CMakeLists.txt files in root or child folders.
# Reads: 
# .h: C header files
# .hpp: C++ header files
# .hxx: C++ header files
# .hh: C++ header files (less common)
# Other custom extensions used for header files in specific scenarios or frameworks
include_directories(include_dir1 include_dir2)


# "To include directories recursively and process 
# CMakeLists.txt files in those directories, 
# you can use the add_subdirectory() command instead. 
# add_subdirectory() allows you to specify a subdirectory 
# containing its own CMakeLists.txt file, 
# which will be processed and executed by CMake. 
# If you need to include directories recursively 
# and maintain a cascading behavior, 
# you can use a combination of include_directories() 
# and add_subdirectory() to achieve your desired result." 


# 6/22/2023
# "Adds a subdirectory."
# Is recursive.
# Recursively reads and executes CMakeLists.txt files
# in the root included folder as well as child folders.
add_subdirectory(subdirectory)


# 6/22/2023
# Sets target header files to be read?

# "The SYSTEM keyword can be used to indicate that the 
# specified directories are system directories. 
# It can help suppress warnings that may be 
# generated when including system headers."

# "The BEFORE keyword can be used to prepend 
# the specified directories to the include directories 
# list, placing them at the front of the search path."

target_include_directories(target_name [SYSTEM] [BEFORE]
    <INTERFACE|PUBLIC|PRIVATE> [header_dir1] [header_dir2 ...])

# 6/22/2023
# Link DLL libraries and to-be-compiled libraries to your target
target_link_libraries(MyTarget PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/path/to/dll_file.dll
)
