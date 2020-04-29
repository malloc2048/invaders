add_executable(disassembler ${CMAKE_CURRENT_LIST_DIR}/disassembler.cpp)
target_link_libraries(disassembler cpulib ramlib)
add_dependencies(disassembler cpulib ramlib)

add_executable(nes_disassembler ${CMAKE_CURRENT_LIST_DIR}/nes_disassembler.cpp)
target_link_libraries(nes_disassembler cpulib ramlib)
add_dependencies(nes_disassembler cpulib ramlib)

add_executable(emulator emulator.cpp)
target_link_libraries(emulator cpulib videolib ramlib)
add_dependencies(emulator cpulib videolib ramlib)
