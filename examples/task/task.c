#include "task.h"
#include <stdio.h>

void test(task* par_task, void* par) {
	printf("Hello ")	 ; yield(par_task);
	printf("World ")	 ; yield(par_task);
	printf("C ")		 ; yield(par_task);
	printf("Coroutine\n");
}

int main() {
	task* task = make(task_t) from(2, test, 0);
	run(task);
	run(task);
	run(task);
}