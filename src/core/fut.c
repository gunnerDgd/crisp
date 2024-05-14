#include "fut.h"

#include "this.h"
#include "task.h"

obj_trait fut_trait = make_trait (
    fut_new    ,
    fut_clone  ,
    null_t     ,
    fut_del    ,
    sizeof(fut),
    null_t
);

obj_trait* fut_t = &fut_trait;

bool_t
    fut_new
        (fut* par_fut, u32_t par_count, va_list par)                             {
            fut_ops *ops = null_t; if (par_count > 0) ops = va_arg(par, fut_ops*);
            obj     *fut = null_t; if (par_count > 1) fut = va_arg(par, obj    *);
            if (!ops)       return false_t;
            if (!ops->poll) return false_t;
            if (!ops->ret)  return false_t;
            if (!fut)       return false_t;

            par_fut->stat = fut_pend;
            par_fut->fut  = ref(fut);
            par_fut->ops  = ops     ;
            return true_t;
}

bool_t
    fut_clone
        (fut* self, fut* clone) {
            return false_t;
}

void   
    fut_del
        (fut* self)        {
            del (self->fut);
}

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
            if (trait_of(this->task) != task_t) return null_t;
            if (trait_of(self)       != fut_t)  return null_t;
            task* task = this->task;

            for ( ; fut_poll(self) == fut_pend ; cpu_switch(&task->cpu, task->ret));
            any_t  ret = fut_ret (self); del(self);
            return ret;
}