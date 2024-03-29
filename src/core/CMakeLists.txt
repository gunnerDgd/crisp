cmake_minimum_required(VERSION 3.10)
project(crisp-core)

if (PRESET_ARCH_X86_64)
    enable_language        (ASM_NASM)
    set                    (CMAKE_ASM_NASM_COMPILE_OBJECT "<CMAKE_ASM_NASM_COMPILER> <INCLUDES> <FLAGS> -o <OBJECT> <SOURCE>")
    add_compile_options    ("$<$<COMPILE_LANGUAGE:ASM_NASM>:-f $<IF:$<BOOL:$<TARGET_PROPERTY:NASM_OBJ_FORMAT>>, \ $<TARGET_PROPERTY:NASM_OBJ_FORMAT>, ${CMAKE_ASM_NASM_OBJECT_FORMAT}>>")
    if    (PRESET_CALL_VECTORCALL)
        add_library                           (
            crisp-core-arch-asm STATIC
            arch/x86_64/asm/vectorcall_atom.asm
            arch/x86_64/asm/vectorcall_cpu.asm
            arch/x86_64/asm/vectorcall_bit.asm
        )
    elseif(PRESET_CALL_SYSV)
        add_library                      (
            crisp-core-arch-asm STATIC
            arch/x86_64/asm/sysv_atom.asm
            arch/x86_64/asm/sysv_cpu.asm
            arch/x86_64/asm/sysv_bit.asm
        )
    endif ()

    add_library (crisp-core-arch STATIC arch/x86_64/cpu.h arch/x86_64/cpu.c)
    if (PRESET_WIN32)
        set_target_properties(crisp-core-arch-asm PROPERTIES NASM_OBJ_FORMAT win64)
        target_link_libraries(crisp-core-arch PRIVATE crisp-core-arch-asm)
    elseif (UNIX AND NOT APPLE)
        set_target_properties(crisp-core-arch-asm PROPERTIES NASM_OBJ_FORMAT elf64)
        target_link_libraries(crisp-core-arch PRIVATE crisp-core-arch-asm)
    endif()
endif()

add_library (crisp-core STATIC
    type.h
    macro.h
    cpu.h
    bit.h

    atom.h
    atom.c

    fut.h
    fut.c
        
    mem.h
    mem.c

    this.h
    this.c

    task.h
    task.c

    obj.h
    obj.c

    box.h
    box.c

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

    sync/spsc.h
    sync/spsc.c

    sync/spmc.h
    sync/spmc.c

    sync/mpsc.h
    sync/mpsc.c

    sync/mpmc.h
    sync/mpmc.c
    sync.h

    ../core.h
    ../core.c
)

target_link_libraries(crisp-core PRIVATE crisp-core-arch)
add_library          (crisp-core-include STATIC
    ../../include/core.h

    ../../include/core/atom.h
    ../../include/core/box.h
    ../../include/core/bit.h
    ../../include/core/cpu.h
    ../../include/core/endian.h
    ../../include/core/mem.h
    ../../include/core/obj.h
    ../../include/core/fut.h
    ../../include/core/task.h

    ../../include/core/type.h

    ../../include/core/ops.h
    ../../include/core/ops/arith.h
    ../../include/core/ops/cast.h
    ../../include/core/ops/bit.h
    ../../include/core/ops/cmp.h
    ../../include/core/ops/logical.h

    ../../include/core/sync/spsc.h
    ../../include/core/sync/spmc.h
    ../../include/core/sync/mpsc.h
    ../../include/core/sync/mpmc.h
    ../../include/core/sync.h
)

set_target_properties(crisp-core-include PROPERTIES LINKER_LANGUAGE C)