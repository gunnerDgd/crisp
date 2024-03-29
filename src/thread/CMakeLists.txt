if   (PRESET_WIN32)
    add_library (crisp-thread STATIC
        win32/thd.h
        win32/thd.c

        thd.h
    )
endif()

if   (PRESET_LINUX)
    add_library (crisp-thread STATIC
        linux/thd.h
        linux/thd.c

        linux/mtx.h
        linux/mtx.c

        thd.h
        mtx.h

        ../thread.h
    )
endif()

add_library(crisp-thread-include STATIC
        ../../include/thread/thd.h
        ../../include/thread/mtx.h
        ../../include/thread.h
)

set_target_properties(crisp-thread-include PROPERTIES LINKER_LANGUAGE C)