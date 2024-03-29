#ifndef __BIT_H__
#define __BIT_H__

#include "type.h"

#define shl(par, par_shift)  ((par) << (par_shift))
#define shr(par, par_shift)  ((par) >> (par_shift))
#define test(par, par_shift) ((par) & shl(1, par_shift))
#define mask(par)            ((shl(1, par) - 1))

#if PRESET_ARCH_BIT >= 16
u16_t btc16     (u16_t*, u16_t);
u16_t bsf16     (u16_t)        ;
u16_t btr16     (u16_t*, u16_t);
u16_t bts16     (u16_t*, u16_t);
u16_t bsr16     (u16_t)        ;

u16_t lock_btc16(u16_t*, u16_t);
u16_t lock_btr16(u16_t*, u16_t);
u16_t lock_bts16(u16_t*, u16_t);
#endif

#if PRESET_ARCH_BIT >= 32
u32_t btc32     (u32_t*, u32_t);
u32_t bsf32     (u32_t)        ;
u32_t btr32     (u32_t*, u32_t);
u32_t bts32     (u32_t*, u32_t);
u32_t bsr32     (u32_t)        ;

u32_t lock_btc32(u32_t*, u32_t);
u32_t lock_btr32(u32_t*, u32_t);
u32_t lock_bts32(u32_t*, u32_t);
#endif

#if PRESET_ARCH_BIT >= 64
u64_t btc64     (u64_t*, u64_t);
u64_t bsf64     (u64_t)        ;
u64_t btr64     (u64_t*, u64_t);
u64_t bts64     (u64_t*, u64_t);
u64_t bsr64     (u64_t)        ;

u64_t lock_btc64(u64_t*, u64_t);
u64_t lock_btr64(u64_t*, u64_t);
u64_t lock_bts64(u64_t*, u64_t);
#endif

#if PRESET_ARCH_BIT == 64
#define btc(par, par_arg) btc64(((u64_t*)par), ((u64_t)par_arg))
#define bsf(par)          bsf64(((u64_t*)par))
#define btr(par, par_arg) btr64(((u64_t*)par), ((u64_t)par_arg))
#define bts(par, par_arg) bts64(((u64_t*)par), ((u64_t)par_arg))
#define bsr(par)          bsr64(((u64_t*)par))

#define lock_btc(par, par_arg) lock_btc64(((u64_t*)par), ((u64_t)par_arg))
#define lock_btr(par, par_arg) lock_btr64(((u64_t*)par), ((u64_t)par_arg))
#define lock_bts(par, par_arg) lock_bts64(((u64_t*)par), ((u64_t)par_arg))
#endif

#if PRESET_ARCH_BIT == 32
#define btc(par, par_arg) btc32(((u32_t*)par), ((u32_t)par_arg))
#define bsf(par)          bsf32(((u32_t*)par))
#define btr(par, par_arg) btr32(((u32_t*)par), ((u32_t)par_arg))
#define bts(par, par_arg) bts32(((u32_t*)par), ((u32_t)par_arg))
#define bsr(par)          bsr32(((u32_t*)par))

#define lock_btc(par, par_arg) lock_btc32(((u32_t*)par), ((u32_t)par_arg))
#define lock_btr(par, par_arg) lock_btr32(((u32_t*)par), ((u32_t)par_arg))
#define lock_bts(par, par_arg) lock_bts32(((u32_t*)par), ((u32_t)par_arg))
#endif

#if PRESET_ARCH_BIT == 16
#define btc(par, par_arg) btc16(((u16_t*)par), ((u16_t)par_arg))
#define bsf(par)          bsf16(((u16_t*)par))
#define btr(par, par_arg) btr16(((u16_t*)par), ((u16_t)par_arg))
#define bts(par, par_arg) bts16(((u16_t*)par), ((u16_t)par_arg))
#define bsr(par)          bsr16(((u16_t*)par))

#define lock_btc(par, par_arg) lock_btc16(((u16_t*)par), ((u16_t)par_arg))
#define lock_btr(par, par_arg) lock_btr16(((u16_t*)par), ((u16_t)par_arg))
#define lock_bts(par, par_arg) lock_bts16(((u16_t*)par), ((u16_t)par_arg))

#endif

#endif