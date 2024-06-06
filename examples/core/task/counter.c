#include <core.h>
#include <stdio.h>

use()

typedef struct counter {
    obj   head ;
    u64_t count;
}   counter;

bool_t counter_new  (counter* par_counter, u32_t par_count, va_list par) { par_counter->count = 0; return true_t; }
bool_t counter_clone(counter* par, counter* par_clone)                   { return true_t; }
void   counter_del  (counter* par)                                       {  }

obj_trait counter_trait = make_trait (
    counter_new    ,
    counter_clone  ,
    null_t         ,
    counter_del    ,
    sizeof(counter),
    null_t
);

obj_trait *counter_t = &counter_trait;

u64_t
    counter_do_poll
        (counter* par)  {
            ++par->count;
            if (par->count >= 5)             {
                printf ("Counter Ready !!\n");
                return fut_ready;
            }

            printf ("Be Patient... (%d Remaining)\n", 5 - par->count);
            return fut_pend;
}

u64_t
    counter_do_ret
        (counter* par)       {
            return par->count;
}

fut_ops counter_do = make_fut_ops (
    counter_do_poll,
    counter_do_ret
);

fut*
    counter_fut
        (counter* par)             {
            return make (fut) from (
                2          ,
                &counter_do,
                par
            );
}

void*
    test_1()                                    {
        counter *count = make (counter) from (0);
        fut     *fut   = counter_fut(count);
        await(fut)  ;
        del  (count);
        del  (fut)  ;

        printf("Finished !!");
}

int run()                                 {
    fut     *fut_1 = async(test_1, null_t);
    while (fut_poll(fut_1) == fut_pend)   {
        printf("Polling Async Task...\n");
    }

    del(fut_1);
}