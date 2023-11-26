#ifndef __ATOM_H__
#define __ATOM_H__

#include "type_atom.h"

atom_u8_t  lock_add8 (atom_u8_t  *, atom_u8_t) ;
atom_u16_t lock_add16(atom_u16_t *, atom_u16_t);
atom_u32_t lock_add32(atom_u32_t *, atom_u32_t);
atom_u64_t lock_add64(atom_u64_t *, atom_u64_t);

atom_u8_t  lock_sub8 (atom_u8_t *, atom_u8_t);
atom_u16_t lock_sub16(atom_u16_t *, atom_u16_t);
atom_u32_t lock_sub32(atom_u32_t *, atom_u32_t);
atom_u64_t lock_sub64(atom_u64_t *, atom_u64_t);

atom_u8_t  lock_inc8 (atom_u8_t  *);
atom_u16_t lock_inc16(atom_u16_t *);
atom_u32_t lock_inc32(atom_u32_t *);
atom_u64_t lock_inc64(atom_u64_t *);

atom_u8_t  lock_dec8 (atom_u8_t *);
atom_u16_t lock_dec16(atom_u16_t*);
atom_u32_t lock_dec32(atom_u32_t*);
atom_u64_t lock_dec64(atom_u64_t*);

atom_u8_t  lock_cas8 (atom_u8_t *, atom_u8_t , atom_u8_t) ;
atom_u16_t lock_cas16(atom_u16_t*, atom_u16_t, atom_u16_t);
atom_u32_t lock_cas32(atom_u32_t*, atom_u32_t, atom_u32_t);
atom_u64_t lock_cas64(atom_u64_t*, atom_u64_t, atom_u64_t);

atom_u8_t  lock_xchg8 (atom_u8_t *, atom_u8_t);
atom_u16_t lock_xchg16(atom_u16_t*, atom_u16_t);
atom_u32_t lock_xchg32(atom_u32_t*, atom_u32_t);
atom_u64_t lock_xchg64(atom_u64_t*, atom_u64_t);

atom_u8_t  cas8 (atom_u8_t *, atom_u8_t , atom_u8_t);
atom_u16_t cas16(atom_u16_t*, atom_u16_t, atom_u16_t);
atom_u32_t cas32(atom_u32_t*, atom_u32_t, atom_u32_t);
atom_u64_t cas64(atom_u64_t*, atom_u64_t, atom_u64_t);

atom_u8_t  xchg8 (atom_u8_t *, atom_u8_t );
atom_u16_t xchg16(atom_u16_t*, atom_u16_t);
atom_u32_t xchg32(atom_u32_t*, atom_u32_t);
atom_u64_t xchg64(atom_u64_t*, atom_u64_t);

#endif
