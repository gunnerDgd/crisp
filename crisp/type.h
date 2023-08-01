#ifndef CRISP_TYPE_H
#define CRISP_TYPE_H

#ifdef CRISP_PRESET_LINUX
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#endif

#ifdef CRISP_PRESET_WIN32
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#endif

typedef uint8_t  c_u8_t ;
typedef uint16_t c_u16_t;
typedef uint32_t c_u32_t;
typedef uint64_t c_u64_t;
typedef int8_t   c_i8_t ;
typedef int16_t  c_i16_t;
typedef int32_t  c_i32_t;
typedef int64_t  c_i64_t;
typedef bool     c_bool_t;

#define c_handle_t(name) typedef struct name { void* ptr; } name;
#define c_handle_init(type, name, value) type name = { .ptr = value }

#define c_handle_typed_ptr(par_handle, type) ((type)par_handle.ptr)
#define c_handle_ptr(par_handle)             (par_handle.ptr)
#endif
