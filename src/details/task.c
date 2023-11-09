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
			__cpu_switch(&par->cpu, &par->sched->cpu);

			par->ent(par, par->ent_arg)   ;
			par->state = __task_state_stop;
			
			__cpu_switch(&par->cpu, &par->sched->cpu);
}

bool_t 
	__task_init
		(__task* par_task, u32_t par_count, va_list par) {
			void  *par_fn	  = va_arg(par, void*);
			void  *par_fn_arg = va_arg(par, void*);
			alloc *par_alloc  = (par_count == 3) ? va_arg(par, alloc*) : get_alloc();

			if (!par_alloc)								return false_t;
			if (!__cpu_init(&par_task->cpu, par_alloc)) return false_t;

			par_task->ent     =       par_fn    ;
			par_task->ent_arg =       par_fn_arg;
			par_task->sched   =				   0;
			par_task->state   = __task_state_run;

			return true_t;
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
			if (par->state == __task_state_run)  
				list_pop_at(&par->sched->exec, &par->sched_it);
			if (par->state == __task_state_susp) 
				list_pop_at(&par->sched->susp, &par->sched_it);
			
			par->sched = 0;
}

u64_t
	__task_size() {
		return sizeof(__task);
}