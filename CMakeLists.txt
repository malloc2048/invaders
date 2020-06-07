cmake_minimum_required(VERSION 3.15)
project(invaders)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)

if(WIN32)
    include_directories(${CMAKE_CURRENT_LIST_DIR}/sdl/include)
    include_directories(${CMAKE_CURRENT_LIST_DIR}/sdl/include/SDL2)
    link_directories(${CMAKE_CURRENT_LIST_DIR}/sdl/lib)
else()
    include_directories(/usr/include/SDL2)
endif()

include_directories(${CMAKE_CURRENT_LIST_DIR}/source)

file(GLOB_RECURSE I8080_SRC ${CMAKE_CURRENT_LIST_DIR}/source/i8080/*)
file(GLOB_RECURSE MEMORY_SRC ${CMAKE_CURRENT_LIST_DIR}/source/memory/*)
file(GLOB_RECURSE INVADERS_SRC ${CMAKE_CURRENT_LIST_DIR}/source/invaders/*)

add_executable(invaders ${I8080_SRC} ${MEMORY_SRC} ${INVADERS_SRC} source/invaders.cpp)
target_link_libraries(invaders SDL2)

add_executable(disassembler ${MEMORY_SRC} source/disassembler.cpp)

# Test executable
file(GLOB_RECURSE TESTS ${CMAKE_CURRENT_LIST_DIR}/test/*)
add_executable(unittests ${TESTS} ${I8080_SRC} ${MEMORY_SRC})
target_link_libraries(unittests gtest_main gtest pthread)

target_compile_options(unittests PUBLIC --coverage)
target_link_libraries(unittests gcov)
