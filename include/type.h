#ifndef __TYPE_H__
#define __TYPE_H__

#include <stdarg.h>

typedef unsigned char      u8_t  ;
typedef unsigned short     u16_t ;
typedef unsigned int       u32_t ;
typedef unsigned long long u64_t ;
typedef char               i8_t  ;
typedef short              i16_t ;
typedef int                i32_t ;
typedef long long          i64_t ;
typedef char               bool_t;

#define false_t  0
#define true_t   1

typedef u64_t u128_t[2];
typedef i64_t i128_t[2];

typedef u64_t u256_t[4];
typedef i64_t i256_t[4];

#endif
