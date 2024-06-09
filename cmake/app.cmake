function   (app NAME)
    add_executable (${NAME} ${ARGN})
    if   (PRESET_SUB_BARE)
    if   (PRESET_COMPILER_GCC)
        target_link_options (
            ${NAME} PRIVATE
            "-nostdinc"
            "-nostdinc++"
            "-nostdlib"
            "-nostdlib++"
            "-nodefaultlibs"
            "-nolibc"
        )
    endif()
    endif()
endfunction()