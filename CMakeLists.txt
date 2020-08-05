cmake_minimum_required(VERSION 3.15)
project(invaders)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)

if(WIN32)
    include_directories(${CMAKE_CURRENT_LIST_DIR}/sdl/include)
    include_directories(${CMAKE_CURRENT_LIST_DIR}/sdl/include/SDL2)
    link_directories(${CMAKE_CURRENT_LIST_DIR}/sdl/lib/mingw64)
else()
    include_directories(/usr/include/SDL2)
endif()

#include_directories(${CMAKE_CURRENT_LIST_DIR}/source)
#
#file(GLOB_RECURSE GAME_SRC ${CMAKE_CURRENT_LIST_DIR}/source/invaders/*)
#file(GLOB_RECURSE CABINET_SRC ${CMAKE_CURRENT_LIST_DIR}/source/cabinet/*)
#
#add_executable(invaders ${GAME_SRC} ${CABINET_SRC} source/game.cpp)
#target_link_libraries(invaders SDL2)
#
#add_executable(disassembler ${CABINET_SRC} source/disassembler.cpp)
#
## Test executable
#file(GLOB_RECURSE TESTS ${CMAKE_CURRENT_LIST_DIR}/test/*)
#add_executable(unittests ${TESTS} ${CABINET_SRC} ${MEMORY_SRC})
#target_link_libraries(unittests gtest_main gtest pthread)
#
#target_compile_options(unittests PUBLIC --coverage)
#target_link_libraries(unittests gcov)

include_directories(${CMAKE_CURRENT_LIST_DIR}/invaders/include)


file(GLOB_RECURSE hardware_src
    ${CMAKE_CURRENT_LIST_DIR}/invaders/include/hardware/*.h
    ${CMAKE_CURRENT_LIST_DIR}/invaders/source/hardware/*.cpp
)

file(GLOB src
    ${CMAKE_CURRENT_LIST_DIR}/invaders/include/*.h
    ${CMAKE_CURRENT_LIST_DIR}/invaders/source/*.cpp
)
add_executable(invaders ${src} ${hardware_src})
target_link_libraries(invaders SDL2)

file(GLOB_RECURSE tests ${CMAKE_CURRENT_LIST_DIR}/invaders/test/*)
add_executable(unittests ${tests} ${hardware_src})
target_link_libraries(unittests gtest_main gtest gcov pthread)
target_compile_options(unittests PUBLIC --coverage)
