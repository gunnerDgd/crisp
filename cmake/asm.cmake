enable_language    (ASM_NASM)
set                (CMAKE_ASM_NASM_COMPILE_OBJECT "<CMAKE_ASM_NASM_COMPILER> <INCLUDES> <FLAGS> -o <OBJECT> <SOURCE>")
add_compile_options("$<$<COMPILE_LANGUAGE:ASM_NASM>:-f $<IF:$<BOOL:$<TARGET_PROPERTY:NASM_OBJ_FORMAT>>, \ $<TARGET_PROPERTY:NASM_OBJ_FORMAT>, ${CMAKE_ASM_NASM_OBJECT_FORMAT}>>")


function   (asm NAME)
    add_library(${NAME} STATIC ${ARGN})
    if    (PRESET_WIN32)
        set_target_properties (
            ${NAME}
            PROPERTIES
            NASM_OBJ_FORMAT
            win64
        )
    elseif(PRESET_LINUX)
        set_target_properties (
            ${NAME}
            PROPERTIES
            NASM_OBJ_FORMAT
            elf64
        )
    endif ()
endfunction()