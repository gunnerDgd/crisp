#include <task.h>
#include <sched.h>
#include <mem.h>

#include <stdio.h>
#include <stdlib.h>

void* cstd_mem_new(mem* par, u64_t par_size) { return malloc(par_size); }
void  cstd_mem_del(mem* par, void* par_del)  { free(par_del); }

mem cstd_mem_res         = {
	.on_new = &cstd_mem_new,
	.on_del = &cstd_mem_del
};

void* test(task* par)                 {
    printf("Hello\n"); task_yield(par);
    printf("World\n"); task_yield(par);
    return "Hello World";
}

void* test2(task* par)                  {
    printf("Goodbye\n"); task_yield(par);
    printf("world\n")  ; task_yield(par);
    return "Goodbye World";
}

int main()                {
    set_mem(&cstd_mem_res);
    sched *run    = make (sched) from (0);
    fut   *task_1 = sched_dispatch (run, test , 0);
    fut   *task_2 = sched_dispatch (run, test2, 0);

    while (fut_poll(task_1) == fut_pend) sched_run(run);
    while (fut_poll(task_2) == fut_pend) sched_run(run);
    printf("%s ", (const char*) fut_ret(task_1));
    printf("%s" , (const char*) fut_ret(task_2));

    del(task_1);
    del(task_2);
    del(run)   ;
}