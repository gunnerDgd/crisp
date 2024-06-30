#include "mem.h"

static bool_t
    do_new
        (mem* self, u32_t count, va_list arg)                             {
            mem_ops *ops = null_t; if (count > 0) ops = va_arg(arg, any_t);
            if (!ops)          return false_t;
            if (!ops->on_free) return false_t;
            if (!ops->on_use)  return false_t;
            if (!ops->on_new)  return false_t;
            if (!ops->on_del)  return false_t;

            self->mem = ops->on_new(count - 1, arg);
            self->ops = ops;

            if (!self->mem) return false_t;
            return true_t;
}

static bool_t
    do_clone
        (mem* self, mem* clone) {
            return false_t;
}

static void
    do_del
        (mem* self)                     {
            self->ops->on_del(self->mem);
}

static obj_trait
    do_obj = make_trait (
        do_new     ,
        do_clone   ,
        null_t     ,
        do_del     ,
        sizeof(mem),
        null_t
);

obj_trait *mem_t = &do_obj;

void*
    mem_use
        (mem* self, void* hint, u64_t len)            {
            if (trait_of(self) != mem_t) return null_t;
            if (!len)                    return null_t;
            return self->ops->on_use (
                self->mem,
                hint     ,
                len
            );
}

void
    mem_free
        (mem* self, void* rel, u64_t len)      {
            if (trait_of(self) != mem_t) return;
            if (!rel)                    return;
            return self->ops->on_free          (
                self->mem,
                rel      ,
                len
            );
}

