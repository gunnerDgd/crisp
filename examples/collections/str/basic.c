#include <core.h>
#include <collections.h>

#include <stdio.h>

int run ()                          {
    str* str_1 = make (str) from (0);
    str_push_back_cstr(str_1, "Hello", 5); printf("%s\n", str_ptr(str_1));
    str_push_back_cstr(str_1, "World", 5); printf("%s\n", str_ptr(str_1));
    str_push_cstr     (str_1, " ", 1 , 5); printf("%s\n", str_ptr(str_1));
    str_pop_back      (str_1, 6)         ; printf("%s\n", str_ptr(str_1));

    printf ("Compare : %s\n",
        (str_eq_cstr(str_1, "Hello", 5))
            ? "True"
            : "False"
    );
}