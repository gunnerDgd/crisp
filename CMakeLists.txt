cmake_minimum_required(VERSION 3.10)
add_subdirectory      (src)

if(PRESET_BUILD_EXAMPLES)
    include_directories(src)
    add_subdirectory   (examples)
endif()