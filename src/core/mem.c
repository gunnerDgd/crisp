#include "mem.h"
#include "macro.h"

obj_trait mem_trait = make_trait (
    mem_new    ,
    mem_clone  ,
    null_t     ,
    mem_del    ,
    sizeof(mem),
    null_t
);

obj_trait *mem_t = &mem_trait;

bool_t
    mem_new
        (mem* self, u32_t count, va_list arg)                             {
            mem_ops *ops = null_t; if (count > 0) ops = va_arg(arg, any_t);
            if (!ops)         return false_t;
            if (!ops->on_acq) return false_t;
            if (!ops->on_rel) return false_t;
            if (!ops->on_new) return false_t;
            if (!ops->on_del) return false_t;

            self->mem = ops->on_new(count - 1, arg);
            self->ops = ops;

            if (!self->mem) return false_t;
            return true_t;
}

bool_t
    mem_clone
        (mem* self, mem* clone) {
            return false_t;
}

void
    mem_del
        (mem* self)                     {
            self->ops->on_del(self->mem);
}

void*
    mem_acq
        (mem* self, void* hint, u64_t len)            {
            if (trait_of(self) != mem_t) return null_t;
            if (!len)                    return null_t;
            return self->ops->on_acq (
                self->mem,
                hint     ,
                len
            );
}

void
    mem_rel
        (mem* self, void* rel, u64_t len)      {
            if (trait_of(self) != mem_t) return;
            if (!rel)                    return;
            return self->ops->on_rel           (
                self->mem,
                rel      ,
                len
            );
}

