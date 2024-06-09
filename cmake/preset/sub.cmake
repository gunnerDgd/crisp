function   (sub_libc)
    if   (DEFINED PRESET_SUB)
        message ("[crisp] Another Subsystem has already defined.")
        message ("[crisp] Target Subsystem Count Must be 1")
        message (SEND_ERROR)
    endif()

    set(PRESET_SUB_LIBC ON PARENT_SCOPE)
    set(PRESET_SUB      ON PARENT_SCOPE)
    add_compile_definitions(PRESET_SUB_LIBC)
    add_compile_definitions(PRESET_SUB)
endfunction()

function   (sub_bare)
    if   (DEFINED PRESET_SUB)
        message ("[crisp] Another Subsystem has already defined.")
        message ("[crisp] Target Subsystem Count Must be 1")
        message (SEND_ERROR)
    endif()

    set(PRESET_SUB_BARE ON PARENT_SCOPE)
    set(PRESET_SUB      ON PARENT_SCOPE)
    add_compile_definitions(PRESET_SUB_BARE)
    add_compile_definitions(PRESET_SUB)
endfunction()