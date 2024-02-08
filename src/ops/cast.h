#ifndef __OPS_CAST_H__
#define __OPS_CAST_H__

#include "../type.h"

struct obj      ;
struct obj_trait;

typedef struct ops_cast                                  {
    struct obj* (*as)    (struct obj*, struct obj_trait*);
    i8_t        (*as_i8) (struct obj*);
    u8_t        (*as_u8) (struct obj*);

    i16_t       (*as_i16)(struct obj*);
    u16_t       (*as_u16)(struct obj*);
    
    i32_t       (*as_i32)(struct obj*);
    u32_t       (*as_u32)(struct obj*);
    
    i64_t       (*as_i64)(struct obj*);
    u64_t       (*as_u64)(struct obj*);
    
    f32_t       (*as_f32)(struct obj*);
    f64_t       (*as_f64)(struct obj*);
}   ops_cast;

struct obj* as    (struct obj*, struct obj_trait*);
i8_t        as_i8 (struct obj*);
u8_t        as_u8 (struct obj*);

i16_t       as_i16(struct obj*);
u16_t       as_u16(struct obj*);

i32_t       as_i32(struct obj*);
u32_t       as_u32(struct obj*);

i64_t       as_i64(struct obj*);
u64_t       as_u64(struct obj*);

f32_t       as_f32(struct obj*);
f64_t       as_f64(struct obj*);

#endif