project(crisp)

add_subdirectory(src)
if (PRESET_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()