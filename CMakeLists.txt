project(crisp)

add_subdirectory(src)
set(CRISP ON PARENT_SCOPE)
set(CRISP_INC ${CMAKE_CURRENT_SOURCE_DIR}/include PARENT_SCOPE)
set(CRISP_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src     PARENT_SCOPE)