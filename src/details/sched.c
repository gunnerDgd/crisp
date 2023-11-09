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
			void  *par_fn     = va_arg(par, void*);
			void  *par_fn_arg = va_arg(par, void*);
			alloc *par_alloc  = (par_count == 2) ? get_alloc() : va_arg(par, alloc*);

			if (!par_alloc)											  return false_t;
			if (!make_at(par_sched->exec, list_t) from(1, par_alloc)) return false_t;
			if (!make_at(par_sched->susp, list_t) from(1, par_alloc)) return false_t;

			par_sched->curr = &par_sched->main;
			return make_at(par_sched->main, &__task_trait) from (
				4			    , 
				par_sched		,
				par_fn		    ,
				par_fn_arg		,
				par_alloc
			);
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
	__sched_run
		(__sched* par) {
			if (list_empty(&par->exec)) return false_t;

			it      exec_it = list_begin(&par->exec);
			__task* exec    = get(exec_it)			; if (!exec) return false_t;
			
			par->curr = exec;
			__cpu_switch(&par->cpu, &exec->cpu);

			switch(exec->state)				     {
			case __task_state_stop				 :
				list_pop_at(&par->exec, &exec_it);
				break;
			case __task_state_susp:							     {
				it susp_it = list_push_back(&par->susp, exec)    ;
							 list_pop_at   (&par->exec, &exec_it);

				exec->sched_it = susp_it;
				break;
			}
			case __task_state_run:								{
				it run_it = list_push_back(&par->exec, exec)    ;
							list_pop_at   (&par->exec, &exec_it);

				exec->sched_it = run_it;
				break;
			}
			}


		par->curr = 0;
		return true_t;
}

bool_t 
	__sched_dispatch
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

			if (par_task == &par->main) __cpu_start(&par->cpu	   , &par_task->cpu, __task_main, par_task);
			else					    __cpu_start(&par->curr->cpu, &par_task->cpu, __task_main, par_task);

			return true_t;
}

__task* 
	__sched_curr
		(__sched* par) {
			return par->curr;
}