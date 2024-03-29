#include <thread.h>
#include <core.h>

#include <stdio.h>

void test_1 ()              {
    printf("Hello Thread\n");
}

int run ()                                          {
    thd* thd_1 = make (thd) from (2, test_1, null_t);
    del (thd_1);
}