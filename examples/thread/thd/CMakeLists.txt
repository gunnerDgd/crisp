project                   (crisp-example-thread)
add_executable            (thread-01-basic basic.c)
target_link_libraries     (thread-01-basic crisp)
target_include_directories(thread-01-basic PRIVATE ../../../include)