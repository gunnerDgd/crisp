#ifndef CORE_OPS_CAST_H
#define CORE_OPS_CAST_H

#include "../type.h"

struct obj_trait;
struct obj;

typedef struct cast                                      {
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

    any_t       (*as_any)(struct obj*);
}   cast;

#define make_cast(do_as, do_i8, do_u8, do_i16, do_u16, do_i32, do_u32, do_i64, do_u64, do_f32, do_f64, do_any) {\
    .as     = (struct obj*(*)(struct obj*, struct obj_trait*))(do_as) ,\
    .as_i8  = (i8_t       (*)(struct obj*, struct obj_trait*))(do_i8) ,\
    .as_u8  = (u8_t       (*)(struct obj*, struct obj_trait*))(do_u8) ,\
    .as_i16 = (i16_t      (*)(struct obj*, struct obj_trait*))(do_i16),\
    .as_u16 = (u16_t      (*)(struct obj*, struct obj_trait*))(do_u16),\
    .as_i32 = (i32_t      (*)(struct obj*, struct obj_trait*))(do_i32),\
    .as_u32 = (u32_t      (*)(struct obj*, struct obj_trait*))(do_u32),\
    .as_i64 = (i64_t      (*)(struct obj*, struct obj_trait*))(do_i64),\
    .as_u64 = (u64_t      (*)(struct obj*, struct obj_trait*))(do_u64),\
    .as_f32 = (f32_t      (*)(struct obj*, struct obj_trait*))(do_f32),\
    .as_f64 = (f64_t      (*)(struct obj*, struct obj_trait*))(do_f64),\
    .as_any = (any_t      (*)(struct obj*, struct obj_trait*))(do_any),\
}

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

any_t       as_any(struct obj*);

#endif