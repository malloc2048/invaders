file(GLOB ARITHMETIC_TEST_SRC
    ${CMAKE_CURRENT_LIST_DIR}/arithmetic_group/*.h
    ${CMAKE_CURRENT_LIST_DIR}/arithmetic_group/*.cpp
)

add_executable(arithmetic_tests ${ARITHMETIC_TEST_SRC})
target_link_libraries(arithmetic_tests gtest_main gtest gcov cpulib)
add_dependencies(arithmetic_tests cpulib)
target_compile_options(arithmetic_tests PUBLIC --coverage)

target_compile_options(cpulib PUBLIC --coverage)
target_link_libraries(cpulib gcov)
