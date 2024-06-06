#include "task.h"
#include "this.h"

void
    task_do_run
        (task* par)                                  {
            if (trait_of(par)       != task_t) return;
            if (trait_of(&par->cpu) != cpu_t)  return;
            task* task = this->task;
            this->task = par       ;

            par->res   = par->func(par->arg);
            par->stat  = fut_ready          ;
            cpu_switch(&par->cpu, par->ret);
            this->task = task;
}

u64_t  
    task_do_poll
        (task* par)                                                    {
            if (trait_of(par) != task_t)      return fut_err  ; cpu ret;
            if (!make_at(&ret, cpu) from (0)) return fut_err  ;
            if (par->stat != fut_pend)        return par->stat;
            task* task = this->task;
            this->task = par       ;

            par->ret = &ret  ; cpu_switch(&ret, &par->cpu);
            par->ret = null_t;
            del (&ret);

            this->task = task;
            return par->stat ;
}

void* 
    task_do_ret
        (task* par)                                   {
            if (trait_of(par) != task_t) return null_t;
            return par->ret;
}

fut_ops task_fut_ops = make_fut_ops (
    task_do_poll,
    task_do_ret
);

obj_trait task_trait = make_trait (
        task_new    ,
        task_clone  ,
        null_t      ,
        task_del    ,
        sizeof(task),
        null_t
);

obj_trait *task_t = &task_trait;

bool_t
    task_new
        (task* self, u32_t count, va_list par)                           {
            void *func = null_t; if (count > 0) func = va_arg(par, void*);
            void *arg  = null_t; if (count > 1) arg  = va_arg(par, void*);
            if (!func) return false_t;
            u8_t *spa = self->spa;
            u64_t len = 1 MB;
            spa += 1 MB;
            spa -= 24;
            len -= 24;

            if (!make_at(&self->cpu, cpu) from (0)) return false_t;
            cpu_entry(&self->cpu, task_do_run);
            cpu_stack(&self->cpu, spa, len);
            cpu_arg  (&self->cpu, self);

            self->stat   = fut_pend;
            self->func   = func    ;
            self->ret    = null_t  ;
            self->res    = null_t  ;
            self->arg    = arg     ;
            return true_t;
}

bool_t
    task_clone
        (task* par, task* par_clone)   {
            par->func = par_clone->func;
            par->arg  = par_clone->arg ;
            par->stat = fut_pend;
            return true_t;
}

void   
    task_del
        (task* par)        {
            del (&par->cpu);
}

fut*
    task_fut
        (task* par)                                   {
            if (trait_of(par) != task_t) return null_t;
            return make (fut) from                    (
                2            ,
                &task_fut_ops,
                par
            );
}

fut*
    async
        (void*(*func)(void*), void* arg)               {
            task *ret = make (task) from (2, func, arg);
            fut  *fut = task_fut(ret)                  ;
            if (trait_of(ret) != task_t) return null_t;
            if (trait_of(fut) != fut_t)  return null_t;
            del(ret);

            return fut;
}