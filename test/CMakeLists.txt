target_compile_options(cpulib PUBLIC --coverage)
target_link_libraries(cpulib gcov)

target_compile_options(ramlib PUBLIC --coverage)
target_link_libraries(ramlib gcov)

target_compile_options(videolib PUBLIC --coverage)
target_link_libraries(videolib gcov)

file(GLOB_RECURSE OPCODES_TEST_SRC ${CMAKE_CURRENT_LIST_DIR}/shared/cpu/8080/opcodes/*)
add_executable(opcode_ut ${OPCODES_TEST_SRC})
target_compile_options(opcode_ut PUBLIC --coverage)
target_link_libraries(opcode_ut gtest_main gtest cpulib ramlib pthread)
add_dependencies(opcode_ut cpulib ramlib)

file(GLOB_RECURSE CPU_TEST_SRC ${CMAKE_CURRENT_LIST_DIR}/shared/cpu/*.h ${CMAKE_CURRENT_LIST_DIR}/shared/cpu/*.cpp)
add_executable(cpu_ut ${CPU_TEST_SRC})
target_compile_options(cpu_ut PUBLIC --coverage)
target_link_libraries(cpu_ut gtest_main gtest cpulib ramlib pthread)
add_dependencies(cpu_ut cpulib ramlib)

file(GLOB_RECURSE RAM_TEST_SRC ${CMAKE_CURRENT_LIST_DIR}/shared/memory/*.h ${CMAKE_CURRENT_LIST_DIR}/shared/memory/*.cpp)
add_executable(ram_ut ${RAM_TEST_SRC})
target_compile_options(ram_ut PUBLIC --coverage)
target_link_libraries(ram_ut gtest_main gtest ramlib gcov pthread)
add_dependencies(ram_ut ramlib)

file(GLOB_RECURSE VIDEO_TEST_SRC ${CMAKE_CURRENT_LIST_DIR}/shared/video/*.h ${CMAKE_CURRENT_LIST_DIR}/shared/video/*.cpp)
add_executable(video_ut ${VIDEO_TEST_SRC})
target_compile_options(video_ut PUBLIC --coverage)
target_link_libraries(video_ut videolib ramlib gcov pthread)
add_dependencies(video_ut videolib ramlib)
