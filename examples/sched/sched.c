#include "sched.h"
#include "task.h"

#include <stdio.h>

void*
	test(task* par_sched, void* par) {
		printf("Print : %s\n", par);
		return 0;
}

void
	async_main(task* par_task, void* par) {
		task* task1 = async(test, "Task 1", par_task);
		task* task2 = async(test, "Task 2", par_task);
		susp (task1);
		await(task2);
		printf("Task 2 Completed\n");

		resm (task1);
		await(task1);

		del(task1);
		del(task2);
		printf("async_main Completed\n");
}

int main() {
	sched *sched     = make(sched_t) from(0)			   ;
	task  *main_task = make(task_t)  from(2, async_main, 0);

	sched_dispatch(sched, main_task);
	while (sched_run(sched))
		printf("Executor\n");
}