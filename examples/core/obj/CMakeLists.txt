project                   (crisp-example-obj)
app                       (obj-01-basic basic.c)
target_link_libraries     (obj-01-basic crisp)
target_include_directories(obj-01-basic PRIVATE ../../../include)

app                       (obj-02-unique unique.c)
target_link_libraries     (obj-02-unique crisp)
target_include_directories(obj-02-unique PRIVATE ../../../include)