#include "cpu.h"

obj_trait cpu_trait	    = {
	.on_new	  = &cpu_new  ,
	.on_clone = &cpu_clone,
	.on_ref   =		     0,
	.on_del	  = &cpu_del  ,
	.size	  = sizeof(cpu)
};

obj_trait* cpu_t = &cpu_trait;

bool_t cpu_new  (cpu* par_cpu, u32_t par_count, va_list par) { return true_t ; }
bool_t cpu_clone(cpu* par, cpu* par_clone)				     { return false_t; }
void   cpu_del  (cpu* par)								     {}

void
	cpu_switch
		(cpu* par, cpu* par_cpu) {
			if (!par)     return;
			if (!par_cpu) return;

			if (trait_of(par)     != cpu_t) return;
			if (trait_of(par_cpu) != cpu_t) return;

			__cpu_switch(&par->reg, &par_cpu->reg);
}

bool_t 
	cpu_get_reg
		(cpu* par, u16_t par_reg, reg* par_get)       {
			if (!par)					return false_t;
			if (trait_of(par) != cpu_t) return false_t;
			if (par_reg > cpu_r15)		return false_t;

			*par_get = par->reg.reg[par_reg];
			return true_t;
}

bool_t 
	cpu_get_reg8
		(cpu* par, u16_t par_reg, u8_t* par_get)      {
			if (!par)					return false_t;
			if (trait_of(par) != cpu_t) return false_t;
			if (par_reg > cpu_r15)		return false_t;

			*par_get = par->reg.reg[par_reg].r8;
			return true_t;
}

bool_t 
	cpu_get_reg16
		(cpu* par, u16_t par_reg, u16_t* par_get)     {
			if (!par)					return false_t;
			if (trait_of(par) != cpu_t) return false_t;
			if (par_reg > cpu_r15)		return false_t;

			*par_get = par->reg.reg[par_reg].r16;
			return true_t;
}

bool_t 
	cpu_get_reg32
		(cpu* par, u16_t par_reg, u32_t* par_get)     {
			if (!par)					return false_t;
			if (trait_of(par) != cpu_t) return false_t;
			if (par_reg > cpu_r15)		return false_t;

			*par_get = par->reg.reg[par_reg].r32;
			return true_t;
}

bool_t 
	cpu_get_reg64
		(cpu* par, u16_t par_reg, u64_t* par_get)     {
			if (!par)					return false_t;
			if (trait_of(par) != cpu_t) return false_t;
			if (par_reg > cpu_r15)		return false_t;

			*par_get = par->reg.reg[par_reg].r64;
			return true_t;
}

bool_t 
	cpu_set_reg
		(cpu* par, u16_t par_reg, reg par_set)        {
			if (!par)					return false_t;
			if (trait_of(par) != cpu_t) return false_t;
			if (par_reg > cpu_r15)		return false_t;

			par->reg.reg[par_reg] = par_set;
			return true_t;
}

bool_t 
	cpu_set_reg8
		(cpu* par, u16_t par_reg, u8_t par_set)      {
			if (!par)					return false_t;
			if (trait_of(par) != cpu_t) return false_t;
			if (par_reg > cpu_r15)		return false_t;

			par->reg.reg[par_reg].r8[0] = par_set;
			return true_t;
}

bool_t 
	cpu_set_reg16
		(cpu* par, u16_t par_reg, u16_t par_set)     {
			if (!par)					return false_t;
			if (trait_of(par) != cpu_t) return false_t;
			if (par_reg > cpu_r15)		return false_t;

			par->reg.reg[par_reg].r16[0] = par_set;
			return true_t;
}

bool_t 
	cpu_set_reg32
		(cpu* par, u16_t par_reg, u32_t par_set)     {
			if (!par)					return false_t;
			if (trait_of(par) != cpu_t) return false_t;
			if (par_reg > cpu_r15)		return false_t;

			par->reg.reg[par_reg].r32[0] = par_set;
			return true_t;
}

bool_t 
	cpu_set_reg64
		(cpu* par, u16_t par_reg, u64_t par_set)     {
			if (!par)					return false_t;
			if (trait_of(par) != cpu_t) return false_t;
			if (par_reg > cpu_r15)		return false_t;

			par->reg.reg[par_reg].r64 = par_set;
			return true_t;
}

bool_t 
	cpu_get_vreg
		(cpu* par, u16_t par_reg, vreg* par_get)      {
			if (!par)					return false_t;
			if (trait_of(par) != cpu_t) return false_t;
			if (par_reg > cpu_xmm7)		return false_t;

			*par_get = par->reg.xmm[par_reg];
			return true_t;
}

bool_t 
	cpu_set_vreg
		(cpu* par, u16_t par_reg, vreg* par_set)      {
			if (!par)					return false_t;
			if (trait_of(par) != cpu_t) return false_t;
			if (par_reg > cpu_xmm7)		return false_t;

			par->reg.xmm[par_reg] = *par_set;
			return true_t;
}