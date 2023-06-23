cmake_minimum_required(VERSION 3.0.0)
project(cppProject VERSION 0.1.0)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_executable(test1 projects/test1/main.cpp)
add_library(invsqrt ../src/math/invsqrt.cpp)
target_link_libraries(test1 PUBLIC invsqrt)

# Add the SFML .hpp's
target_include_directories(test1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/GCC-SFML-2.5.1/include)

# Add the SFML .dll's
target_link_directories(test1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/GCC-SFML-2.5.1/bin)

# Link SFML .dll's to the executable
target_link_libraries(test1 PUBLIC
    sfml-system-2
    sfml-window-2
    sfml-graphics-2
    sfml-audio-2
    sfml-network-2
)
# 6/19/2023 - updated
target_link_libraries(test1 PUBLIC 
    ${SFML_LIBS}
    ${INCLUDED_LIBRARIES}
)