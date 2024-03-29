if   (PRESET_FEATURE_THREAD)
    add_compile_definitions(PRESET_FEATURE_THREAD)
    add_subdirectory       (thread)
endif()

if   (PRESET_FEATURE_LIBC)
    add_compile_definitions(PRESET_FEATURE_LIBC)
    add_subdirectory       (libc)
endif()

if   (PRESET_FEATURE_COLLECTIONS)
    add_compile_definitions(PRESET_FEATURE_COLLECTIONS)
    add_subdirectory       (collections)
endif()

add_subdirectory     (core)
add_library          (crisp STATIC main.c)
target_link_libraries(crisp crisp-core)

if   (PRESET_FEATURE_THREAD)
    target_link_libraries  (crisp crisp-thread)
endif()

if   (PRESET_FEATURE_LIBC)
    target_link_libraries  (crisp crisp-libc)
endif()

if   (PRESET_FEATURE_COLLECTIONS)
    target_link_libraries  (crisp crisp-collections)
endif()