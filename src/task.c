#include "task.h"
#include "details/task.h"

obj_trait* task_t = &__task_trait;

void* task_wait(task* par) { return __task_wait(par); }
void  task_susp(task* par) {		__task_susp(par); }
void  task_resm(task* par) {		__task_resm(par); }