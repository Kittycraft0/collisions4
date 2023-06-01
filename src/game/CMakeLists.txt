# 5/30/2023
# CMakeLists.txt file for src/data
set(GAME_DIR ${SRC_DIR}/game)
# Add the source files for the data library
set(SOURCES_GAME
    #data.cpp
    # Add more source files if needed
    ${GAME_DIR}/script.cpp
    ${GAME_DIR}/loop.cpp
)

# Create the data library
# "No SOURCES" - Why are you yelling at me!?
add_library(game ${SOURCES_GAME})

# Set the include directories for the data library
target_include_directories(game PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
#add_library(invsqrt ../src/math/invsqrt.cpp)
#target_link_libraries(${AWESOME_PROJECT_EXECUTABLE} PUBLIC invsqrt)

# Link any dependencies for the data library
target_link_libraries(
    game
    # Add any dependencies if needed
)

target_link_libraries(${AWESOME_PROJECT_EXECUTABLE} PUBLIC
    game
    # Add any dependencies if needed
)