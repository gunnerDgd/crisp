enable_language(ASM_NASM)
set            (CMAKE_ASM_NASM_COMPILE_OBJECT 
                "<CMAKE_ASM_NASM_COMPILER> <INCLUDES> <FLAGS> -o <OBJECT> <SOURCE>")

add_compile_options("$<$<COMPILE_LANGUAGE:ASM_NASM>:-f                \
                     $<IF:$<BOOL:$<TARGET_PROPERTY:NASM_OBJ_FORMAT>>, \
                     $<TARGET_PROPERTY:NASM_OBJ_FORMAT>,              \
                     ${CMAKE_ASM_NASM_OBJECT_FORMAT}>>")

project(crisp.arch
        VERSION 0.1.0
        LANGUAGES C)

add_library(crisp.arch.x86_64.msvc
            spsc_msvc.asm
            stack_msvc.asm
            turbo_list_msvc.asm)

set_target_properties(crisp.arch.x86_64.msvc
                      PROPERTIES
                      NASM_OBJ_FORMAT win64)