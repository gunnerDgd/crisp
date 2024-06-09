if   (NOT DEFINED PRESET_OS)
    message("[crisp] Target OS is not defined.")
    message("[crisp] thread feature requires OS preset definition.")
    message(SEND_ERROR)
endif()

if   (PRESET_WIN32)
    lib (crisp-thread
        win32/thd.h
        win32/thd.c

        win32/mtx.h
        win32/mtx.c

        thd.h
        mtx.h

        ../thread.h
        ../thread.c
    )
endif()

if   (PRESET_LINUX)
    lib (crisp-thread
        linux/thd.h
        linux/thd.c

        linux/mtx.h
        linux/mtx.c

        thd.h
        mtx.h

        ../thread.h
        ../thread.c
    )
endif()

inc                           (
    crisp-thread-include
    ../../include/thread/thd.h
    ../../include/thread/mtx.h
    ../../include/thread.h
)