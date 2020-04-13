file(GLOB_RECURSE CPU_SRC ${CMAKE_CURRENT_LIST_DIR}/*.h ${CMAKE_CURRENT_LIST_DIR}/*.cpp)
add_library(cpulib ${CPU_SRC})
target_link_libraries(cpulib opcodeslib)
add_dependencies(cpulib opcodeslib)
