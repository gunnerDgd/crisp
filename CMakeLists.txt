cmake_minimum_required(VERSION 3.10)
project(build)
if     (PRESET_ARCH_X86_64)
    add_compile_definitions(PRESET_ARCH_X86_64)
endif()

if (PRESET_ARCH_X86_64)
    enable_language        (ASM_NASM)
    set                    (CMAKE_ASM_NASM_COMPILE_OBJECT "<CMAKE_ASM_NASM_COMPILER> <INCLUDES> <FLAGS> -o <OBJECT> <SOURCE>")
    add_compile_options    ("$<$<COMPILE_LANGUAGE:ASM_NASM>:-f $<IF:$<BOOL:$<TARGET_PROPERTY:NASM_OBJ_FORMAT>>, \ $<TARGET_PROPERTY:NASM_OBJ_FORMAT>, ${CMAKE_ASM_NASM_OBJECT_FORMAT}>>")

    add_library                           (
        build-arch-asm STATIC
        src/arch/x86_64/asm/atomic_msvc.asm 
        src/arch/x86_64/asm/cpu_msvc.asm
    )
    set_target_properties(build-arch-asm PROPERTIES NASM_OBJ_FORMAT win64)

    add_library                       (
        build-arch STATIC
        src/arch/x86_64/cpu.h
        src/arch/x86_64/cpu.c
        src/arch/cpu.h
    )
endif()

add_library (build STATIC
    src/type.h
    src/type_atom.h
        
    src/mem.h
    src/mem.c

    src/atom.h
    src/atom.c

    src/str.h
    src/str.c

    src/list.h
    src/list.c

    src/obj_list.h
    src/obj_list.c

    src/obj.h
    src/obj.c

    src/cpu.h
    src/cpu.c

    src/box.h
    src/box.c

    src/endian.h
    src/endian.c
        
    src/details/mem.h
    src/details/mem.c

    src/details/atom.h

    src/details/str.h
    src/details/str.c

    src/details/list.h
    src/details/list.c

    src/details/obj_list.h
    src/details/obj_list.c

    src/details/obj.h
    src/details/obj.c

    src/details/box.h
    src/details/box.c
)

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

    add_executable            (examples-cpu-cpu examples/cpu/cpu.c)
    target_link_libraries     (examples-cpu-cpu build build-arch build-arch-asm)
    target_include_directories(examples-cpu-cpu PRIVATE include)
endif()