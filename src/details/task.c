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
		(cpu* par_cpu, __task* par)										      {
			if(par->sched->curr) cpu_switch(&par->cpu, &par->sched->curr->cpu);
			else			     cpu_switch(&par->cpu, &par->sched->cpu)	  ;

			par->ret   = par->ent(par, par->ent_arg);
			par->state = __task_state_stop		    ;
			
			if (par->ret_await) {
				it exec = list_push_back(&par->sched->exec, par->ret_await);
						  list_pop_at   (&par->sched->susp, &par->sched_it);

				par->sched_it = exec;
			}

			cpu_switch(&par->cpu, &par->sched->cpu);
}

bool_t 
	__task_init
		(__task* par_task, u32_t par_count, va_list par) {
			void   *par_fn	   = va_arg(par, void*)  ;
			void   *par_fn_arg = va_arg(par, void*)  ;
			__task *par_curr   = (par_count >= 3) ? va_arg(par, __task*) : 0		  ;
			alloc  *par_alloc  = (par_count == 4) ? va_arg(par, alloc*)  : get_alloc();

			if (par_curr && !par_curr->sched)
				return false_t;
			if (par_curr &&  par_curr->sched->curr != par_curr)
				return false_t;
			
			if (!par_alloc)										   return false_t;
			if (!make_at(par_task->cpu, cpu_t) from(1, par_alloc)) return false_t;

			par_task->ent       = par_fn    ;
			par_task->ent_arg   = par_fn_arg;

			par_task->ret       = 0;
			par_task->ret_await = 0;
			par_task->state     = __task_state_run;

			if (!par_curr)		   {
				par_task->sched = 0;
				return true_t;
			}

			par_task->sched    = ref(par_curr->sched);
			par_task->sched_it = list_push_back(&par_curr->sched->exec, par_task);

			cpu_run(&par_curr->cpu, &par_task->cpu, __task_main, par_task);
			return true_t;
}

bool_t 
	__task_init_as_clone
		(__task* par, __task* par_clone) {
			return false_t;
}

void 
	__task_deinit
		(__task* par)	    {
			del(&par->cpu)  ;
			if (par->sched && par->state == __task_state_run)  
				list_pop_at(&par->sched->exec, &par->sched_it);
			if (par->sched && par->state == __task_state_susp) 
				list_pop_at(&par->sched->susp, &par->sched_it);
			if (par->sched)
				del(par->sched);
}

u64_t
	__task_size()			 {
		return sizeof(__task);
}

void* 
	__task_wait
		(__task* par)									{
			if (!par->sched)					return 0;
			if (!par->sched->curr)				return 0;
			if (par == par->sched->curr)		return 0;
			if (par->state != __task_state_run) return 0;

			par->ret_await			= par->sched->curr ;
			par->sched->curr->state = __task_state_susp;
			
			cpu_switch(&par->sched->curr->cpu, &par->sched->cpu);
			void*  ret = par->ret	      ;
					     par->sched = 0   ;

			return ret;
}

void  
	__task_susp
		(__task* par)									 {
			if (par->state != __task_state_run)    return;
			if (par->sched->curr == par)			     {
				par->state			  = __task_state_susp;
				cpu_switch(&par->cpu, &par->sched->cpu)  ;
				
				return;
			}

			__sched* sched   = par->sched;
			it		 susp_it = list_push_back(&sched->susp, par)		   ;
							   list_pop_at   (&sched->exec, &par->sched_it);

			par->sched_it = susp_it			 ;
			par->state    = __task_state_susp;
			return;
}

void 
	__task_resm
		(__task* par)			 					   {
			if (par->sched->curr == par)		 return;
			if (par->state != __task_state_susp) return;
			
			__sched* sched   = par->sched;
			it	     exec_it = list_push_front(&sched->exec, par)			;
							   list_pop_at    (&sched->susp, &par->sched_it);

			par->state    = __task_state_run;
			par->sched_it = exec_it		    ;
}