cmake_minimum_required(VERSION 3.15)
project(invaders)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)

include_directories(${CMAKE_CURRENT_LIST_DIR}/invaders/include)
if(WIN32)
    include_directories(${CMAKE_CURRENT_LIST_DIR}/sdl/include)
    include_directories(${CMAKE_CURRENT_LIST_DIR}/sdl/include/SDL2)
    link_directories(${CMAKE_CURRENT_LIST_DIR}/sdl/lib/mingw64)
else()
    include_directories(/usr/include/SDL2)
endif()

file(GLOB_RECURSE common_src
    ${CMAKE_CURRENT_LIST_DIR}/invaders/include/common/*.h
    ${CMAKE_CURRENT_LIST_DIR}/invaders/source/common/*.cpp
    )
add_library(common ${common_src})

file(GLOB_RECURSE hardware_src
    ${CMAKE_CURRENT_LIST_DIR}/invaders/include/hardware/*.h
    ${CMAKE_CURRENT_LIST_DIR}/invaders/source/hardware/*.cpp
)

file(GLOB src
    ${CMAKE_CURRENT_LIST_DIR}/invaders/include/*.h
    ${CMAKE_CURRENT_LIST_DIR}/invaders/source/*.cpp
)
add_executable(invaders ${src} ${hardware_src} ${common_src})
target_link_libraries(invaders SDL2)

file(GLOB_RECURSE tests ${CMAKE_CURRENT_LIST_DIR}/invaders/test/*)
add_executable(unittests ${tests} ${hardware_src} ${common_src})
target_link_libraries(unittests gtest_main gtest gcov pthread)
target_compile_options(unittests PUBLIC --coverage)
