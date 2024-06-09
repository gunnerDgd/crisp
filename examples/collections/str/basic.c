#include <core.h>
#include <collections.h>

use ()

int run ()                        {
    str* foo = make (str) from (0);
    str_push_back_cstr(foo, "Hello", 5); println("PUSH : %s", str_ptr(foo));
    str_push_back_cstr(foo, "World", 5); println("PUSH : %s", str_ptr(foo));
    str_push_cstr     (foo, " ", 1 , 5); println("PUSH : %s", str_ptr(foo));
    str_pop_back      (foo, 6)         ; println("POP : %s", str_ptr(foo));

    bool_t res = str_eq_cstr (foo, "Hello", 5);
    if (!res) println ("NOT EQUAL");
    else      println ("EQUAL");
    return 0;
}