cmake_minimum_required(VERSION 3.15)
project(emulator)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_CURRENT_LIST_DIR}/include/shared)

set(PROJECT_ROOT ${CMAKE_CURRENT_LIST_DIR})
set(SHARED_INC_ROOT ${PROJECT_ROOT}/include/shared)

add_subdirectory(source/shared)
add_subdirectory(source/applications)

option(BUILD_TESTS "build tests also" ON)
if(BUILD_TESTS)
    add_subdirectory(test)
ENDIF()
