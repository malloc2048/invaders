add_executable(disassembler disassembler_main.cpp)
target_link_libraries(disassembler disassemblerlib)
add_dependencies(disassembler disassemblerlib)

add_executable(cpu cpu_main.cpp)
target_link_libraries(cpu cpulib)
add_dependencies(cpu cpulib)
