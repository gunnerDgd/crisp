#include "atomic.h"
#include "details/atomic.h"

c_atomic_i8_t
    c_atomic_add_i8(c_atomic_i8_t * par_dst, c_atomic_i8_t par_add) {
        return atomic_add8(par_dst, par_add);
}

c_atomic_i16_t
    c_atomic_add_i16(c_atomic_i16_t * par_dst, c_atomic_i16_t par_add) {
        return atomic_add16(par_dst, par_add);
}

c_atomic_i32_t
    c_atomic_add_i32(c_atomic_i32_t * par_dst, c_atomic_i32_t par_add) {
        return atomic_add32(par_dst, par_add);
}

c_atomic_i64_t
    c_atomic_add_i64(c_atomic_i64_t * par_dst, c_atomic_i64_t par_add) {
        return atomic_add64(par_dst, par_add);
}

c_atomic_u8_t
    c_atomic_add_u8(c_atomic_u8_t * par_dst, c_atomic_u8_t par_add) {
        return atomic_add8(par_dst, par_add);
}

c_atomic_u16_t
    c_atomic_add_u16(c_atomic_u16_t * par_dst, c_atomic_u16_t par_add) {
        return atomic_add16(par_dst, par_add);
}

c_atomic_u32_t
    c_atomic_add_u32(c_atomic_u32_t * par_dst, c_atomic_u32_t par_add) {
        return atomic_add32(par_dst, par_add);
}

c_atomic_u64_t
    c_atomic_add_u64(c_atomic_u64_t * par_dst, c_atomic_u64_t par_add) {
        return atomic_add64(par_dst, par_add);
}

c_atomic_i8_t
    c_atomic_sub_i8(c_atomic_i8_t * par_dst, c_atomic_i8_t par_add) {
        return atomic_sub8(par_dst, par_add);
}

c_atomic_i16_t
    c_atomic_sub_i16(c_atomic_i16_t * par_dst, c_atomic_i16_t par_add) {
        return atomic_sub16(par_dst, par_add);
}

c_atomic_i32_t
    c_atomic_sub_i32(c_atomic_i32_t * par_dst, c_atomic_i32_t par_add) {
        return atomic_sub32(par_dst, par_add);
}

c_atomic_i64_t
    c_atomic_sub_i64(c_atomic_i64_t * par_dst, c_atomic_i64_t par_add) {
        return atomic_sub64(par_dst, par_add);
}

c_atomic_u8_t
    c_atomic_sub_u8(c_atomic_u8_t * par_dst, c_atomic_u8_t par_add) {
        return atomic_sub8(par_dst, par_add);
}

c_atomic_u16_t
    c_atomic_sub_u16(c_atomic_u16_t * par_dst, c_atomic_u16_t par_add) {
        return atomic_sub16(par_dst, par_add);
}

c_atomic_u32_t
    c_atomic_sub_u32(c_atomic_u32_t * par_dst, c_atomic_u32_t par_add) {
        return atomic_sub32(par_dst, par_add);
}

c_atomic_u64_t
    c_atomic_sub_u64(c_atomic_u64_t * par_dst, c_atomic_u64_t par_add) {
        return atomic_sub64(par_dst, par_add);
}


c_atomic_i8_t
    c_atomic_inc_i8(c_atomic_i8_t * par_dst, c_atomic_i8_t par_add) {
        return atomic_inc8(par_dst, par_add);
}

c_atomic_i16_t
    c_atomic_inc_i16(c_atomic_i16_t * par_dst, c_atomic_i16_t par_add) {
        return atomic_inc16(par_dst, par_add);
}

c_atomic_i32_t
    c_atomic_inc_i32(c_atomic_i32_t * par_dst, c_atomic_i32_t par_add) {
        return atomic_inc32(par_dst, par_add);
}

c_atomic_i64_t
    c_atomic_inc_i64(c_atomic_i64_t * par_dst, c_atomic_i64_t par_add) {
        return atomic_inc64(par_dst, par_add);
}

