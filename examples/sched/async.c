#include "task.h"
#include "sched.h"

#include <stdio.h>

typedef struct test_par {
	const char* str;
	u64_t	    u64;
}	test_par;

void*
	test(task* par_task, test_par* par) {
		printf("Task Executed !! (Str : %s)\n", par->str);
		return par->u64;
}

void 
	async_main(task* par, void* par_str)        {
		printf("Async Main Executed !!\n\n")    ;

		test_par par1 = { .str = "Task 1", .u64 = 1 },
				 par2 = { .str = "Task 2", .u64 = 2 },
				 par3 = { .str = "Task 3", .u64 = 3 };

		task* task1 = async(par, test, &par1);
		task* task2 = async(par, test, &par2);
		task* task3 = async(par, test, &par3);

		printf("Await Completed (Value : %d)\n", await(task2));
		printf("Await Completed (Value : %d)\n", await(task1));
		printf("Await Completed (Value : %d)\n", await(task3));

		del(task1);
		del(task2);
		del(task3);
}

int main() {
	sched *sched	  = make(sched_t) from(0);
	task  *sched_main = make(task_t)  from (3, NULL, async_main, 0);

	sched_dispatch(sched, sched_main);
	while (sched_run(sched));

	del(sched_main);
	del(sched)	   ;
}