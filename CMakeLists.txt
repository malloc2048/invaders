cmake_minimum_required(VERSION 3.15)
project(emulator)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_CURRENT_LIST_DIR}/source/shared)

add_subdirectory(source/shared)
add_subdirectory(source/applications)