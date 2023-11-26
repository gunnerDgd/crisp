#ifndef __CPU_H__
#define __CPU_H__

#include "obj.h"

#ifdef PRESET_ARCH_X86_64
#define cpu_rax 0
#define cpu_rbx 1
#define cpu_rcx 2
#define cpu_rdx 3

#define cpu_rsi 4
#define cpu_rdi 5
#define cpu_rsp 6
#define cpu_rbp 7
#define cpu_rip 8

#define cpu_r8  9
#define cpu_r9  10
#define cpu_r10 11
#define cpu_r11 12

#define cpu_r12 13
#define cpu_r13 14
#define cpu_r14 15
#define cpu_r15 16
#endif

extern obj_trait* cpu_t;
typedef struct    cpu { u8_t cpu[512]; } cpu;

void cpu_switch   (cpu*, cpu*)         ;
void cpu_reg_read (cpu*, u16_t, u64_t*);
void cpu_reg_write(cpu*, u16_t, u64_t) ;

#endif