#include "task.h"
#include "../../alloc.h"

bool_t 
	__task_obj_init
		(__task* par_task, u32_t par_count, va_list par) {
			void   (*par_fn)(void*) = va_arg(par, void*);
			void	*par_fn_arg	    = va_arg(par, void*);
			__alloc *par_alloc      =				   0;

			if (par_count == 3) 
				par_alloc = va_arg(par, __alloc*);

			if (!par_alloc) par_alloc = get_alloc();
			if (!par_alloc) return false_t;

			return __task_init(par_task, par_alloc, par_fn, par_fn_arg);
}

bool_t 
	__task_obj_init_as_clone
		(__task* par, __task* par_clone) {
			return __task_init_as_clone(par, par_clone);
}

void
	__task_obj_deinit
		(__task* par) {
			return __task_deinit(par);
}

u64_t  
	__task_obj_size() {
		return sizeof(__task);
}

__obj_trait __task_trait				    = {
	.init		   = &__task_obj_init		  ,
	.init_as_clone = &__task_obj_init_as_clone,
	.init_as_ref   =						 0,
	.deinit		   = &__task_obj_deinit		  ,
	.size		   = &__task_obj_size		  ,
	.name		   =						 0
};

bool_t 
	__task_init
		(__task* par, __alloc* par_alloc, void(*par_fn)(__task*, void*), void* par_fn_arg) {
			par->stack   = __mem_init(par_alloc, 4096 * 4);
			par->cur.rsp = par->stack->ptr + par->stack->alloc_size - 16;
			par->cur.rbp = par->cur.rsp								- 16;

			par->fn		= par_fn	    ;
			par->fn_arg = par_fn_arg    ;
			par->state  = __task_running;

			__task_start(&par->ret, &par->cur, __task_main, par);
			return true_t;
}
bool_t 
	__task_init_as_clone
		(__task* par, __task* par_clone) {
			par->stack  = __mem_init_as_clone(par_clone->stack);
			par->cur    = par_clone->cur;
			
			par->fn     = par_clone->fn    ;
			par->fn_arg = par_clone->fn_arg;
			par->stack  = __task_suspended ;

			__task_switch(&par->ret, &par->cur);
			return true_t;
}

void
	__task_deinit
		(__task* par) {
			while(par->state != __task_stopped)
				__task_switch(&par->ret, &par->cur);
}

void
	__task_main
		(__task* par) {
			par->state = __task_running;
			par->fn(par, par->fn_arg);

			par->state = __task_stopped;
			__task_switch(&par->cur, &par->ret);
}

bool_t 
	__task_run
		(__task* par) {
			if(par->state != __task_suspended)
				return false_t;

			par->state = __task_running  ; __task_switch(&par->ret, &par->cur);
			par->state = __task_suspended;

			return true_t;
}

bool_t 
	__task_yield
		(__task* par) {
			if(par->state != __task_running)
				return false_t;

			par->state = __task_suspended; __task_switch(&par->cur, &par->ret);
			par->state = __task_running  ;

			return true_t;
}