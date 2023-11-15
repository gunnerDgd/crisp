#ifndef __ATOMIC_H__
#define __ATOMIC_H__

#include "type_atomic.h"

atomic_u8_t  lock_add8 (atomic_u8_t  *, atomic_u8_t) ;
atomic_u16_t lock_add16(atomic_u16_t *, atomic_u16_t);
atomic_u32_t lock_add32(atomic_u32_t *, atomic_u32_t);
atomic_u64_t lock_add64(atomic_u64_t *, atomic_u64_t);

atomic_u8_t  lock_sub8 (atomic_u8_t *, atomic_u8_t);
atomic_u16_t lock_sub16(atomic_u16_t *, atomic_u16_t);
atomic_u32_t lock_sub32(atomic_u32_t *, atomic_u32_t);
atomic_u64_t lock_sub64(atomic_u64_t *, atomic_u64_t);

atomic_u8_t  lock_inc8 (atomic_u8_t  *);
atomic_u16_t lock_inc16(atomic_u16_t *);
atomic_u32_t lock_inc32(atomic_u32_t *);
atomic_u64_t lock_inc64(atomic_u64_t *);

atomic_u8_t  lock_dec8 (atomic_u8_t *);
atomic_u16_t lock_dec16(atomic_u16_t*);
atomic_u32_t lock_dec32(atomic_u32_t*);
atomic_u64_t lock_dec64(atomic_u64_t*);

atomic_u8_t  lock_cas8 (atomic_u8_t *, atomic_u8_t , atomic_u8_t) ;
atomic_u16_t lock_cas16(atomic_u16_t*, atomic_u16_t, atomic_u16_t);
atomic_u32_t lock_cas32(atomic_u32_t*, atomic_u32_t, atomic_u32_t);
atomic_u64_t lock_cas64(atomic_u64_t*, atomic_u64_t, atomic_u64_t);

#endif
