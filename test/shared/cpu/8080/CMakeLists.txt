file(GLOB_RECURSE TEST_SRC
    ${CMAKE_CURRENT_LIST_DIR}/*.h
    ${CMAKE_CURRENT_LIST_DIR}/*.cpp
)

add_executable(tests ${TEST_SRC})
target_link_libraries(tests gtest_main gtest cpulib pthread)
add_dependencies(tests cpulib)

option(USE_COVERAGE "coverage" OFF)
if (USE_COVERAGE)
    target_compile_options(tests PUBLIC --coverage)
    target_compile_options(cpulib PUBLIC --coverage)
    target_link_libraries(cpulib gcov)
endif ()
