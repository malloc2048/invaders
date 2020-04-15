file(GLOB COMMON_SRC ${SHARED_INC_ROOT}/common/*.h ${CMAKE_CURRENT_LIST_DIR}/*.cpp)
add_library(commonlib ${COMMON_SRC})
