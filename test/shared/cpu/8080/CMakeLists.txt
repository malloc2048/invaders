file(GLOB_RECURSE INSTRUCTION_TEST_SRC
    ${CMAKE_CURRENT_LIST_DIR}/instructions/*.h
    ${CMAKE_CURRENT_LIST_DIR}/instructions/*.cpp
)

add_executable(instruction_tests ${INSTRUCTION_TEST_SRC})
target_link_libraries(instruction_tests gtest_main gtest cpulib pthread)
add_dependencies(instruction_tests cpulib)

option(USE_COVERAGE "coverage" ON)
if (USE_COVERAGE)
    target_compile_options(instruction_tests PUBLIC --coverage)
    target_compile_options(cpulib PUBLIC --coverage)
    target_link_libraries(cpulib gcov)
endif ()
