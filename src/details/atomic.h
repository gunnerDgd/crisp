#ifndef __DETAILS_ATOMIC_H__
#define __DETAILS_ATOMIC_H__

#include "../type_atomic.h"

atomic_u8_t  __lock_add8 (atomic_u8_t *, atomic_u8_t);
atomic_u16_t __lock_add16(atomic_u16_t*, atomic_u16_t);
atomic_u32_t __lock_add32(atomic_u32_t*, atomic_u32_t);
atomic_u64_t __lock_add64(atomic_u64_t*, atomic_u64_t);

atomic_u8_t  __lock_sub8 (atomic_u8_t *, atomic_u8_t);
atomic_u16_t __lock_sub16(atomic_u16_t*, atomic_u16_t);
atomic_u32_t __lock_sub32(atomic_u32_t*, atomic_u32_t);
atomic_u64_t __lock_sub64(atomic_u64_t*, atomic_u64_t);

atomic_u8_t  __lock_inc8 (atomic_u8_t *);
atomic_u16_t __lock_inc16(atomic_u16_t*);
atomic_u32_t __lock_inc32(atomic_u32_t*);
atomic_u64_t __lock_inc64(atomic_u64_t*);

atomic_u8_t  __lock_dec8 (atomic_u8_t *);
atomic_u16_t __lock_dec16(atomic_u16_t*);
atomic_u32_t __lock_dec32(atomic_u32_t*);
atomic_u64_t __lock_dec64(atomic_u64_t*);

atomic_u8_t  __lock_cas8 (atomic_u8_t *, atomic_u8_t , atomic_u8_t);
atomic_u16_t __lock_cas16(atomic_u16_t*, atomic_u16_t, atomic_u16_t);
atomic_u32_t __lock_cas32(atomic_u32_t*, atomic_u32_t, atomic_u32_t);
atomic_u64_t __lock_cas64(atomic_u64_t*, atomic_u64_t, atomic_u64_t);

atomic_u8_t  __lock_xchg8 (atomic_u8_t *, atomic_u8_t);
atomic_u16_t __lock_xchg16(atomic_u16_t*, atomic_u16_t);
atomic_u32_t __lock_xchg32(atomic_u32_t*, atomic_u32_t);
atomic_u64_t __lock_xchg64(atomic_u64_t*, atomic_u64_t);

atomic_u8_t  __cas8 (atomic_u8_t *, atomic_u8_t , atomic_u8_t);
atomic_u16_t __cas16(atomic_u16_t*, atomic_u16_t, atomic_u16_t);
atomic_u32_t __cas32(atomic_u32_t*, atomic_u32_t, atomic_u32_t);
atomic_u64_t __cas64(atomic_u64_t*, atomic_u64_t, atomic_u64_t);

atomic_u8_t  __xchg8 (atomic_u8_t *, atomic_u8_t) ;
atomic_u16_t __xchg16(atomic_u16_t*, atomic_u16_t);
atomic_u32_t __xchg32(atomic_u32_t*, atomic_u32_t);
atomic_u64_t __xchg64(atomic_u64_t*, atomic_u64_t);

#endif
