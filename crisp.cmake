macro   (crisp_examples)
    add_subdirectory(lib/crisp/examples)
endmacro()

macro   (crisp_tls)
    opt (CRISP_TLS)
endmacro()

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)