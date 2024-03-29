project                   (crisp-example-task)
add_executable            (task-01-basic basic.c)
target_link_libraries     (task-01-basic crisp)
target_include_directories(task-01-basic PRIVATE ../../../include)

add_executable            (task-02-counter counter.c)
target_link_libraries     (task-02-counter crisp)
target_include_directories(task-02-counter PRIVATE ../../../include)