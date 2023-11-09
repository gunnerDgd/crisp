#include "sched.h"
#include "details/sched.h"

obj_trait* sched_t = &__sched_trait;

bool_t 
	sched_run
		(sched* par, task* par_task) { 
			if (trait_of(par)      != sched_t) return false_t;
			if (trait_of(par_task) != task_t)  return false_t;
			
			return __sched_run(par, par_task);
}

void 
	sched_yield
		(sched* par) { 
			if (trait_of(par) == sched_t) 
				__sched_yield(par); 
}

task*
	sched_curr
		(sched* par) { 
			if (trait_of(par) == sched_t)
				return __sched_curr (par); 
			return 0;
}

bool_t 
	sched_exec
		(sched* par) { 
			if(trait_of(par) != sched_t)
				return false_t;

			return __sched_exec(par);
}

void
	sched_susp
		(sched* par, task* par_task) {
			if(trait_of(par)      != sched_t) return false_t;
			if(trait_of(par_task) != task_t)  return false_t;

			__sched_susp(par, par_task);
}