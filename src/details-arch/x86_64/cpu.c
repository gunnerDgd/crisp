#include "cpu.h"
#include "../../alloc.h"

obj_trait __cpu_trait				   = {
	.init		   = &__cpu_init		 ,
	.init_as_clone = &__cpu_init_as_clone,
	.init_as_ref   =					0,
	.deinit		   = &__cpu_deinit		 ,
	.size		   = &__cpu_size		 ,
	.name		   = 0
};

bool_t 
	__cpu_init
		(__cpu* par_cpu, u32_t par_count, va_list par) {
			if(par_count == 0)	    {
				par_cpu->ent	 = 0;
				par_cpu->ent_arg = 0;
				par_cpu->stack   = 0;

				return true_t;
			}

			alloc *par_alloc      = (par_count >= 1) ? va_arg(par, alloc*) : get_alloc();
			u64_t  par_alloc_size = (par_count == 2) ? va_arg(par, u64_t)  : 4096 * 8;
			
			if (!par_alloc)
				return false_t;

			par_cpu->stack = mem_init(par_alloc, par_alloc_size);
			if (!par_cpu->stack)
				return false_t;
			
			u64_t stack		 = ptr_raw(mem_ptr (par_cpu->stack))	;
			par_cpu->reg.rsp = stack + mem_size(par_cpu->stack) - 16;
			par_cpu->reg.rbp = par_cpu->reg.rsp;

			par_cpu->ent	 = 0;
			par_cpu->ent_arg = 0;

			return true_t;
}
bool_t 
	__cpu_init_as_clone
		(__cpu* par, __cpu* par_clone) {
			return false_t;
}

void
	__cpu_deinit
		(__cpu* par) {
			mem_deinit(par->stack);
}

void
	__cpu_run
		(__cpu* par, __cpu* par_cur, void(*par_fn)(__cpu*, void*), void* par_arg) {
			__asm_cpu_run    (
				&par    ->reg, 
				&par_cur->reg, 
				 par_fn		 ,
				 par_arg
			);
}

void
	__cpu_switch
		(__cpu* par, __cpu* par_cur) {
			__asm_cpu_switch(&par->reg, &par_cur->reg);
}

u64_t
	__cpu_size() {
		return sizeof(__cpu);
}