#include "box.h"

static obj*
    do_as
        (box* self, obj_trait *as)                    {
            if (trait_of(self) != box_t) return null_t;
            if (!as)                     return null_t;
            obj* ret = (obj*) self->ptr;

            if (self->len < as->size) return null_t;
            if (trait_of(ret) != as)  return null_t;
            return ret;
}

static cast
    do_cast = make_cast (
        do_as ,
        null_t,
        null_t,
        null_t,
        null_t,
        null_t,
        null_t,
        null_t,
        null_t,
        null_t,
        null_t,
        null_t
);

static obj_ops
    do_ops =            {
        .cast = &do_cast
};

static bool_t
    do_new
        (box* self, u32_t count, va_list arg)                          {
            u64_t len = 0ull  ; if (count > 0) len = va_arg(arg, u64_t);
            mem  *mem = null_t; if (count > 1) mem = va_arg(arg, void*);
            if (trait_of(mem) != mem_t) mem = get_mem();
            if (trait_of(mem) != mem_t) return false_t;
            if (!len) return false_t;

            self->ptr = mem_use(mem, null_t, len);
            self->len = len;
            self->mem = mem;
            return self->ptr != 0;
}

static bool_t
    do_clone
        (box* self, box* clone)                                    {
            if (!clone->mem) return false_t; mem  *mem = clone->mem;
            if (!clone->ptr) return false_t; void *ptr = clone->ptr;
            if (!clone->len) return false_t; u64_t len = clone->len;

            self->ptr = mem_use(mem, null_t, len); if (!self->ptr) return false_t;
            self->len = clone->len;
            self->mem = clone->mem;

            mem_copy(self->ptr, clone->ptr, len);
            return true_t;
}

static void
    do_del
        (box* self)      {
            mem_free     (
                self->mem,
                self->ptr,
                0
            );
}

static obj_trait
    do_obj = make_trait (
        do_new     ,
        do_clone   ,
        null_t     ,
        do_del     ,
        sizeof(box),
        &do_ops
);

obj_trait* box_t = &do_obj;

void*
    box_ptr
        (box* self)                                   {
            if (trait_of(self) != box_t) return null_t;
            return self->ptr;
}

u64_t 
    box_size
        (box* self)                              {
            if (trait_of(self) != box_t) return 0;
            return self->len;
}