#include "task.h"
#include "sched.h"

#include <stdio.h>

void test(task* par, const char* par_str) { printf("Task Executed !! (Str : %s)\n", par_str); }

int main() {
	sched *sched = make(sched_t) from(0);
	task  *task1 = make(task_t)  from(2, test, "Task 1");
	task  *task2 = make(task_t)  from(2, test, "Task 2");
	task  *task3 = make(task_t)  from(2, test, "Task 3");

	sched_run (sched, task1);
	sched_run (sched, task2);
	sched_run (sched, task3); sched_susp(sched, task2);
	sched_exec(sched);

	sched_run (sched, task2);
	sched_exec(sched);
}