c_atomic_u8_t
    c_atomic_inc_u8(c_atomic_u8_t * par_dst, c_atomic_u8_t par_add) {
        return atomic_inc8(par_dst, par_add);
}

c_atomic_u16_t
    c_atomic_inc_u16(c_atomic_u16_t * par_dst, c_atomic_u16_t par_add) {
        return atomic_inc16(par_dst, par_add);
}

c_atomic_u32_t
    c_atomic_inc_u32(c_atomic_u32_t * par_dst, c_atomic_u32_t par_add) {
        return atomic_inc32(par_dst, par_add);
}

c_atomic_u64_t
    c_atomic_inc_u64(c_atomic_u64_t * par_dst, c_atomic_u64_t par_add) {
        return atomic_inc64(par_dst, par_add);
}


c_atomic_i8_t
    c_atomic_dec_i8(c_atomic_i8_t * par_dst, c_atomic_i8_t par_add) {
        return atomic_dec8(par_dst, par_add);
}

c_atomic_i16_t
    c_atomic_dec_i16(c_atomic_i16_t * par_dst, c_atomic_i16_t par_add) {
        return atomic_dec16(par_dst, par_add);
}

c_atomic_i32_t
    c_atomic_dec_i32(c_atomic_i32_t * par_dst, c_atomic_i32_t par_add) {
        return atomic_dec32(par_dst, par_add);
}

c_atomic_i64_t
    c_atomic_dec_i64(c_atomic_i64_t * par_dst, c_atomic_i64_t par_add) {
        return atomic_dec64(par_dst, par_add);
}

c_atomic_u8_t
    c_atomic_dec_u8(c_atomic_u8_t * par_dst, c_atomic_u8_t par_add) {
        return atomic_dec8(par_dst, par_add);
}

c_atomic_u16_t
    c_atomic_dec_u16(c_atomic_u16_t * par_dst, c_atomic_u16_t par_add) {
        return atomic_dec16(par_dst, par_add);
}

c_atomic_u32_t
    c_atomic_dec_u32(c_atomic_u32_t * par_dst, c_atomic_u32_t par_add) {
        return atomic_dec32(par_dst, par_add);
}

c_atomic_u64_t
    c_atomic_dec_u64(c_atomic_u64_t * par_dst, c_atomic_u64_t par_add) {
        return atomic_dec64(par_dst, par_add);
}


c_atomic_i8_t
    c_atomic_cmpxchg_i8(c_atomic_i8_t * par_dst, c_atomic_i8_t par_add) {
        return atomic_cmpxchg8(par_dst, par_add);
}

c_atomic_i16_t
    c_atomic_cmpxchg_i16(c_atomic_i16_t * par_dst, c_atomic_i16_t par_add) {
        return atomic_cmpxchg16(par_dst, par_add);
}

c_atomic_i32_t
    c_atomic_cmpxchjg_i32(c_atomic_i32_t * par_dst, c_atomic_i32_t par_add) {
        return atomic_cmpxchg32(par_dst, par_add);
}

c_atomic_i64_t
    c_atomic_cmpxchg_i64(c_atomic_i64_t * par_dst, c_atomic_i64_t par_add) {
        return atomic_cmpxchg64(par_dst, par_add);
}

c_atomic_u8_t
    c_atomic_cmpxchg_u8(c_atomic_u8_t * par_dst, c_atomic_u8_t par_add) {
        return atomic_cmpxchg8(par_dst, par_add);
}

c_atomic_u16_t
    c_atomic_cmpxchg_u16(c_atomic_u16_t * par_dst, c_atomic_u16_t par_add) {
        return atomic_cmpxchg16(par_dst, par_add);
}

c_atomic_u32_t
    c_atomic_cmpxchg_u32(c_atomic_u32_t * par_dst, c_atomic_u32_t par_add) {
        return atomic_cmpxchg32(par_dst, par_add);
}

c_atomic_u64_t
    c_atomic_cmpxchg_u64(c_atomic_u64_t * par_dst, c_atomic_u64_t par_add) {
        return atomic_cmpxchg64(par_dst, par_add);
}