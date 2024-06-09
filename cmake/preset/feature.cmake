function   (use_collections)
    set                    (PRESET_FEATURE_COLLECTIONS ON PARENT_SCOPE)
    add_compile_definitions(PRESET_FEATURE_COLLECTIONS)
endfunction()

function   (use_thread)
    set                    (PRESET_FEATURE_THREAD ON PARENT_SCOPE)
    add_compile_definitions(PRESET_FEATURE_THREAD)
endfunction()