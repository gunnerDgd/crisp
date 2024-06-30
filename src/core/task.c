#include "task.h"
#include "this.h"

static void
    do_run
        (task* self)                            {
            if (trait_of(self) != task_t) return;
            task* task = this.task;
            this.task  = self;

            self->res  = self->func(self->arg);
            self->stat = fut_ready;

            cpu_switch(&self->cpu, self->ret);
            this.task = task;
}

static u64_t
    do_poll
        (task* self)                                                   {
            if (trait_of(self) != task_t)     return fut_err  ; cpu ret;
            if (!make_at(&ret, cpu) from (0)) return fut_err  ;
            if (self->stat != fut_pend)       return self->stat;
            task* task = this.task;
            this.task  = self;

            self->ret = &ret  ; cpu_switch(&ret, &self->cpu);
            self->ret = null_t;
            del (&ret);

            this.task  = task;
            return self->stat;
}

static any_t
    do_ret
        (task* par)                                   {
            if (trait_of(par) != task_t) return null_t;
            return par->res;
}

static fut_ops
    do_fut = make_fut_ops (
        do_poll,
        do_ret
);

static bool_t
    do_new
        (task* self, u32_t count, va_list par)                           {
            void *func = null_t; if (count > 0) func = va_arg(par, void*);
            void *arg  = null_t; if (count > 1) arg  = va_arg(par, void*);
            if (!func) return false_t;
            u8_t *spa = self->spa;
            u64_t len = 1 MB;
            len -= 40;

            if (!make_at(&self->cpu, cpu) from (0)) return false_t;
            cpu_stack(&self->cpu, spa, len);
            cpu_entry(&self->cpu, do_run);
            cpu_arg  (&self->cpu, self);

            self->stat = fut_pend;
            self->func = func    ;
            self->ret  = null_t  ;
            self->res  = null_t  ;
            self->arg  = arg     ;
            return true_t;
}

static bool_t
    do_clone
        (task* self, task* clone)                                 {
            if (!make_at(&self->cpu, cpu) from (0)) return false_t;
            u8_t *spa = self->spa;
            u64_t len = 1 MB;
            len -= 40;

            cpu_stack(&self->cpu, spa, len);
            cpu_entry(&self->cpu, do_run);
            cpu_arg  (&self->cpu, self);
            self->func = clone->func;
            self->arg  = clone->arg ;
            self->stat = fut_pend;
            self->ret  = null_t  ;
            self->res  = null_t  ;

            return true_t;
}

static void
    do_del
        (task* self)        {
            del (&self->cpu);
}

static obj_trait
    do_obj = make_trait (
        do_new      ,
        do_clone    ,
        null_t      ,
        do_del      ,
        sizeof(task),
        null_t
);

obj_trait *task_t = &do_obj;

fut*
    task_fut
        (task* self)                                   {
            if (trait_of(self) != task_t) return null_t;
            return make (fut) from      (
                2      ,
                &do_fut,
                self
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