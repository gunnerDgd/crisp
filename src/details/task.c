#include "task.h"
#include "sched.h"

obj_trait __task_trait			        = {
	.init		   = &__task_init		  ,
	.init_as_clone = &__task_init_as_clone,
	.init_as_ref   =					 0,
	.deinit		   = &__task_deinit		  ,
	.size		   = &__task_size		  ,
	.name		   =					 0
};

void 
	__task_main
		(__task* par) {			  
			__cpu_switch(&par->cpu, &par->sched->curr->cpu);

			par->ret   = par->ent(par->sched, par->ent_arg);
			par->state = __task_state_stop				   ;
			
			if(par->ret_await)
				__sched_dispatch(par->sched, par->ret_await);

			__cpu_switch(&par->cpu, &par->sched->cpu);
}

bool_t 
	__task_init
		(__task* par_task, u32_t par_count, va_list par) {
			__sched *par_sched  = va_arg(par, __sched*);
			void    *par_fn	    = va_arg(par, void*)   ;
			void    *par_fn_arg = va_arg(par, void*)   ;
			alloc   *par_alloc  = (par_count == 4) ? va_arg(par, alloc*) : get_alloc();

			if (!par_sched->curr)						return false_t;
			if (!par_alloc)								return false_t;
			if (!__cpu_init(&par_task->cpu, par_alloc)) return false_t;

			par_task->ent      = par_fn    ;
			par_task->ent_arg  = par_fn_arg;

			par_task->ret       = 0;
			par_task->ret_await = 0;

			par_task->sched   = par_sched		;
			par_task->state   = __task_state_run;

			return __sched_dispatch(par_task->sched, par_task);
}
bool_t 
	__task_init_as_clone
		(__task* par, __task* par_clone) {
			return false_t;
}

void 
	__task_deinit
		(__task* par)				   {
			if(!par->sched)			   {
				__cpu_deinit(&par->cpu);
				return;
			}

			__cpu_deinit(&par->cpu);
			if (par->state == __task_state_run)  list_pop_at(&par->sched->exec, &par->sched_it);
			if (par->state == __task_state_susp) list_pop_at(&par->sched->susp, &par->sched_it);
			
			par->sched = 0;
}

u64_t
	__task_size() {
		return sizeof(__task);
}

void* 
	__task_wait
		(__task* par)							 {
			if (par == par->sched->curr) return 0;
			if (!par->sched->curr)		 return 0;

			par->ret_await			= par->sched->curr ;
			par->sched->curr->state = __task_state_susp;
			
			__cpu_switch(&par->sched->curr->cpu, &par->sched->cpu);
			void*  ret = par->ret	   ;
					     par->sched = 0;

			return ret;
}