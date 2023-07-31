#ifndef CRISP_TYPE_ATOMIC_H
#define CRISP_TYPE_ATOMIC_H

#include <crisp/type.h>

typedef volatile uint8_t  c_atomic_u8_t ;
typedef volatile uint16_t c_atomic_u16_t;
typedef volatile uint32_t c_atomic_u32_t;
typedef volatile uint64_t c_atomic_u64_t;

typedef volatile int8_t   c_atomic_i8_t ;
typedef volatile int16_t  c_atomic_i16_t;
typedef volatile int32_t  c_atomic_i32_t;
typedef volatile int64_t  c_atomic_i64_t;

#endif
