project(crisp)

include (${CMAKE_CURRENT_SOURCE_DIR}/cmake/preset.cmake)
include (${CMAKE_CURRENT_SOURCE_DIR}/cmake/lib.cmake)
include (${CMAKE_CURRENT_SOURCE_DIR}/cmake/app.cmake)
include (${CMAKE_CURRENT_SOURCE_DIR}/cmake/inc.cmake)
include (${CMAKE_CURRENT_SOURCE_DIR}/cmake/asm.cmake)

add_arch    ()
add_compiler()
add_os      ()

if   (PRESET_BUILD_EXAMPLES)
    use_collections()

    sub_bare()
endif()

add_subdirectory(src)
if (PRESET_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()