#include "coro.h"
#include "alloc.h"

__obj_trait __coro_trait				= {
	.init		   = &__coro_init_as_obj  ,
	.init_as_clone = &__coro_init_as_clone,
	.init_as_ref   =					 0,
	.deinit		   = &__coro_deinit		  ,
	.size		   = &__coro_size		  ,
	.name		   =					 0
};

u64_t
	__coro_size() {
		return sizeof(__coro);
}

void   
	__coro_main
		(__coro* par) {
			par->state = __coro_susp; __cpu_switch(&par->cpu_coro, &par->cpu);
			par->state = __coro_run ; par->ent(par, par->ent_arg);
			par->state = __coro_stop;

			__cpu_switch(&par->cpu_coro, &par->cpu);
}

bool_t 
	__coro_init
		(__coro* par, void(*par_fn)(__coro*, void*), void* par_arg, __alloc* par_alloc) {
			if(!par_alloc)
				return false_t;

			par->ent     = par_fn ;
			par->ent_arg = par_arg;

			if (!__cpu_init(&par->cpu_coro, par_alloc))
				return false_t;

			__cpu_start(&par->cpu, &par->cpu_coro, &__coro_main, par);
			return true_t;
}

bool_t 
	__coro_init_as_obj
		(__coro* par_coro, u32_t par_count, va_list par) {
			void    *fn     = va_arg(par, void*)									 ;
			void    *fn_arg = va_arg(par, void*)									 ;
			__alloc *alloc  = (par_count == 3) ? va_arg(par, __alloc*) : global_alloc;

			return __coro_init(par_coro, fn, fn_arg, alloc);
}

bool_t 
	__coro_init_as_clone
		(__coro* par, __coro* par_clone) {
			par->ent	 = par_clone->ent    ;
			par->ent_arg = par_clone->ent_arg;

			if (!__cpu_init(&par->cpu_coro, 0))
				return false_t;
			
			__cpu_start(&par->cpu, &par->cpu_coro, &__coro_main, par);
			return true_t;
}

void 
	__coro_deinit
		(__coro* par) {
			while(par->state == __coro_stop)
				__cpu_switch(&par->cpu, &par->cpu_coro);
}

void*
	__coro_yield		   
		(__coro* par, void* par_yield) {
			par->ret = par_yield;
			if (par->state == __coro_run) {
				par->state = __coro_susp; __cpu_switch(&par->cpu_coro, &par->cpu);
				par->state = __coro_run ;
			}
			else if (par->state == __coro_susp) {
				par->state = __coro_run ; __cpu_switch(&par->cpu, &par->cpu_coro);
				par->state = __coro_susp;
			}
			else
				return 0;

			return par->ret;
}