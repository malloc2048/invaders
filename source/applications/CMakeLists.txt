add_executable(disassembler disassembler_main.cpp)
target_link_libraries(disassembler disassemblerlib)
add_dependencies(disassembler disassemblerlib)

add_executable(emulator emulator.cpp)
target_link_libraries(emulator cpulib)
add_dependencies(emulator cpulib)

add_executable(hexdump hexdump.cpp)
target_link_libraries(hexdump cpulib)
add_dependencies(hexdump cpulib)
