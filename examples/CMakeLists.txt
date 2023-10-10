project(build-examples)
if     (PRESET_X86_64)
    add_compile_definitions(PRESET_X86_64)
elseif (PRESET_X86)
    add_compile_definitions(PRESET_X86)
elseif (PRESET_AARCH64)
    add_compile_definitions(PRESET_AARCH64)
endif  ()

if(UNIX AND NOT APPLE)
    set                    (PRESET_LINUX ON)
    add_compile_definitions(PRESET_LINUX)
elseif(WIN32)
    set                    (PRESET_WIN32 ON)
    add_compile_definitions(PRESET_WIN32)
endif ()

add_executable       (examples-mem-mem mem/mem.c)
target_link_libraries(examples-mem-mem build build-arch)

add_executable       (examples-obj-obj obj/obj.c)
target_link_libraries(examples-obj-obj build build-arch)

add_executable       (examples-list-list list/list.c)
target_link_libraries(examples-list-list build build-arch)

add_executable       (examples-str-str str/str.c)
target_link_libraries(examples-str-str build build-arch)