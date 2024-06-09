function   (inc NAME)
    add_library(${NAME} STATIC ${ARGN})
    set_target_properties             (
        ${NAME}
        PROPERTIES
        LINKER_LANGUAGE
        C
    )
endfunction()