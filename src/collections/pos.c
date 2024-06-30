#include "pos.h"

static i8_t  do_as_i8 (pos* self) { if (trait_of(self) != pos_t) return 0; return self->i8; }
static u8_t  do_as_u8 (pos* self) { if (trait_of(self) != pos_t) return 0; return self->u8; }

static i16_t do_as_i16(pos* self) { if (trait_of(self) != pos_t) return 0; return self->i16; }
static u16_t do_as_u16(pos* self) { if (trait_of(self) != pos_t) return 0; return self->u16; }

static i32_t do_as_i32(pos* self) { if (trait_of(self) != pos_t) return 0; return self->i32; }
static u32_t do_as_u32(pos* self) { if (trait_of(self) != pos_t) return 0; return self->u32; }

static i64_t do_as_i64(pos* self) { if (trait_of(self) != pos_t) return 0; return self->i64; }
static u64_t do_as_u64(pos* self) { if (trait_of(self) != pos_t) return 0; return self->u64; }

static f32_t do_as_f32(pos* self) { if (trait_of(self) != pos_t) return 0.0f; return self->f32; }
static f64_t do_as_f64(pos* self) { if (trait_of(self) != pos_t) return 0.0;  return self->f64; }

static any_t do_as_any(pos* self) { if (trait_of(self) != pos_t) return null_t; return self->any; }

static obj*
    do_as
        (pos* self, obj_trait *as)                    {
            if (trait_of(self) != pos_t) return null_t;
            if (!as)                     return null_t;
            obj* ret = self->obj;

            if (trait_of(ret) == as) return ret;
            return null_t;
}

static cast
    do_cast = make_cast (
        do_as    ,
        do_as_i8 ,
        do_as_u8 ,
        do_as_i16,
        do_as_u16,
        do_as_i32,
        do_as_u32,
        do_as_i64,
        do_as_u64,
        do_as_f32,
        do_as_f64,
        do_as_any
);

static obj_ops
    do_ops =            {
        .cast = &do_cast
};

static bool_t
    do_new
        (pos* self, u32_t count, va_list arg)                           {
            any_t pos  = null_t; if (count > 0) pos = va_arg(arg, any_t);
            self->next = null_t;
            self->prev = null_t;
            self->any  = pos;
            return true_t;
}

static bool_t
    do_clone
        (pos* self, pos* clone) {
            return false_t;
}

static void
    do_del
        (pos* self)                                      {
            if (self->prev) self->prev->next = self->next;
            if (self->next) self->next->prev = self->prev;
}

static obj_trait
    do_obj = make_trait (
        do_new     ,
        do_clone   ,
        null_t     ,
        do_del     ,
        sizeof(pos),
        &do_ops
);

obj_trait* pos_t = &do_obj;

pos*
    pos_next
        (pos* self, pos* next)                                                      {
            if (trait_of(self) != pos_t) return null_t; if (!next) return self->next;
            if (trait_of(next) != pos_t) return null_t;
            self->next = next;
            next->prev = self;
            return next;
}

pos*
    pos_prev
        (pos* self, pos* prev)                                                      {
            if (trait_of(self) != pos_t) return null_t; if (!prev) return self->prev;
            if (trait_of(prev) != pos_t) return null_t;
            self->prev = prev;
            prev->next = self;
            return prev;
}