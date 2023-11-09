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
			alloc* par_alloc = (par_count == 0) ? get_alloc() : va_arg(par, alloc*);

			if (!par_alloc) 
				return false_t;
			if (!make_at(par_sched->exec, list_t) from(1, par_alloc)) 
				return false_t;
			if (!make_at(par_sched->susp, list_t) from(1, par_alloc)) 
				return false_t;

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
}

u64_t
	__sched_size() {
		return sizeof(__sched);
}

bool_t 
	__sched_exec	    
		(__sched* par) {
			it exec = list_begin(&par->exec), exec_end = list_end(&par->exec);
			if (list_empty(par))
				return false_t;

			while(neq(exec, exec_end))			  {
				__task* task = get(exec);
				if (!task)						  {
					list_pop_at(&par->curr, &exec);
					continue;
				}

				par->curr = task;
				__cpu_switch(&par->cpu, &task->cpu);

				if(task->state == __task_state_stop) {
					list_pop_at(&par->exec, &exec);
					task->sched = 0;
					continue	   ;
				}

				next(exec);
			}

			par->curr = 0;
			return true_t;
}

bool_t 
	__sched_run
		(__sched* par, __task* par_task) {
			if (par_task->sched && par_task->sched != par)
				return false_t;

			if (par_task->state == __task_state_stop)
				return false_t;
			if(par_task->state == __task_state_susp) {
				it exec_it = list_push_front(&par->exec, par_task)		     ;
							 list_pop_at    (&par->susp, &par_task->sched_it);

				par_task->state    = __task_state_run;
				par_task->sched_it = exec_it		 ;
				return true_t;
			}

			par_task->state    = __task_state_run;
			par_task->sched    = par;
			par_task->sched_it = list_push_front(&par->exec, par_task);
			
			__cpu_start(&par->cpu, &par_task->cpu, __task_main, par_task);
			return true_t;
}

void
	__sched_yield
		(__sched* par) {
			if(!par->curr) return;
			__cpu_switch(&par->curr->cpu, &par->cpu);
}

void
	__sched_susp
		(__sched* par, __task* par_task) {
			if (par_task->state != __task_state_run) return;
			if (par_task->sched != par)				 return;

			par_task->state = __task_state_susp;
			it susp_it = list_push_back(&par->susp, par_task)		    ;
						 list_pop_at   (&par->exec, &par_task->sched_it);

			par_task->sched_it = susp_it;
}

__task* 
	__sched_curr
		(__sched* par) {
			return par->curr;
}