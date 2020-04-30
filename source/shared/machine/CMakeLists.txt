include_directories(${CMAKE_CURRENT_LIST_DIR})

file(GLOB_RECURSE RAMLIB_SRC ${CMAKE_CURRENT_LIST_DIR}/ram/*.h ${CMAKE_CURRENT_LIST_DIR}/ram/*.cpp)
add_library(ramlib ${RAMLIB_SRC})

file(GLOB_RECURSE CPULIB_SRC ${CMAKE_CURRENT_LIST_DIR}/cpu/*.h ${CMAKE_CURRENT_LIST_DIR}/cpu/*.cpp)
add_library(cpulib ${CPULIB_SRC})

file(GLOB_RECURSE VIDEOLIB_SRC ${CMAKE_CURRENT_LIST_DIR}/video/*.h ${CMAKE_CURRENT_LIST_DIR}/video/*.cpp)
add_library(videolib ${VIDEOLIB_SRC})
target_link_libraries(videolib sfml-graphics-s-d sfml-window-s-d sfml-system-s-d opengl32 winmm gdi32)

