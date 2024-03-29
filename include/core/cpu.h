#ifndef __CPU_H__
#define __CPU_H__

#ifdef PRESET_ARCH_X86_64
#include "obj.h"

extern obj_trait* cpu_t;
typedef struct    cpu { u8_t cpu[512]; } cpu;

#endif
#endif