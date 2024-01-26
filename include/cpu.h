#ifndef __CPU_H__
#define __CPU_H__

#ifdef PRESET_ARCH_X86_64
#include "obj.h"

extern obj_trait* cpu_t;
typedef struct    cpu { u8_t cpu[512]; } cpu;

void cpu_switch(cpu*, cpu*)        ;
void cpu_stack (cpu*, void*, u64_t);
void cpu_entry (cpu*, void*)	   ;
void cpu_arg   (cpu*, void*)	   ;

#endif
#endif