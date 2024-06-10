if    (PRESET_SUB_BARE)
    if (PRESET_LINUX)
        lib                     (
            crisp-sub
            bare/linux/abi/call.h
            bare/linux/abi/int.h
            bare/linux/abi/arg.h
            bare/linux/abi/aux.h
            bare/linux/abi.h

            bare/linux/fs/perm.h
            bare/linux/fs/file.h
            bare/linux/fs/link.h
            bare/linux/fs/dir.h
            bare/linux/fs.h

            bare/linux/proc/exec.h
            bare/linux/proc/exit.h
            bare/linux/proc/fork.h
            bare/linux/proc.h

            bare/linux/std/lib.h
            bare/linux/std/io.h
            bare/linux/std.h

            bare/linux/print.c
            bare/linux/main.c
            bare/main.c
            bare/mem.c
        )

        target_include_directories(crisp-sub PRIVATE ../src)
        target_link_libraries     (crisp-sub PRIVATE crisp-core)
    endif()

    if   (PRESET_WIN32)
        lib                  (
            crisp-sub
            bare/win32/print.c
            bare/win32/main.c
            bare/main.c
            bare/mem.c
        )

        target_include_directories(crisp-sub PRIVATE ../src)
    endif()
elseif(DEFINED PRESET_SUB_LIBC)
    lib            (
        crisp-sub
        libc/print.c
        libc/main.c
        libc/mem.c
    )

    target_include_directories(crisp-sub PRIVATE ../src)
    target_link_libraries     (crisp-sub PRIVATE crisp-core)
endif ()