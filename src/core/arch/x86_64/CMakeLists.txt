if    (PRESET_FFI_VECTORCALL)
    asm                       (
        crisp-core-arch-asm
        asm/vectorcall_atom.asm
        asm/vectorcall_cpu.asm
        asm/vectorcall_bit.asm
    )
elseif(PRESET_FFI_SYSV)
    asm                    (
        crisp-core-arch-asm
        asm/sysv_atom.asm
        asm/sysv_cpu.asm
        asm/sysv_bit.asm
    )
endif ()

lib                     (
    NAME crisp-core-arch
    SRC
    cpu.h
    cpu.c
)

target_link_libraries(crisp-core-arch PRIVATE crisp-core-arch-asm)

link_libraries(crisp-core-arch-asm)
link_libraries(crisp-core-arch)