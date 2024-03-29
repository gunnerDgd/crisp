add_library(crisp-collections STATIC
    list.h
    list.c

    map.h
    map.c

    node.h
    node.c

    seq.h
    seq.c

    set.h
    set.c

    str.h
    str.c

    ../collections.h
)

add_library(crisp-collections-include STATIC
    ../../include/collections/list.h
    ../../include/collections/map.h
    ../../include/collections/node.h
    ../../include/collections/set.h
    ../../include/collections/str.h
    ../../include/collections/seq.h
    ../../include/collections.h
)

set_target_properties(crisp-collections-include PROPERTIES LINKER_LANGUAGE C)