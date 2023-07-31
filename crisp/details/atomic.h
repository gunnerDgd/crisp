#ifndef CRISP_DETAILS_ATOMIC_H
#define CRISP_DETAILS_ATOMIC_H

#include <crisp/type_atomic.h>

c_atomic_i8_t
    atomic_add_i8
        (c_atomic_i8_t *, c_atomic_i8_t );

c_atomic_i16_t
    atomic_add_i16
        (c_atomic_i16_t *, c_atomic_i16_t );

c_atomic_i32_t
    atomic_add_i32
        (c_atomic_i32_t *, c_atomic_i32_t );

c_atomic_i64_t
    atomic_add_i64
        (c_atomic_i64_t *, c_atomic_i64_t );

c_atomic_u8_t
    atomic_add_u8
        (c_atomic_u8_t *, c_atomic_u8_t );

c_atomic_u16_t
    atomic_add_u16
        (c_atomic_u16_t *, c_atomic_u16_t );

c_atomic_u32_t
    atomic_add_u32
        (c_atomic_u32_t *, c_atomic_u32_t );

c_atomic_u64_t
    atomic_add_u64
        (c_atomic_u64_t *, c_atomic_u64_t );


c_atomic_i8_t
    atomic_sub_i8
        (c_atomic_i8_t *, c_atomic_i8_t );

c_atomic_i16_t
    atomic_sub_i16
        (c_atomic_i16_t *, c_atomic_i16_t );

c_atomic_i32_t
    atomic_sub_i32
        (c_atomic_i32_t *, c_atomic_i32_t );

c_atomic_i64_t
    atomic_sub_i64
        (c_atomic_i64_t *, c_atomic_i64_t );

c_atomic_u8_t
    atomic_sub_u8
        (c_atomic_u8_t *, c_atomic_u8_t );

c_atomic_u16_t
    atomic_sub_u16
        (c_atomic_u16_t *, c_atomic_u16_t );

c_atomic_u32_t
    atomic_sub_u32
        (c_atomic_u32_t *, c_atomic_u32_t );

c_atomic_u64_t
    atomic_sub_u64
        (c_atomic_u64_t *, c_atomic_u64_t );

c_atomic_i8_t
    atomic_inc_i8
        (c_atomic_i8_t *, c_atomic_i8_t );

c_atomic_i16_t
    atomic_inc_i16
        (c_atomic_i16_t *, c_atomic_i16_t );

c_atomic_i32_t
    atomic_inc_i32
        (c_atomic_i32_t *, c_atomic_i32_t );

c_atomic_i64_t
    atomic_inc_i64
        (c_atomic_i64_t *, c_atomic_i64_t );

c_atomic_u8_t
    atomic_inc_u8
        (c_atomic_u8_t *, c_atomic_u8_t );

c_atomic_u16_t
    atomic_inc_u16
        (c_atomic_u16_t *, c_atomic_u16_t );

c_atomic_u32_t
    atomic_inc_u32
        (c_atomic_u32_t *, c_atomic_u32_t );

c_atomic_u64_t
    atomic_inc_u64
        (c_atomic_u64_t *, c_atomic_u64_t );

c_atomic_i8_t
    atomic_dec_i8
        (c_atomic_i8_t *, c_atomic_i8_t );

c_atomic_i16_t
    atomic_dec_i16
        (c_atomic_i16_t *, c_atomic_i16_t );

c_atomic_i32_t
    atomic_dec_i32
        (c_atomic_i32_t *, c_atomic_i32_t );

c_atomic_i64_t
    atomic_dec_i64
        (c_atomic_i64_t *, c_atomic_i64_t );

c_atomic_u8_t
    atomic_dec_u8
        (c_atomic_u8_t *, c_atomic_u8_t );

c_atomic_u16_t
    atomic_dec_u16
        (c_atomic_u16_t *, c_atomic_u16_t );

c_atomic_u32_t
    atomic_dec_u32
        (c_atomic_u32_t *, c_atomic_u32_t );

c_atomic_u64_t
    atomic_dec_u64
        (c_atomic_u64_t *, c_atomic_u64_t );

c_atomic_i8_t
    atomic_cmpxchg_i8
        (c_atomic_i8_t *, c_atomic_i8_t );

c_atomic_i16_t
    atomic_cmpxchg_i16
        (c_atomic_i16_t *, c_atomic_i16_t );

c_atomic_i32_t
    atomic_cmpxchg_i32
        (c_atomic_i32_t *, c_atomic_i32_t );

c_atomic_i64_t
    atomic_cmpxchg_i64
        (c_atomic_i64_t *, c_atomic_i64_t );

c_atomic_u8_t
    atomic_cmpxchg_u8
        (c_atomic_u8_t *, c_atomic_u8_t );

c_atomic_u16_t
    atomic_cmpxchg_u16
        (c_atomic_u16_t *, c_atomic_u16_t );

c_atomic_u32_t
    atomic_cmpxchg_u32
        (c_atomic_u32_t *, c_atomic_u32_t );

c_atomic_u64_t
    atomic_cmpxchg_u64
        (c_atomic_u64_t *, c_atomic_u64_t );

#endif
