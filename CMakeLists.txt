cmake_minimum_required(VERSION 3.10)
project               (crisp-all)
include_directories   (${CMAKE_SOURCE_DIR})

option(CRISP_PRESET_LINUX OFF)
option(CRISP_PRESET_WIN32 OFF)

if(CRISP_PRESET_LINUX)
    add_subdirectory(crisp-build/linux)
endif()