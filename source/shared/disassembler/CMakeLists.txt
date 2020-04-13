file(GLOB DISASSEMBLER_SRC ${CMAKE_CURRENT_LIST_DIR}/*.h ${CMAKE_CURRENT_LIST_DIR}/*.cpp)
add_library(disassemblerlib ${DISASSEMBLER_SRC})
target_link_libraries(disassemblerlib opcodeslib)
add_dependencies(disassemblerlib opcodeslib)
