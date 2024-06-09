#include <core.h>

use ()

void* world()       {
    println("World");
}

void* hello()       {
    println("Hello");
    fut     *fut_1 = async(world, null_t);
    fut_poll(fut_1);
    del     (fut_1);
}

int run()                                {
    fut     *fut_1 = async(hello, null_t);
    fut_poll(fut_1);
    del     (fut_1);
}