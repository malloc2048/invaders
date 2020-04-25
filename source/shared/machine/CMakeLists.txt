file(GLOB_RECURSE SOURCE
    ${CMAKE_CURRENT_LIST_DIR}/*.h
    ${CMAKE_CURRENT_LIST_DIR}/*.cpp
)

include_directories(${CMAKE_CURRENT_LIST_DIR})

add_library(machinelib ${SOURCE})
