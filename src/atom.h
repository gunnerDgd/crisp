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

#endif
