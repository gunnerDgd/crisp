macro   (crisp_collections)
    set                    (PRESET_FEATURE_COLLECTIONS ON PARENT_SCOPE)
    add_compile_definitions(PRESET_FEATURE_COLLECTIONS)
endmacro()

macro   (crisp_thread)
    set                    (PRESET_FEATURE_THREAD ON PARENT_SCOPE)
    add_compile_definitions(PRESET_FEATURE_THREAD)
endmacro()