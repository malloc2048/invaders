file(GLOB OPCODES_SRC ${CMAKE_CURRENT_LIST_DIR}/*.h ${CMAKE_CURRENT_LIST_DIR}/*.cpp)
add_library(opcodeslib ${OPCODES_SRC})
target_link_libraries(opcodeslib commonlib)
add_dependencies(opcodeslib commonlib)
