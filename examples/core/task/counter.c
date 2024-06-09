#include <core.h>

use()

typedef struct num {
    obj   head ;
    u64_t count;
}   num;

bool_t num_new  (num* self, u32_t count, va_list arg) { self->count = 0; return true_t; }
bool_t num_clone(num* self, num* clone)               { return true_t; }
void   num_del  (num* self)                           {  }

obj_trait num_trait = make_trait (
    num_new    ,
    num_clone  ,
    null_t     ,
    num_del    ,
    sizeof(num),
    null_t
);

obj_trait *num_t = &num_trait;

u64_t
    num_do_poll
        (num* par)      {
            ++par->count;
            if (par->count >= 5)             {
                println ("num Ready !!");
                return fut_ready;
            }

            println ("Be Patient... (%d Remaining)", 5 - par->count);
            return fut_pend;
}

u64_t
    num_do_ret
        (num* par)           {
            return par->count;
}

fut_ops num_do = make_fut_ops (
    num_do_poll,
    num_do_ret
);

fut*
    num_fut
        (num* par)                 {
            return make (fut) from (
                2          ,
                &num_do,
                par
            );
}

void*
    test_1()                                    {
        num *count = make (num) from (0);
        fut     *fut   = num_fut(count);
        await(fut)  ;
        del  (count);
        del  (fut)  ;

        println("Finished !!");
}

int run()                                 {
    fut     *fut_1 = async(test_1, null_t);
    while (fut_poll(fut_1) == fut_pend)   {
        println("Polling Async Task...");
    }

    del(fut_1);
}