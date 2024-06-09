project                   (crisp-example-mem)
app                       (mem-01-basic basic.c)
target_link_libraries     (mem-01-basic crisp)
target_include_directories(mem-01-basic PRIVATE ../../../include)

app                       (mem-02-ops ops.c)
target_link_libraries     (mem-02-ops crisp)
target_include_directories(mem-02-ops PRIVATE ../../../include)