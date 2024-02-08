#include "cpu.h"

obj_trait cpu_trait	    = {
	.on_new	  = &cpu_new  ,
	.on_clone = &cpu_clone,
	.on_ref   =		     0,
	.on_del	  = &cpu_del  ,
	.size	  = sizeof(cpu)
};

obj_trait* cpu_t = &cpu_trait;

bool_t 
	cpu_new  
		(cpu* par_cpu, u32_t par_count, va_list par)				  {
			u32_t eip = 0; if (par_count > 0) eip = va_arg(par, u32_t);
			u32_t ecx = 0; if (par_count > 1) ecx = va_arg(par, u32_t);
			u32_t esp = 0; if (par_count > 2) esp = va_arg(par, u32_t);
			u32_t len = 0; if (par_count > 3) len = va_arg(par, u64_t);

			if (par_count == 0) return true_t ;
			if (par_count != 4) return false_t;
			par_cpu->reg.eip  = eip;
			par_cpu->reg.ecx  = ecx;
			par_cpu->reg.esp  = esp;
			par_cpu->reg.esp += len;
			return true_t; 
}

bool_t 
	cpu_clone
		(cpu* par, cpu* par_clone) { 
			return false_t; 
}

void   
	cpu_del  
		(cpu* par) {
			return;
}

void
	cpu_switch
		(cpu* par, cpu* par_cpu)				  {
			if (!par)						return;
			if (!par_cpu)					return;

			if (trait_of(par)     != cpu_t) return;
			if (trait_of(par_cpu) != cpu_t) return;
			if (par == par_cpu)			    return;

			cpu_do_switch(&par->reg, &par_cpu->reg);
}

void   
	cpu_stack
		(cpu* par, void* par_stack, u64_t par_len) {
			if (!par)					return;
			if (trait_of(par) != cpu_t) return;

			if (!par_stack)				return;
			if (!par_len)				return;
			par->reg.esp  = par_stack;
			par->reg.esp += par_len  ;
}

void   
	cpu_entry
		(cpu* par, void* par_entry)			  {
			if (!par)					return;
			if (trait_of(par) != cpu_t) return;
			par->reg.eip = par_entry;
}

void   
	cpu_arg
		(cpu* par, void* par_arg)			  {
			if (!par)					return;
			if (trait_of(par) != cpu_t) return;
#ifdef PRESET_WIN32
			par->reg.ecx = par_arg;
#elif PRESET_LINUX
            par->reg.edi = par_arg;
#endif
}