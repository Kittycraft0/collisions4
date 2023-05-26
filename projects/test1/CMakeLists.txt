# The below like sets a variable of "main" to the 
# executable (.cpp without .h) for use in
# the cmake file here
# this (the first parameter thing) is 
# also probably the name of the created .exe file thing
#add_executable(collisions3 main.cpp)
add_executable(collisions3 projects/test1/main.cpp)

# 5/9/2023
# The below like sets the variable thing of "invsqrt" to the 
# library (.cpp with .h) for use in the cmake file here
add_library(invsqrt ../src/math/invsqrt.cpp)

# 5/9/2023
# The below connects the executable (first) 
# to the library (second and any more following)
target_link_libraries(collisions3 invsqrt)