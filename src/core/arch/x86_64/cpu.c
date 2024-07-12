#include "cpu.h"

obj_trait cpu_trait	= make_trait (
	cpu_new    ,
	cpu_clone  ,
	null_t     ,
	cpu_del    ,
	sizeof(cpu),
	null_t
);

obj_trait* cpu_t = &cpu_trait;

bool_t 
	cpu_new  
		(cpu* par_cpu, u32_t par_count, va_list par)				  {
#ifdef PRESET_FFI_VECTORCALL
			u64_t rip = 0; if (par_count > 0) rip = va_arg(par, u64_t);
			u64_t rcx = 0; if (par_count > 1) rcx = va_arg(par, u64_t);
			u64_t rsp = 0; if (par_count > 2) rsp = va_arg(par, u64_t);
			u64_t len = 0; if (par_count > 3) len = va_arg(par, u64_t);

			if (par_count == 0) return true_t ;
			if (par_count != 4) return false_t;
			par_cpu->reg.rip  = rip;
			par_cpu->reg.rcx  = rcx;
			par_cpu->reg.rsp  = rsp;
			par_cpu->reg.rsp += len;
			return true_t; 
#elif  PRESET_FFI_SYSV
			u64_t rip = 0; if (par_count > 0) rip = va_arg(par, u64_t);
			u64_t rdi = 0; if (par_count > 1) rdi = va_arg(par, u64_t);
			u64_t rsp = 0; if (par_count > 2) rsp = va_arg(par, u64_t);
			u64_t len = 0; if (par_count > 3) len = va_arg(par, u64_t);
			if (par_count == 0)                                       {
                cpu_do_get(&par_cpu->reg);
                return true_t            ;
            }

			if (par_count != 4) return false_t;
			par_cpu->reg.rip  = rip;
			par_cpu->reg.rdi  = rdi;
			par_cpu->reg.rsp  = rsp;
			par_cpu->reg.rsp += len;
			return true_t; 
#endif
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
			if (trait_of(par)     != cpu_t) return;
			if (trait_of(par_cpu) != cpu_t) return;
			if (par == par_cpu)			    return;

			cpu_do_switch(&par->reg, &par_cpu->reg);
}

void   
	cpu_stack
		(cpu* par, void* par_stack, u64_t par_len) {
			if (trait_of(par) != cpu_t) return;
			if (!par_stack)             return;
            if (!par_len)	            return;

			par->reg.rsp  = (u64_t) par_stack;
			par->reg.rsp += par_len;
}

void   
	cpu_entry
		(cpu* par, void* par_entry)			  {
			if (trait_of(par) != cpu_t) return;
			par->reg.rip = (u64_t) par_entry;
}

void   
	cpu_arg
		(cpu* par, void* par_arg)			  {
			if (trait_of(par) != cpu_t) return;
#ifdef PRESET_WIN32
			par->reg.rcx = par_arg;
#elif PRESET_LINUX
            par->reg.rdi = (u64_t) par_arg;
#endif
}