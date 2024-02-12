#ifndef __ATOM_H__
#define __ATOM_H__

#include "type.h"

u8_t lock_add8(u8_t*, u8_t);
u8_t lock_sub8(u8_t*, u8_t);
u8_t lock_inc8(u8_t*);
u8_t lock_dec8(u8_t*);

u8_t cas_inc8(u8_t*);
u8_t cas_dec8(u8_t*);
u8_t cas8    (u8_t*, u8_t, u8_t);
u8_t xchg8   (u8_t*, u8_t);

u8_t lock_cas_inc8(u8_t*);
u8_t lock_cas_dec8(u8_t*);
u8_t lock_cas8    (u8_t*, u8_t, u8_t);
u8_t lock_xchg8   (u8_t*, u8_t);

#if PRESET_ARCH_BIT >= 16
u16_t lock_add16(u16_t*, u16_t);
u16_t lock_sub16(u16_t*, u16_t);
u16_t lock_inc16(u16_t*);
u16_t lock_dec16(u16_t*);

u16_t cas_inc16(u16_t*);
u16_t cas_dec16(u16_t*);
u16_t cas16    (u16_t*, u16_t, u16_t);
u16_t xchg16   (u16_t*, u16_t);

u16_t lock_cas_inc16(u16_t*);
u16_t lock_cas_dec16(u16_t*);
u16_t lock_cas16    (u16_t*, u16_t, u16_t);
u16_t lock_xchg16   (u16_t*, u16_t);
#endif

#if PRESET_ARCH_BIT >= 32
u32_t lock_add32(u32_t*, u32_t);
u32_t lock_sub32(u32_t*, u32_t);
u32_t lock_inc32(u32_t*);
u32_t lock_dec32(u32_t*);

u32_t cas_inc32(u32_t*);
u32_t cas_dec32(u32_t*);
u32_t cas32    (u32_t*, u32_t, u32_t);
u32_t xchg32   (u32_t*, u32_t);

u32_t lock_cas_inc32(u32_t*);
u32_t lock_cas_dec32(u32_t*);
u32_t lock_cas32    (u32_t*, u32_t, u32_t);
u32_t lock_xchg32   (u32_t*, u32_t);
#endif

#if PRESET_ARCH_BIT >= 64
u64_t lock_add64(u64_t*, u64_t);
u64_t lock_sub64(u64_t*, u64_t);
u64_t lock_inc64(u64_t*);
u64_t lock_dec64(u64_t*);

u64_t cas_inc64(u64_t*);
u64_t cas_dec64(u64_t*);
u64_t cas64    (u64_t*, u64_t, u64_t);
u64_t xchg64   (u64_t*, u64_t);

u64_t lock_cas_inc64(u64_t*);
u64_t lock_cas_dec64(u64_t*);
u64_t lock_cas64    (u64_t*, u64_t, u64_t);
u64_t lock_xchg64   (u64_t*, u64_t);
#endif

#if PRESET_ARCH_BIT == 64
#define lock_add_ptr(par, par_arg) lock_add64(((u64_t*)(par)), ((u64_t)(par_arg)))
#define lock_sub_ptr(par, par_arg) lock_sub64(((u64_t*)(par)), ((u64_t)(par_arg))
#define lock_inc_ptr(par)          lock_inc64(((u64_t*)(par)))
#define lock_dec_ptr(par)          lock_dec64(((u64_t*)(par)))

#define cas_inc_ptr(par)                  cas_inc64(((u64_t*)(par)))
#define cas_dec_ptr(par)                  cas_dec64(((u64_t*)(par)))
#define cas_ptr(par, par_expect, par_arg) cas64    (((u64_t*)(par)), ((u64_t)(par_expect)), ((u64_t)(par_arg)))
#define xchg_ptr(par, par_arg)            xchg64   (((u64_t*)(par)), ((u64_t)(par_arg)))

#define lock_cas_inc_ptr(par)                  lock_cas_inc64(((u64_t*)(par)))
#define lock_cas_dec_ptr(par)                  lock_cas_dec64(((u64_t*)(par)))
#define lock_cas_ptr(par, par_expect, par_arg) lock_cas64    (((u64_t*)(par)), ((u64_t)(par_expect)), ((u64_t)(par_arg)))
#define lock_xchg_ptr(par, par_arg)            lock_xchg64   (((u64_t*)(par)), ((u64_t)(par_arg)))
#endif

#if PRESET_ARCH_BIT == 32
#define lock_add_ptr(par, par_arg) lock_add32(((u32_t*)(par)), ((u32_t)(par_arg)))
#define lock_sub_ptr(par, par_arg) lock_sub32(((u32_t*)(par)), ((u32_t)(par_arg)))
#define lock_inc_ptr(par)          lock_inc32(((u32_t*)(par)), ((u32_t)(par_arg)))
#define lock_dec_ptr(par)          lock_dec32(((u32_t*)(par)), ((u32_t)(par_arg)))

#define cas_inc_ptr(par)                  cas_inc32(((u32_t*)(par)))
#define cas_dec_ptr(par)                  cas_dec32(((u32_t*)(par)))
#define cas_ptr(par, par_expect, par_arg) cas32    (((u32_t*)(par)), ((u32_t)(par_expect)), ((u32_t)(par_arg)))
#define xchg_ptr(par, par_arg)            xchg32   (((u32_t*)(par)), ((u32_t)(par_arg)))

#define lock_cas_inc_ptr(par)                  lock_cas_inc32(((u32_t*)(par)))
#define lock_cas_dec_ptr(par)                  lock_cas_dec32(((u32_t*)(par)))
#define lock_cas_ptr(par, par_expect, par_arg) lock_cas32    (((u32_t*)(par)), ((u32_t)(par_expect)), ((u32_t)(par_arg)))
#define lock_xchg_ptr(par, par_arg)            lock_xchg32   (((u32_t*)(par)), ((u32_t)(par_arg)))
#endif

#if PRESET_ARCH_BIT == 16
#define lock_add_ptr(par, par_arg) lock_add16(((u16_t*)(par)), ((u16_t)(par_arg)))
#define lock_sub_ptr(par, par_arg) lock_sub16(((u16_t*)(par)), ((u16_t)(par_arg)))
#define lock_inc_ptr(par)          lock_inc16(((u16_t*)(par)), ((u16_t)(par_arg)))
#define lock_dec_ptr(par)          lock_dec16(((u16_t*)(par)), ((u16_t)(par_arg)))

#define cas_inc_ptr(par)                  cas_inc16(((u16_t*)(par)))
#define cas_dec_ptr(par)                  cas_dec16(((u16_t*)(par)))
#define cas_ptr(par, par_expect, par_arg) cas16    (((u16_t*)(par)), ((u16_t)(par_expect)), ((u16_t)(par_arg)))
#define xchg_ptr(par, par_arg)            xchg16   (((u16_t*)(par)), ((u16_t)(par_arg)))

#define lock_cas_inc_ptr(par)                  lock_cas_inc16(((u16_t*)(par)))
#define lock_cas_dec_ptr(par)                  lock_cas_dec16(((u16_t*)(par)))
#define lock_cas_ptr(par, par_expect, par_arg) lock_cas16    (((u16_t*)(par)), ((u16_t)(par_expect)), ((u16_t)(par_arg)))
#define lock_xchg_ptr(par, par_arg)            lock_xchg16   (((u16_t*)(par)), ((u16_t)(par_arg)))
#endif

#endif
