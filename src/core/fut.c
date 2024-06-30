#include "fut.h"

#include "this.h"
#include "task.h"

static bool_t
    do_new
        (fut* self, u32_t count, va_list arg)                             {
            fut_ops *ops = null_t; if (count > 0) ops = va_arg(arg, any_t);
            obj     *fut = null_t; if (count > 1) fut = va_arg(arg, any_t);
            if (!ops)       return false_t;
            if (!ops->poll) return false_t;
            if (!ops->ret)  return false_t;
            if (!fut)       return false_t;

            self->stat = fut_pend;
            self->fut  = ref(fut);
            self->ops  = ops     ;
            return true_t;
}

static bool_t
    do_clone
        (fut* self, fut* clone) {
            return false_t;
}

static void
    do_del
        (fut* self)        {
            del (self->fut);
}

static obj_trait
    do_obj = make_trait (
        do_new     ,
        do_clone   ,
        null_t     ,
        do_del     ,
        sizeof(fut),
        null_t
);

obj_trait* fut_t = &do_obj;

u64_t  
    fut_poll
        (fut* self)                                       {
            if (trait_of(self) != fut_t) return    fut_err;
            if (self->stat != fut_pend)  return self->stat;
            self->stat = self->ops->poll(self->fut);
            return self->stat;
}

void*
    fut_ret
        (fut* self)                                   {
            if (trait_of(self) != fut_t) return null_t;
            if (self->stat == fut_pend)  return null_t;

            self->ret = self->ops->ret(self->fut);
            return self->ret;
}

void*
    await
        (fut* self)                                          {
            if (trait_of(this.task) != task_t) return null_t;
            if (trait_of(self)      != fut_t)  return null_t;
            task* task = this.task;

            for ( ; fut_poll(self) == fut_pend ; cpu_switch(&task->cpu, task->ret));
            any_t  ret = fut_ret (self); del(self);
            return ret;
}