#include <core.h>
#include <collections.h>

use ()

int run ()                        {
    str* foo = make (str) from (0);
    str_push_back(foo, "Hello", 5); println("PUSH : %s", str_ptr(foo));
    str_push_back(foo, "World", 5); println("PUSH : %s", str_ptr(foo));
    str_push     (foo, " ", 1 , 5); println("PUSH : %s", str_ptr(foo));
    str_pop_back (foo, 6)         ; println("POP : %s" , str_ptr(foo));

    bool_t res = eq_arg(foo, "Hello");
    if (!res) println ("NOT EQUAL");
    else      println ("EQUAL");
    return 0;
}