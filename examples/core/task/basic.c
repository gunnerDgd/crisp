#include <core/task.h>
#include <core/mem.h>

#include <stdio.h>

void* test2()        {
    printf("World\n");
}

void* test()         {
    printf("Hello\n");
    fut     *fut_1 = async(test2, null_t);
    fut_poll(fut_1);
    del     (fut_1);
}

int run()                               {
    fut     *fut_1 = async(test, null_t);
    fut_poll(fut_1);
    del     (fut_1);
}