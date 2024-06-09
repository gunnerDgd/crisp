#include <core.h>

use()

int run()                    {
    char* src = "Hello World";
    char* ops = "Hello";
    ord_t res;

    res = mem_ord(src, ops, 5);
    if (res == ord_eq) println ("eq");
    if (res == ord_gt) println ("gt");
    if (res == ord_lt) println ("lt");
    return 0;
}