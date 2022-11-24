cmake_minimum_required(VERSION 3.12)

enable_language(ASM_NASM)
set            (CMAKE_ASM_NASM_COMPILE_OBJECT 
                "<CMAKE_ASM_NASM_COMPILER> <INCLUDES> <FLAGS> -o <OBJECT> <SOURCE>")

add_compile_options("$<$<COMPILE_LANGUAGE:ASM_NASM>:-f                \
                     $<IF:$<BOOL:$<TARGET_PROPERTY:NASM_OBJ_FORMAT>>, \
                     $<TARGET_PROPERTY:NASM_OBJ_FORMAT>,              \
                     ${CMAKE_ASM_NASM_OBJECT_FORMAT}>>")

project(crisp.atomic
        VERSION 0.1.0
        LANGUAGES C)

add_library(spsc_controller_x86_64_msvc STATIC
            spsc_controller_x86_64_msvc.asm)
set_target_properties(spsc_controller_x86_64_msvc
                      PROPERTIES NASM_OBJ_FORMAT win64)

add_library(stack_controller_x86_64_msvc STATIC
            stack_controller_x86_64_msvc.asm)
set_target_properties(stack_controller_x86_64_msvc
                      PROPERTIES NASM_OBJ_FORMAT win64)

add_library(atomic.spsc STATIC
            type_spsc.h
            spsc.h
            spsc_controller.h
            spsc.c
            spsc_controller.c)

add_library(atomic.stack STATIC
            type_stack.h
            stack.h
            stack.c)