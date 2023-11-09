#include "cpu.h"
#include "../../alloc.h"

bool_t 
	__cpu_init
		(__cpu* par, alloc* par_alloc) {
			par->stack = mem_init(par_alloc, 4096 * 4);
			if (!par->stack) return false_t;
			
			u64_t stack = ptr_raw(mem_ptr(par->stack));
			par->cpu.rsp = stack + mem_size(par->stack) - 16;
			par->cpu.rbp = par->cpu.rsp;

			par->ent	 = 0;
			par->ent_arg = 0;

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
	__cpu_start
		(__cpu* par, __cpu* par_next, void(*par_fn)(void*), void* par_arg) {
			__asm_cpu_start(&par->cpu, &par_next->cpu, par_fn, par_arg);
}

void
	__cpu_switch
		(__cpu* par, __cpu* par_next) {
			__asm_cpu_switch(&par->cpu, &par_next->cpu);
}