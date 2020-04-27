add_executable(disassembler ${CMAKE_CURRENT_LIST_DIR}/disassembler.cpp)
target_link_libraries(disassembler cpulib ramlib)
add_dependencies(disassembler cpulib ramlib)

add_executable(emulator emulator.cpp)
target_link_libraries(emulator cpulib ramlib)
add_dependencies(emulator cpulib ramlib)
