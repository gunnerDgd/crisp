project(crisp-examples)
add_executable            (examples-mem-mem mem/mem.c)
target_link_libraries     (examples-mem-mem crisp)
target_include_directories(examples-mem-mem PRIVATE ../include)

add_executable            (examples-obj-obj obj/obj.c)
target_link_libraries     (examples-obj-obj crisp)
target_include_directories(examples-obj-obj PRIVATE ../include)

add_executable            (examples-list-list list/list.c)
target_link_libraries     (examples-list-list crisp)
target_include_directories(examples-list-list PRIVATE ../include)

add_executable            (examples-str-str str/str.c)
target_link_libraries     (examples-str-str crisp)
target_include_directories(examples-str-str PRIVATE ../include)

add_executable            (examples-map-map map/map.c)
target_link_libraries     (examples-map-map crisp)
target_include_directories(examples-map-map PRIVATE ../include)

add_executable            (examples-sched-sched sched/sched.c)
target_link_libraries     (examples-sched-sched crisp)
target_include_directories(examples-sched-sched PRIVATE ../include)

add_executable            (examples-set-set set/set.c)
target_link_libraries     (examples-set-set crisp)
target_include_directories(examples-set-set PRIVATE ../include)

add_executable            (examples-sync-mpmc sync/mpmc.c)
target_link_libraries     (examples-sync-mpmc crisp)
target_include_directories(examples-sync-mpmc PRIVATE ../include)