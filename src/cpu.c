#include "cpu.h"
#include "details-arch/cpu.h"

obj_trait* cpu_t = &__cpu_trait;

void 
	cpu_run
		(cpu* par, cpu* par_cur, void(*par_fn)(cpu*, void*), void* par_arg) {
			if (!par)						return;
			if (!par_cur)					return;

			if (trait_of(par)     != cpu_t) return;
			if (trait_of(par_cur) != cpu_t) return;

			__cpu_run(par, par_cur, par_fn, par_arg);
}

void 
	cpu_switch
		(cpu* par, cpu* par_cur)				  {
			if (!par)						return;
			if (!par_cur)					return;

			if (trait_of(par)     != cpu_t) return;
			if (trait_of(par_cur) != cpu_t) return;

			__cpu_switch(par, par_cur);
}