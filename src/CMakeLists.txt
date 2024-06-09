if   (PRESET_FEATURE_THREAD)
    add_compile_definitions(PRESET_FEATURE_THREAD)
    add_subdirectory       (thread)
endif()

if   (PRESET_FEATURE_COLLECTIONS)
    add_compile_definitions(PRESET_FEATURE_COLLECTIONS)
    add_subdirectory       (collections)
endif()

add_subdirectory(core)
add_subdirectory(sub)
add_library          (crisp INTERFACE)
target_link_libraries(crisp INTERFACE crisp-core)
target_link_libraries(crisp INTERFACE crisp-sub)

if   (PRESET_FEATURE_THREAD)
    target_link_libraries  (crisp INTERFACE crisp-thread)
endif()

if   (PRESET_FEATURE_COLLECTIONS)
    target_link_libraries  (crisp INTERFACE crisp-collections)
endif()