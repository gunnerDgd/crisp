lib                       (
    NAME crisp-collections
    SRC
    list.h
    list.c

    bma.h
    bma.c

    map.h
    map.c

    pos.h
    pos.c

    seq.h
    seq.c

    str.h
    str.c

    ../collections.h
)

inc                                (
    crisp-collections-include
    ../../include/collections/list.h
    ../../include/collections/map.h
    ../../include/collections/pos.h
    ../../include/collections/bma.h
    ../../include/collections/str.h
    ../../include/collections/seq.h
    ../../include/collections.h
)

link_libraries(crisp-collections)