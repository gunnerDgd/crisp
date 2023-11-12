#ifndef __CPU_H__
#define __CPU_H__

#include "obj.h"

extern obj_trait* cpu_t;
typedef struct    cpu { u8_t cpu[512]; } cpu;

void cpu_run   (cpu*, cpu*, void(*)(cpu*, void*), void*);
void cpu_switch(cpu*, cpu*);

#endif