file(GLOB_RECURSE TEST_SRC
    ${CMAKE_CURRENT_LIST_DIR}/*.h
    ${CMAKE_CURRENT_LIST_DIR}/*.cpp
)

add_executable(tests ${TEST_SRC})
target_link_libraries(tests gtest_main gtest machinelib pthread)
add_dependencies(tests machinelib)

option(USE_COVERAGE "coverage" ON)
if (USE_COVERAGE)
    target_compile_options(tests PUBLIC --coverage)
    target_compile_options(machinelib PUBLIC --coverage)
    target_link_libraries(machinelib gcov)
endif ()