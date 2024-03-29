project                   (crisp-example-mem)
add_executable            (mem-01-basic basic.c)
target_link_libraries     (mem-01-basic crisp)
target_include_directories(mem-01-basic PRIVATE ../../../include)