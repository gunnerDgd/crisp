cmake_minimum_required(VERSION 3.12)

enable_language(ASM_NASM)
set            (CMAKE_ASM_NASM_COMPILE_OBJECT 
                "<CMAKE_ASM_NASM_COMPILER> <INCLUDES> <FLAGS> -o <OBJECT> <SOURCE>")

add_compile_options("$<$<COMPILE_LANGUAGE:ASM_NASM>:-f                \
                     $<IF:$<BOOL:$<TARGET_PROPERTY:NASM_OBJ_FORMAT>>, \
                     $<TARGET_PROPERTY:NASM_OBJ_FORMAT>,              \
                     ${CMAKE_ASM_NASM_OBJECT_FORMAT}>>")

project(crisp.list.turbo
        VERSION 0.1.0
        LANGUAGES C)

add_library(list.turbo_list STATIC
            turbo_list.h
            turbo_list.c)

add_library(turbo_list_x86_64_msvc STATIC
            turbo_list_x86_64_msvc.asm)
set_target_properties(turbo_list_x86_64_msvc
                      PROPERTIES NASM_OBJ_FORMAT win64)