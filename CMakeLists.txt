project(crisp)

include (${CMAKE_CURRENT_SOURCE_DIR}/cmake/preset.cmake)

preset_arch    ()
preset_bit     ()
preset_compiler()
preset_endian  ()
preset_os      ()

add_subdirectory(src)
if (PRESET_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()