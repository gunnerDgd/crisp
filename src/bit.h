#ifndef __BIT_H__
#define __BIT_H__

#include "type.h"

#define shl(par, par_shift) (par << par_shift)
#define shr(par, par_shift) (par >> par_shift)
#define mask(par)           ((shl(1, par) - 1))

#if PRESET_ARCH_BIT >= 16
void  btc16     (u16_t*, u16_t);
u16_t bsf16     (u16_t)        ;
void  btr16     (u16_t*, u16_t);
void  bts16     (u16_t*, u16_t);
u16_t bsr16     (u16_t)        ;

void  lock_btc16(u16_t*, u16_t);
void  lock_btr16(u16_t*, u16_t);
void  lock_bts16(u16_t*, u16_t);
#endif

#if PRESET_ARCH_BIT >= 32
void  btc32     (u32_t*, u32_t);
u16_t bsf32     (u32_t)        ;
void  btr32     (u32_t*, u32_t);
void  bts32     (u32_t*, u32_t);
u16_t bsr32     (u32_t)        ;

void  lock_btc32(u32_t*, u32_t);
void  lock_btr32(u32_t*, u32_t);
void  lock_bts32(u32_t*, u32_t);
#endif

#if PRESET_ARCH_BIT >= 64
void  btc64     (u64_t*, u64_t);
u64_t bsf64     (u64_t)        ;
void  btr64     (u64_t*, u64_t);
void  bts64     (u64_t*, u64_t);
u64_t bsr64     (u64_t)        ;

void  lock_btc64(u64_t*, u64_t);
void  lock_btr64(u64_t*, u64_t);
void  lock_bts64(u64_t*, u64_t);
#endif

#endif