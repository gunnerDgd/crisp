#include "task.h"
#include <stdio.h>

void test(task* par_task, void* par) {
	printf("Hello ")	 ; task_yield(par_task);
	printf("World ")	 ; task_yield(par_task);
	printf("C ")		 ; task_yield(par_task);
	printf("Coroutine\n");
}

int main() {
	task* task = make(task_t) from(2, test, 0);
	task_run(task);
	task_run(task);
	task_run(task);
}