cmake_minimum_required(VERSION 3.10)
project(crisp)

if (PRESET_ARCH_X86_64)
    enable_language        (ASM_NASM)
    set                    (CMAKE_ASM_NASM_COMPILE_OBJECT "<CMAKE_ASM_NASM_COMPILER> <INCLUDES> <FLAGS> -o <OBJECT> <SOURCE>")
    add_compile_options    ("$<$<COMPILE_LANGUAGE:ASM_NASM>:-f $<IF:$<BOOL:$<TARGET_PROPERTY:NASM_OBJ_FORMAT>>, \ $<TARGET_PROPERTY:NASM_OBJ_FORMAT>, ${CMAKE_ASM_NASM_OBJECT_FORMAT}>>")

    if     (PRESET_WIN32)
        if (PRESET_ARCH_X86_64)
            add_library                        (
                crisp-arch-asm STATIC
                arch/x86_64/asm/atomic_msvc.asm
                arch/x86_64/asm/cpu_msvc.asm
                arch/x86_64/asm/bit_msvc.asm
            )

            set_target_properties(crisp-arch-asm PROPERTIES NASM_OBJ_FORMAT win64)
            add_library          (
                crisp-arch STATIC
                arch/x86_64/cpu.h
                arch/x86_64/cpu.c
            )

            target_link_libraries(crisp-arch PRIVATE crisp-arch-asm)
        elseif (PRESET_ARCH_X86)
            add_library                        (
                crisp-arch-asm STATIC
                arch/x86/asm/atomic_msvc.asm
                arch/x86/asm/cpu_msvc.asm
                arch/x86/asm/bit_msvc.asm
            )

            set_target_properties(crisp-arch-asm PROPERTIES NASM_OBJ_FORMAT win32)
            add_library          (
                crisp-arch STATIC
                arch/x86/cpu.h
                arch/x86/cpu.c
            )

            target_link_libraries(crisp-arch PRIVATE crisp-arch-asm)
        endif  ()
    elseif (UNIX AND NOT APPLE)
        if (PRESET_ARCH_X86_64)
            add_library                       (
                crisp-arch-asm STATIC
                arch/x86_64/asm/atomic_gcc.asm
                arch/x86_64/asm/cpu_gcc.asm
                arch/x86_64/asm/bit_gcc.asm
            )
            set_target_properties(crisp-arch-asm PROPERTIES NASM_OBJ_FORMAT elf64)
            add_library          (
                crisp-arch STATIC
                arch/x86_64/cpu.h
                arch/x86_64/cpu.c
            )

            target_link_libraries(crisp-arch PRIVATE crisp-arch-asm)
        elseif (PRESET_ARCH_X86)
            add_library                        (
                crisp-arch-asm STATIC
                arch/x86/asm/atomic_gcc.asm
                arch/x86/asm/cpu_gcc.asm
                arch/x86/asm/bit_gcc.asm
            )

            set_target_properties(crisp-arch-asm PROPERTIES NASM_OBJ_FORMAT elf32)
            add_library          (
                crisp-arch STATIC
                arch/x86/cpu.h
                arch/x86/cpu.c
            )

            target_link_libraries(crisp-arch PRIVATE crisp-arch-asm)
        endif()
    endif()
endif()

add_library (crisp STATIC
    type.h
    type_atom.h
    cpu.h
    bit.h

    atom.h
    atom.c

    task.h
    task.c

    sched.h
    sched.c

    fut.h
    fut.c
        
    mem.h
    mem.c

    node.h
    node.c

    str.h
    str.c

    list.h
    list.c

    obj.h
    obj.c

    box.h
    box.c

    map.h
    map.c

    set.h
    set.c

    endian.h
    endian.c

    ops.h
    ops/arith.h
    ops/arith.c

    ops/cast.h
    ops/cast.c

    ops/bit.h
    ops/bit.c

    ops/cmp.h
    ops/cmp.c

    ops/logical.h
    ops/logical.c
)

target_link_libraries(crisp PRIVATE crisp-arch)

add_library (crisp-include STATIC
    ../include/atom.h
    ../include/box.h
    ../include/bit.h
    ../include/cpu.h
    ../include/endian.h
    ../include/list.h
    ../include/mem.h
    ../include/node.h
    ../include/obj.h
    ../include/sched.h
    ../include/fut.h
    ../include/str.h
    ../include/task.h
    ../include/map.h
    ../include/set.h

    ../include/type_atom.h
    ../include/type.h
)

set_target_properties(crisp-include PROPERTIES LINKER_LANGUAGE C)