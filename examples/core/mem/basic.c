#include <core.h>

struct test {
    u64_t a;
    u32_t b;
    u16_t c;
};

use()

int run()                               {
    struct test* test = new(struct test);
    if (!test)                            {
        println("Memory Not Available !!");
        return 0;
    }

    test->a = 1; println("test::a : %d", test->a);
    test->b = 2; println("test::b : %d", test->b);
    test->c = 3; println("test::c : %d", test->c);

    drop(test);
}