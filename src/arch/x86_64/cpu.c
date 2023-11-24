#include "cpu.h"
#include "../../alloc.h"

obj_trait __cpu_trait	  = {
	.on_new	  = &__cpu_new  ,
	.on_clone = &__cpu_clone,
	.on_ref   =			   0,
	.on_del	  = &__cpu_del  ,
	.size	  = sizeof(__cpu)
};

bool_t __cpu_new  (__cpu* par_cpu, u32_t par_count, va_list par) { return true_t ; }
bool_t __cpu_clone(__cpu* par, __cpu* par_clone)				 { return false_t; }
void   __cpu_del  (__cpu* par)									 {}