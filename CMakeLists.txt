cmake_minimum_required(VERSION 3.10)
project(crisp)
if     (PRESET_ARCH_X86_64)
    add_compile_definitions(PRESET_ARCH_X86_64)
endif()

if (PRESET_ARCH_X86_64)
    enable_language        (ASM_NASM)
    set                    (CMAKE_ASM_NASM_COMPILE_OBJECT "<CMAKE_ASM_NASM_COMPILER> <INCLUDES> <FLAGS> -o <OBJECT> <SOURCE>")
    add_compile_options    ("$<$<COMPILE_LANGUAGE:ASM_NASM>:-f $<IF:$<BOOL:$<TARGET_PROPERTY:NASM_OBJ_FORMAT>>, \ $<TARGET_PROPERTY:NASM_OBJ_FORMAT>, ${CMAKE_ASM_NASM_OBJECT_FORMAT}>>")

    if (WIN32)
        add_library                           (
            crisp-arch-asm STATIC 
            src/arch/x86_64/asm/atomic_msvc.asm
            src/arch/x86_64/asm/cpu_msvc.asm
            src/arch/x86_64/asm/bit_msvc.asm
        )

        set_target_properties(crisp-arch-asm PROPERTIES NASM_OBJ_FORMAT win64)
        add_library          (crisp-arch     
            STATIC     
            src/arch/x86_64/cpu.h 
            src/arch/x86_64/cpu.c

            src/arch/x86_64/atom.c
        )
    elseif (UNIX AND NOT APPLE)
        add_library          (build-crisp-asm STATIC     src/arch/x86_64/asm/atomic_gcc.asm src/arch/x86_64/asm/cpu_gcc.asm)
        set_target_properties(build-crisp-asm PROPERTIES NASM_OBJ_FORMAT win64)
        add_library          (build-crisp     STATIC     src/arch/x86_64/cpu.h src/arch/x86_64/cpu.c)
    endif()
endif()

add_library (crisp STATIC
    src/type.h
    src/type_atom.h
    src/atom.h
    src/cpu.h
    src/bit.h

    src/task.h
    src/task.c

    src/sched.h
    src/sched.c
        
    src/mem.h
    src/mem.c

    src/node.h
    src/node.c

    src/str.h
    src/str.c

    src/list.h
    src/list.c

    src/obj.h
    src/obj.c

    src/box.h
    src/box.c

    src/map.h
    src/map.c

    src/set.h
    src/set.c

    src/endian.h
    src/endian.c
)

add_library (crisp-include STATIC
    include/atom.h
    include/box.h
    include/bit.h
    include/cpu.h
    include/endian.h
    include/list.h
    include/mem.h
    include/node.h
    include/obj.h
    include/sched.h
    include/str.h
    include/task.h
    include/map.h
    include/set.h

    include/type_atom.h
    include/type.h
)

set_target_properties(crisp-include PROPERTIES LINKER_LANGUAGE C)

if(PRESET_BUILD_EXAMPLES)
    add_executable            (examples-mem-mem examples/mem/mem.c)
    target_link_libraries     (examples-mem-mem build build-arch build-arch-asm)
    target_include_directories(examples-mem-mem PRIVATE include)

    add_executable            (examples-obj-obj examples/obj/obj.c)
    target_link_libraries     (examples-obj-obj build build-arch build-arch-asm)
    target_include_directories(examples-obj-obj PRIVATE include)

    add_executable            (examples-list-list examples/list/list.c)
    target_link_libraries     (examples-list-list build build-arch build-arch-asm)
    target_include_directories(examples-list-list PRIVATE include)

    add_executable            (examples-str-str examples/str/str.c)
    target_link_libraries     (examples-str-str build build-arch build-arch-asm)
    target_include_directories(examples-str-str PRIVATE include)

    add_executable            (examples-map-map examples/map/map.c)
    target_link_libraries     (examples-map-map build build-arch build-arch-asm)
    target_include_directories(examples-map-map PRIVATE include)

    add_executable            (examples-sched-sched examples/sched/sched.c)
    target_link_libraries     (examples-sched-sched build build-arch build-arch-asm)
    target_include_directories(examples-sched-sched PRIVATE include)

    add_executable            (examples-set-set examples/set/set.c)
    target_link_libraries     (examples-set-set build build-arch build-arch-asm)
    target_include_directories(examples-set-set PRIVATE include)
endif()