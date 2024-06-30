#ifndef COLLECTIONS_POS_H
#define COLLECTIONS_POS_H

#include "../core.h"

extern obj_trait *pos_t;
typedef struct    pos  {
    obj          head;
    struct pos  *prev, *next;
    union        {
        any_t any;
        obj*  obj;

        f64_t f64;
        f64_t f32;

        u64_t u64;
        i64_t i64;

        u32_t u32;
        i32_t i32;

        u16_t u16;
        i16_t i16;

        u8_t  u8;
        i8_t  i8;
    };
}   pos;

pos* pos_next (pos* self, pos* next);
pos* pos_prev (pos* self, pos* prev);

#ifndef __cplusplus
#define next(self)           pos_next ((self), null_t)
#define next_as(self, next)  pos_next ((self), (next))
#define prev(self)           pos_prev ((self), null_t)
#define prev_as(self, prev)  pos_prev ((self), (prev))
#endif

#endif