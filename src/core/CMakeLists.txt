cmake_minimum_required(VERSION 3.10)
project(crisp-core)

if   (PRESET_ARCH_X86_64)
    add_subdirectory(arch/x86_64)
elseif(PRESET_ARCH_X86)
    add_subdirectory(arch/x86)
endif()

lib                (
    NAME crisp-core
    OPT  nolibc
    SRC
    type.h
    macro.h
    print.h
    cpu.h
    bit.h

    mod.h
    mod.c

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

    ops/cmp.h
    ops/cmp.c

    ops/bit.h
    ops/bit.c

    ../core.h
    ../core.c
    ../main.c
)

inc                         (
    crisp-core-include
    ../../include/core.h

    ../../include/core/atom.h
    ../../include/core/box.h
    ../../include/core/mod.h
    ../../include/core/bit.h
    ../../include/core/endian.h
    ../../include/core/print.h
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
)

target_link_libraries(crisp-core PUBLIC crisp-core-arch crisp-core-arch-asm)
link_libraries       (crisp-core)