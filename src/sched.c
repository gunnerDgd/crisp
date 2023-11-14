#include "sched.h"
#include "details/sched.h"

obj_trait* sched_t = &__sched_trait;

bool_t 
	sched_run
		(sched* par) { 
			if (!par)					  return false_t;
			if (trait_of(par) != sched_t) return false_t;
			return __sched_run(par);
}

task*
	sched_curr
		(sched* par) { 
			if (!par)					  return 0;
			if (trait_of(par) != sched_t) return 0;
			
			return __sched_curr(par);
}

bool_t 
	sched_dispatch
		(sched* par, task* par_task)					    {
			if(!par)					      return false_t;
			if(!par_task)					  return false_t;

			if(trait_of(par)      != sched_t) return false_t;
			if(trait_of(par_task) != task_t)  return false_t;

			return __sched_dispatch(par, par_task);
}