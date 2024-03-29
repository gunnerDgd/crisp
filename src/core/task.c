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
        (task* par_task, u32_t par_count, va_list par)                           {
            void *func   = null_t; if (par_count > 0) func   = va_arg(par, void*);
            void *arg    = null_t; if (par_count > 1) arg    = va_arg(par, void*);
            u64_t sp_len = 1 MB  ; if (par_count > 2) sp_len = va_arg(par, u64_t);
            mem  *mem    = null_t; if (par_count > 3) mem    = va_arg(par, any_t);
            if (trait_of(mem) != mem_t) mem = get_mem();
            if (trait_of(mem) != mem_t) return false_t;
            if (!func)                  return false_t;

            if (!make_at(&par_task->cpu  , cpu) from (0))              return false_t;
            if (!make_at(&par_task->stack, box) from (2, sp_len, mem)) return false_t;

            cpu_stack(&par_task->cpu, box_ptr(&par_task->stack), sp_len - 24);
            cpu_entry(&par_task->cpu, task_do_run);
            cpu_arg  (&par_task->cpu, par_task)   ;
            par_task->stat   = fut_pend;
            par_task->func   = func    ;
            par_task->ret    = null_t  ;
            par_task->res    = null_t  ;
            par_task->arg    = arg     ;
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
        (task* par)          {
            del (&par->stack);
            del (&par->cpu)  ;
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
        (void*(*par)(void*), void* par_arg)               {
            task *ret = make (task) from (2, par, par_arg);
            fut  *fut = task_fut(ret)                     ;
            if (trait_of(ret) != task_t) return null_t;
            if (trait_of(fut) != fut_t)  return null_t;
            del(ret);

            return fut;
}