#include <core.h>
#include <thread.h>
#include <stdio.h>

use ()

void* world()        {
    printf("World\n");
}

void* hello()         {
    printf("Hello\n");
    fut     *fut_1 = async(world, null_t);
    fut_poll(fut_1);
    del     (fut_1);
}

int run()                                {
    fut     *fut_1 = async(hello, null_t);
    fut_poll(fut_1);
    del     (fut_1);
}