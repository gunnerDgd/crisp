#ifndef CRISP_DETAILS_ATOMIC_H
#define CRISP_DETAILS_ATOMIC_H

#include <crisp/type_atomic.h>

c_atomic_i8_t
    atomic_add8
        (c_atomic_i8_t *, c_atomic_i8_t );

c_atomic_i16_t
    atomic_add16
        (c_atomic_i16_t *, c_atomic_i16_t );

c_atomic_i32_t
    atomic_add32
        (c_atomic_i32_t *, c_atomic_i32_t );

c_atomic_i64_t
    atomic_add64
        (c_atomic_i64_t *, c_atomic_i64_t );


c_atomic_i8_t
    atomic_sub8
        (c_atomic_i8_t *, c_atomic_i8_t );

c_atomic_i16_t
    atomic_sub16
        (c_atomic_i16_t *, c_atomic_i16_t );

c_atomic_i32_t
    atomic_sub32
        (c_atomic_i32_t *, c_atomic_i32_t );

c_atomic_i64_t
    atomic_sub64
        (c_atomic_i64_t *, c_atomic_i64_t );


c_atomic_i8_t
    atomic_inc8
        (c_atomic_i8_t *, c_atomic_i8_t );

c_atomic_i16_t
    atomic_inc16
        (c_atomic_i16_t *, c_atomic_i16_t );

c_atomic_i32_t
    atomic_inc32
        (c_atomic_i32_t *, c_atomic_i32_t );

c_atomic_i64_t
    atomic_inc64
        (c_atomic_i64_t *, c_atomic_i64_t );


c_atomic_i8_t
    atomic_dec8
        (c_atomic_i8_t *, c_atomic_i8_t );

c_atomic_i16_t
    atomic_dec16
        (c_atomic_i16_t *, c_atomic_i16_t );

c_atomic_i32_t
    atomic_dec32
        (c_atomic_i32_t *, c_atomic_i32_t );

c_atomic_i64_t
    atomic_dec64
        (c_atomic_i64_t *, c_atomic_i64_t );


c_atomic_i8_t
    atomic_cmpxchg8
        (c_atomic_i8_t *, c_atomic_i8_t );

c_atomic_i16_t
    atomic_cmpxchg16
        (c_atomic_i16_t *, c_atomic_i16_t );

c_atomic_i32_t
    atomic_cmpxchg32
        (c_atomic_i32_t *, c_atomic_i32_t );

c_atomic_i64_t
    atomic_cmpxchg64
        (c_atomic_i64_t *, c_atomic_i64_t );


#endif
