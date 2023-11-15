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
			
			if (par->ret_await)
				__task_resm(par->ret_await);

			cpu_switch(&par->cpu, &par->sched->cpu);
}

bool_t 
	__task_init
		(__task* par_task, u32_t par_count, va_list par) {
			__task* curr	  = va_arg(par, __task*);
			par_task->ent     = va_arg(par, void*); if (!par_task->ent) return 0;
			par_task->ent_arg = va_arg(par, void*);

			alloc* par_alloc = (par_count == 4) ? va_arg(par, alloc*) : get_alloc();
			if   (!par_alloc)
				return false_t;

			if (!make_at(par_task->cpu  , cpu_t)  from(1, par_alloc)) 
				return false_t;
			if (!make_at(par_task->child, list_t) from(1, par_alloc))
				return false_t;

			par_task->ret       = 0;
			par_task->ret_await = 0;
			par_task->state     = __task_state_run;

			if(!curr)			   {
				par_task->sched = 0;
				return true_t;
			}

			if(!curr->sched || curr->sched->curr != curr) {
				del(&par_task->cpu)  ;
				del(&par_task->child);

				return false_t;
			}

			par_task->sched    = ref(curr->sched)							 ;
			par_task->sched_it = list_push_back(&curr->sched->exec, par_task);
			  
			cpu_run(&curr->cpu, &par_task->cpu, __task_main, par_task);
			return true_t;
}

bool_t 
	__task_init_as_clone
		(__task* par, __task* par_clone) {
			return false_t;
}

void 
	__task_deinit
		(__task* par)					        {
			list_while(&par->child, child)      {
				__task*     wait = get(child)   ;
				__task_wait(wait);
				list_pop_at(&par->child, &child);
			}

			del(&par->cpu)  ;
			del(&par->child);

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
		(__task* par)										    {
			if (!par->sched)					 return		   0;
			if (!par->sched->curr)				 return		   0;

			if (par == par->sched->curr)		 return		   0;
			if (par->state == __task_state_stop) return par->ret;

			par->ret_await = par->sched->curr;
			__task_susp(par->sched->curr);

			void*  ret = par->ret;
			return ret;
}

void  
	__task_susp
		(__task* par)								   {
			if (par->state != __task_state_run)  return;
			if (par->sched->curr == par)			   {
				par->state			= __task_state_susp;
				cpu_switch(&par->cpu, &par->sched->cpu);
				
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