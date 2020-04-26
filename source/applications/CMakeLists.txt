add_executable(disassembler ${CMAKE_CURRENT_LIST_DIR}/disassembler.cpp)
target_link_libraries(disassembler machinelib)
add_dependencies(disassembler machinelib)

add_executable(emulator emulator.cpp)
target_link_libraries(emulator machinelib)
add_dependencies(emulator machinelib)
