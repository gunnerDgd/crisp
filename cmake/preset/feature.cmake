function   (enable_collections)
    set                    (PRESET_FEATURE_COLLECTIONS ON PARENT_SCOPE)
    add_compile_definitions(PRESET_FEATURE_COLLECTIONS)
endfunction()

function   (enable_libc)
    set                    (PRESET_FEATURE_LIBC ON PARENT_SCOPE)
    add_compile_definitions(PRESET_FEATURE_LIBC)
endfunction()

function   (enable_thread)
    set                    (PRESET_FEATURE_THREAD ON PARENT_SCOPE)
    add_compile_definitions(PRESET_FEATURE_THREAD)
endfunction()