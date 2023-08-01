project(crisp-linux)
option (CRISP_PRESET_ARCH_X86_64 OFF)

if(CRISP_PRESET_ARCH_X86_64)
    add_subdirectory(x86_64)
endif ()