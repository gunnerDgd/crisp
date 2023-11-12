#include "sched.h"
#include "details/sched.h"

obj_trait* sched_t = &__sched_trait;

bool_t 
	sched_run
		(sched* par) { 
			if (trait_of(par) != sched_t) return false_t;
			return __sched_run(par);
}

task*
	sched_curr
		(sched* par) { 
			if (trait_of(par) == sched_t)
				return __sched_curr (par); 
			return 0;
}

bool_t 
	sched_dispatch
		(sched* par, task* par_task) {
			if(trait_of(par)      != sched_t) return false_t;
			if(trait_of(par_task) != task_t)  return false_t;

			return __sched_dispatch(par, par_task);
}