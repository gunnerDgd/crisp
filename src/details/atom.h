#ifndef __DETAILS_ATOM_H__
#define __DETAILS_ATOM_H__

#include "../type_atom.h"

atom_u8_t  __lock_add8 (atom_u8_t *, atom_u8_t);
atom_u16_t __lock_add16(atom_u16_t*, atom_u16_t);
atom_u32_t __lock_add32(atom_u32_t*, atom_u32_t);
atom_u64_t __lock_add64(atom_u64_t*, atom_u64_t);

atom_u8_t  __lock_sub8 (atom_u8_t *, atom_u8_t);
atom_u16_t __lock_sub16(atom_u16_t*, atom_u16_t);
atom_u32_t __lock_sub32(atom_u32_t*, atom_u32_t);
atom_u64_t __lock_sub64(atom_u64_t*, atom_u64_t);

atom_u8_t  __lock_inc8 (atom_u8_t *);
atom_u16_t __lock_inc16(atom_u16_t*);
atom_u32_t __lock_inc32(atom_u32_t*);
atom_u64_t __lock_inc64(atom_u64_t*);

atom_u8_t  __lock_dec8 (atom_u8_t *);
atom_u16_t __lock_dec16(atom_u16_t*);
atom_u32_t __lock_dec32(atom_u32_t*);
atom_u64_t __lock_dec64(atom_u64_t*);

atom_u8_t  __lock_cas8 (atom_u8_t *, atom_u8_t , atom_u8_t);
atom_u16_t __lock_cas16(atom_u16_t*, atom_u16_t, atom_u16_t);
atom_u32_t __lock_cas32(atom_u32_t*, atom_u32_t, atom_u32_t);
atom_u64_t __lock_cas64(atom_u64_t*, atom_u64_t, atom_u64_t);

atom_u8_t  __lock_xchg8 (atom_u8_t *, atom_u8_t);
atom_u16_t __lock_xchg16(atom_u16_t*, atom_u16_t);
atom_u32_t __lock_xchg32(atom_u32_t*, atom_u32_t);
atom_u64_t __lock_xchg64(atom_u64_t*, atom_u64_t);

atom_u8_t  __cas8 (atom_u8_t *, atom_u8_t , atom_u8_t);
atom_u16_t __cas16(atom_u16_t*, atom_u16_t, atom_u16_t);
atom_u32_t __cas32(atom_u32_t*, atom_u32_t, atom_u32_t);
atom_u64_t __cas64(atom_u64_t*, atom_u64_t, atom_u64_t);

atom_u8_t  __xchg8 (atom_u8_t *, atom_u8_t) ;
atom_u16_t __xchg16(atom_u16_t*, atom_u16_t);
atom_u32_t __xchg32(atom_u32_t*, atom_u32_t);
atom_u64_t __xchg64(atom_u64_t*, atom_u64_t);

#endif
