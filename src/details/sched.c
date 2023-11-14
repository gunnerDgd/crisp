#include "sched.h"
#include "task.h"

obj_trait __sched_trait				     = {
	.init		   = &__sched_init		   ,
	.init_as_clone = &__sched_init_as_clone,
	.init_as_ref   =					  0,
	.deinit		   = &__sched_deinit       ,
	.size		   = &__sched_size		   ,
	.name		   =					  0
};

bool_t 
	__sched_init
		(__sched* par_sched, u32_t par_count, va_list par) {
			alloc *par_alloc = (par_count == 0) ? get_alloc() : va_arg(par, alloc*);

			if (!par_alloc)											  return false_t;
			if (!make_at(par_sched->exec, list_t) from(1, par_alloc)) return false_t;
			if (!make_at(par_sched->susp, list_t) from(1, par_alloc)) return false_t;
			if (!make_at(par_sched->stop, list_t) from(1, par_alloc)) return false_t;
			if (!make_at(par_sched->cpu , cpu_t)  from(0))			  return false_t;

			par_sched->curr = 0;
			return true_t;
}

bool_t 
	__sched_init_as_clone
		(__sched* par, __sched* par_clone) {
			return false_t;
}

void
	__sched_deinit
		(__sched* par) {
			del(&par->exec);
			del(&par->susp);
			del(&par->stop);
}

u64_t
	__sched_size() {
		return sizeof(__sched);
}

bool_t 
	__sched_run
		(__sched* par)								  {
			if (list_empty(&par->exec)) return false_t;
			
			it exec = list_begin(&par->exec), exec_end = list_end(&par->exec);
			while(neq(exec, exec_end)) {
				__task* run = get(exec);
				if(!run)						  {
					list_pop_at(&par->exec, &exec);
					continue;
				}

				par->curr = run;
				cpu_switch(&par->cpu, &run->cpu);

				switch(run->state)							   {
				case __task_state_susp:						   {
					it susp = list_push_back(&par->susp, run)  ;
							  list_pop_at   (&par->exec, &exec);

					run->sched_it = susp;
					break;
				}
				case __task_state_stop:						   {
					it stop = list_push_back(&par->stop, run)  ;
							  list_pop_at	(&par->exec, &exec);

					run->sched_it = stop;
					break;
				}
				case __task_state_run:						   {
					next(exec);
					break;
				}
				}
			}

			par->curr = 0;
			return true_t;
}

bool_t 
	__sched_dispatch
		(__sched* par, __task* par_task)	   {
			if (par->curr)		 return false_t;
			if (par_task->sched) return false_t;

			par_task->state    = __task_state_run;
			par_task->sched    = par;
			par_task->sched_it = list_push_back(&par->exec, par_task);

			cpu_run(&par->cpu, &par_task->cpu, &__task_main, par_task);
			return true_t;
}

__task* 
	__sched_curr
		(__sched* par) {
			return par->curr;
}