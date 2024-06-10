add_subdirectory(mem)
add_subdirectory(obj)
add_subdirectory(task)
add_subdirectory(sync)

app                       (core-01-print print.c)
target_link_libraries     (core-01-print crisp)
target_include_directories(core-01-print PRIVATE ../../include)