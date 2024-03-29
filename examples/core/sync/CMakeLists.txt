add_executable            (sync-01-spsc spsc.c)
target_link_libraries     (sync-01-spsc crisp)
target_include_directories(sync-01-spsc PRIVATE ../../../include)

add_executable            (sync-02-spmc spmc.c)
target_link_libraries     (sync-02-spmc crisp)
target_include_directories(sync-02-spmc PRIVATE ../../../include)

add_executable            (sync-03-mpsc mpsc.c)
target_link_libraries     (sync-03-mpsc crisp)
target_include_directories(sync-03-mpsc PRIVATE ../../../include)

add_executable            (sync-04-mpmc mpmc.c)
target_link_libraries     (sync-04-mpmc crisp)
target_include_directories(sync-04-mpmc PRIVATE ../../../include)