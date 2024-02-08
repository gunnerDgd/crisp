#ifndef __TYPE_H__
#define __TYPE_H__

#include <stdarg.h>
#ifdef PRESET_LINUX_MODULE
#else
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef uint8_t  u8_t ;
typedef uint16_t u16_t;
typedef uint32_t u32_t;
typedef uint64_t u64_t;

typedef int8_t   i8_t ;
typedef int16_t  i16_t;
typedef int32_t  i32_t;
typedef int64_t  i64_t;

typedef float    f32_t;
typedef double   f64_t;

typedef bool     bool_t;
typedef void*    any_t ;
#endif

#define false_t  0
#define true_t   1
#define null_t  ((void*)0)

typedef u64_t u128_t[2];
typedef i64_t i128_t[2];

typedef u64_t u256_t[4];
typedef i64_t i256_t[4];

#define        cstr(par) { .str = par, .len = sizeof(par) }
typedef struct cstr_t    { 
    const char *str;
    u64_t       len; 
}   cstr_t;

#define        wcstr(par) { .str = L##par, .len = sizeof(par) / sizeof(wchar_t) }
typedef struct wcstr_t    { 
    const wchar_t *str; 
    u64_t          len;
}   wcstr_t;

#endif
