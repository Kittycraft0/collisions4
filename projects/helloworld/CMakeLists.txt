# 5/26/2023
# set a custom variable with the project name so everything else works
# the word "AWESOME_" is included because "PROJECT_NAME" is already taken
# and I want to know that I made it immediately when I look at it in the future
# due to the slight unprofessionality of the variable name
# oh wait it's the executable not the name...
set(AWESOME_PROJECT_EXECUTABLE helloworld)
# YESSS IT WORKS!!! 
# THE EXECUTABLE NAME IS SET HERE AND IS ON A PER-PROJECT BASIS!!!

# The below like sets a variable of "main" to the 
# executable (.cpp without .h) for use in
# the cmake file here
# this (the first parameter thing) is 
# also probably the name of the created .exe file thing
#add_executable(collisions3 main.cpp)
add_executable(${AWESOME_PROJECT_EXECUTABLE} projects/helloworld/helloworld.cpp)

# 5/9/2023
# The below like sets the variable thing of "invsqrt" to the 
# library (.cpp with .h) for use in the cmake file here
#add_library(theinvsqrt ../src/math/invsqrt.cpp)

# 5/9/2023
# The below connects the executable (first) 
# to the library (second and any more following)
#target_link_libraries(${AWESOME_PROJECT_EXECUTABLE} theinvsqrt)
#set(INCLUDED_LIBRARIES ${INCLUDED_LIBRARIES} thehelloworld)