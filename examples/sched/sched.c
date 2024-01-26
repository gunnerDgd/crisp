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

int main()                {
    set_mem(&cstd_mem_res);
    sched* run = make (sched_t) from (2, 1 MB, &cstd_mem_res);
    task*  res = 0;

    sched_dispatch (run, test, 0);
    res = sched_run(run);
    res = sched_run(run);
    res = sched_run(run);
    printf("%s\n", task_ret(res));
}