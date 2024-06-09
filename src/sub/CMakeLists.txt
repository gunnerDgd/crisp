if    (PRESET_SUB_BARE)
    if (PRESET_LINUX)
        lib (crisp-sub
            bare/mem.c
            bare/linux.c
        )
        target_link_libraries(crisp-sub PRIVATE crisp-core)
    endif()

    if   (PRESET_WIN32)
        lib (crisp-sub
            bare/mem.c
            bare/win32.c
        )
    endif()
elseif(DEFINED PRESET_SUB_LIBC)
    lib (crisp-sub
        libc/main.c
        libc/mem.c
    )
    target_link_libraries(crisp-sub PRIVATE crisp-core)
endif ()