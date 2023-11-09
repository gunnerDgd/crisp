#include "task.h"
#include "sched.h"

#include <stdio.h>

void 
	test(sched* par, const char* par_str) { 
		printf("Task Executed !! (Str : %s)\n", par_str); 
}

void 
	async_main(sched* par, void* par_str)       {
		printf("Async Main Executed !!\n\n")    ;
		task* task1 = async(par, test, "Task 1");
		task* task2 = async(par, test, "Task 2");
		task* task3 = async(par, test, "Task 3");

		await(task2); printf("Await Completed\n");
		await(task1);
		await(task3);

		del(task1);
		del(task2);
		del(task3);
}

int main() {
	sched    *sched = make(sched_t) from(2, async_main, 0);
	while (sched_run(sched));
}