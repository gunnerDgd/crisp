cmake_minimum_required(VERSION 3.10)

add_compile_definitions(CRISP_PRESET_LINUX)
add_compile_definitions(CRISP_PRESET_ARCH_X86_64)

enable_language    (ASM_NASM)
set                (CMAKE_ASM_NASM_COMPILE_OBJECT "<CMAKE_ASM_NASM_COMPILER> <INCLUDES> <FLAGS> -o <OBJECT> <SOURCE>")
add_compile_options("$<$<COMPILE_LANGUAGE:ASM_NASM>:-f $<IF:$<BOOL:$<TARGET_PROPERTY:NASM_OBJ_FORMAT>>, \ $<TARGET_PROPERTY:NASM_OBJ_FORMAT>, ${CMAKE_ASM_NASM_OBJECT_FORMAT}>>")


project    (crisp)
add_library(crisp STATIC
        ${CMAKE_SOURCE_DIR}/crisp/type.h
        ${CMAKE_SOURCE_DIR}/crisp/type_atomic.h

        ${CMAKE_SOURCE_DIR}/crisp/details/alloc.h
        ${CMAKE_SOURCE_DIR}/crisp/details/alloc.c

        ${CMAKE_SOURCE_DIR}/crisp/details/alloc_cstd.h
        ${CMAKE_SOURCE_DIR}/crisp/details/alloc_cstd.c

        ${CMAKE_SOURCE_DIR}/crisp/details/mem.h
        ${CMAKE_SOURCE_DIR}/crisp/details/mem.c

        ${CMAKE_SOURCE_DIR}/crisp/details/mem_cstd.h
        ${CMAKE_SOURCE_DIR}/crisp/details/mem_cstd.c

        ${CMAKE_SOURCE_DIR}/crisp/details/object.h
        ${CMAKE_SOURCE_DIR}/crisp/details/object.c

        ${CMAKE_SOURCE_DIR}/crisp/details/str.h
        ${CMAKE_SOURCE_DIR}/crisp/details/str.c

        ${CMAKE_SOURCE_DIR}/crisp/extension/details/file.h
        ${CMAKE_SOURCE_DIR}/crisp/extension/details/file.c

        ${CMAKE_SOURCE_DIR}/crisp/details/atomic.h
        ${CMAKE_SOURCE_DIR}/crisp/atomic.h
        ${CMAKE_SOURCE_DIR}/crisp/atomic.c

        ${CMAKE_SOURCE_DIR}/crisp/details/list.h
        ${CMAKE_SOURCE_DIR}/crisp/details/list.c

        ${CMAKE_SOURCE_DIR}/crisp/alloc.h
        ${CMAKE_SOURCE_DIR}/crisp/alloc.c

        ${CMAKE_SOURCE_DIR}/crisp/mem.h
        ${CMAKE_SOURCE_DIR}/crisp/mem.c

        ${CMAKE_SOURCE_DIR}/crisp/object.h
        ${CMAKE_SOURCE_DIR}/crisp/object.c

        ${CMAKE_SOURCE_DIR}/crisp/list.h
        ${CMAKE_SOURCE_DIR}/crisp/list.c

        ${CMAKE_SOURCE_DIR}/crisp/extension/file.c
        ${CMAKE_SOURCE_DIR}/crisp/extension/file.c
)

add_library          (crisp-arch ${CMAKE_SOURCE_DIR}/crisp/details-arch/x86_64/x86_64_gcc_atomic.asm)
set_target_properties(crisp-arch PROPERTIES NASM_OBJ_FORMAT elf64)