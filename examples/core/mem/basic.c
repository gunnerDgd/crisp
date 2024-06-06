#include <core.h>
#include <stdio.h>

struct test {
    u64_t a;
    u32_t b;
    u16_t c;
};

use()

int run()                               {
    struct test* test = new(struct test);
    test->a = 1; printf("test::a : %d\n", test->a);
    test->b = 2; printf("test::b : %d\n", test->b);
    test->c = 3; printf("test::c : %d\n", test->c);

    drop(test);
}