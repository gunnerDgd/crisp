#include "cpu.h"
#include "arch/cpu.h"

obj_trait* cpu_t = &__cpu_trait;

void 
	cpu_switch
		(cpu* par, cpu* par_cur)				  {
			if (!par)						return;
			if (!par_cur)					return;

			if (trait_of(par)     != cpu_t) return;
			if (trait_of(par_cur) != cpu_t) return;

			__cpu_switch(&((__cpu*)par)->reg, &((__cpu*)par_cur)->reg);
}

void
	cpu_reg_read
		(cpu* par, u16_t par_reg, u64_t* par_read) {
			if (!par)					return;
			if (trait_of(par) != cpu_t) return;
			if (par_reg > cpu_r15)		return;
			
			*par_read = ((__cpu*)par)->reg.reg[par_reg];
}

void  
	cpu_reg_write
		(cpu* par, u16_t par_reg, u64_t par_write) {
			if (!par)					return;
			if (trait_of(par) != cpu_t) return;
			if (par_reg > cpu_r15)		return;
			
			((__cpu*)par)->reg.reg[par_reg] = par_write;
}