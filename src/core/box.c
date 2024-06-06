#include "box.h"

obj_trait box_trait = make_trait (
    box_new    ,
    box_clone  ,
    null_t     ,
    box_del    ,
    sizeof(box),
    null_t
);

obj_trait* box_t = &box_trait;

bool_t 
    box_new
        (box* self, u32_t count, va_list arg)                          {
            u64_t len = 0ull  ; if (count > 0) len = va_arg(arg, u64_t);
            mem  *mem = null_t; if (count > 1) mem = va_arg(arg, void*);
            if (trait_of(mem) != mem_t) mem = get_mem();
            if (trait_of(mem) != mem_t) return false_t;
            if (!len) return false_t;

            self->ptr = mem_acq(mem, null_t, len);
            self->len = len;
            self->mem = mem;
            return self->ptr != 0;
}

bool_t 
    box_clone
        (box* self, box* clone)                                    {
            if (!clone->mem) return false_t; mem  *mem = clone->mem;
            if (!clone->ptr) return false_t; void *ptr = clone->ptr;
            if (!clone->len) return false_t; u64_t len = clone->len;

            self->ptr = mem_acq(mem, null_t, len); if (!self->ptr) return false_t;
            self->len = clone->len;
            self->mem = clone->mem;

            mem_copy(self->ptr, clone->ptr, len);
            return true_t;
}

void   
    box_del
        (box* self)                         {
            mem_rel(self->mem, self->ptr, 0);
}

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