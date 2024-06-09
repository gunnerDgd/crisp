if    (PRESET_SUB_BARE)
    if (PRESET_LINUX)
        lib                  (
            crisp-sub
            bare/print_linux.c
            bare/main_linux.c
            bare/mem.c
        )
        target_link_libraries(crisp-sub PRIVATE crisp-core)
    endif()

    if   (PRESET_WIN32)
        lib                  (
            crisp-sub
            bare/print_win32.c
            bare/main_win32.c
            bare/mem.c
        )
    endif()
elseif(DEFINED PRESET_SUB_LIBC)
    lib            (
        crisp-sub
        libc/print.c
        libc/main.c
        libc/mem.c
    )
    target_link_libraries(crisp-sub PRIVATE crisp-core)
endif ()