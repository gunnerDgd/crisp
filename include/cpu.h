#ifndef __CPU_H__
#define __CPU_H__

#ifdef PRESET_ARCH_X86_64
#include "obj.h"

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

#define cpu_xmm0 0
#define cpu_xmm1 1
#define cpu_xmm2 2
#define cpu_xmm3 3
#define cpu_xmm4 4
#define cpu_xmm5 5
#define cpu_xmm6 6
#define cpu_xmm7 7

typedef union reg {
	u64_t r64;
	u32_t r32[2];
	u16_t r16[4];
	u8_t  r8[8];
}	reg;

typedef union vreg {
	u128_t v128;
	u64_t  v64[2];
	u32_t  v32[4];
	u16_t  v16[8];
	u8_t   v8[16];
}	vreg;

extern obj_trait* cpu_t;
typedef struct    cpu { u8_t cpu[512]; } cpu;

void   cpu_switch   (cpu*, cpu*)		 ;
bool_t cpu_get_reg  (cpu*, u16_t, reg*)  ;
bool_t cpu_get_reg8 (cpu*, u16_t, u8_t *);
bool_t cpu_get_reg16(cpu*, u16_t, u16_t*);
bool_t cpu_get_reg32(cpu*, u16_t, u32_t*);
bool_t cpu_get_reg64(cpu*, u16_t, u64_t*);

bool_t cpu_set_reg  (cpu*, u16_t, reg)   ;
bool_t cpu_set_reg8 (cpu*, u16_t, u8_t)  ;
bool_t cpu_set_reg16(cpu*, u16_t, u16_t) ;
bool_t cpu_set_reg32(cpu*, u16_t, u32_t) ;
bool_t cpu_set_reg64(cpu*, u16_t, u64_t) ;

bool_t cpu_get_vreg (cpu*, u16_t, vreg*) ;
bool_t cpu_set_vreg (cpu*, u16_t, vreg*) ;

#endif
#endif