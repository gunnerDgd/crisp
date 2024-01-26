#include "task.h"
#include "sched.h"

void
    task_main
        (task* par)                            {
            if (!par)                    return;
            if (trait_of(par) != task_t) return;

            par->stat = task_run ; par->ret = par->func(par, par->arg);
            par->stat = task_none;
            task_yield(par);
}

obj_trait task_trait     = {
    .on_new   = &task_new  ,
    .on_clone = &task_clone,
    .on_ref   = 0          ,
    .on_del   = &task_del  ,
    .size     = sizeof(task)
};

obj_trait *task_t = &task_trait;

bool_t
    task_new
        (task* par_task, u32_t par_count, va_list par)                     {
            void*  func  = 0; if (par_count > 0) func  = va_arg(par, void*);
            void*  arg   = 0; if (par_count > 1) arg   = va_arg(par, void*);
            u64_t  stack = 0; if (par_count > 2) stack = va_arg(par, u64_t);
            u64_t  len   = 0; if (par_count > 3) len   = va_arg(par, u64_t);

            if (!par_count)                                                {
                if (!make_at(&par_task->cpu, cpu_t) from(0)) return false_t;
                par_task->stat = task_run;
                return true_t;
            }

            if (!make_at(&par_task->cpu, cpu_t) from(0)) return false_t;
            if (!func)                                   return false_t;
            if (!stack)                                  return false_t;
            if (!len)                                    return false_t;
            
            cpu_stack(&par_task->cpu, stack, len);
            cpu_entry(&par_task->cpu, task_main) ;
            cpu_arg  (&par_task->cpu, par_task)  ;
            par_task->stat   = task_none;
            par_task->func   = func     ;
            par_task->arg    = arg      ;

            par_task->sp_len = len      ;
            par_task->sp     = stack    ;
            return true_t;
}

bool_t 
    task_clone
        (task* par, task* par_clone)   {
            par->func = par_clone->func;
            par->arg  = par_clone->arg ;
            return true_t;
}

void   
    task_del
        (task* par)       {
            del(&par->cpu);
}

void   
    task_switch
        (task* par, task* par_task)                 {
            if (!par_task)                    return;
            if (!par)                         return;
            if (trait_of(par_task) != task_t) return;
            if (trait_of(par)      != task_t) return;
            if (par_task->pend)               return;

            par_task->pend = par; cpu_switch(&par->cpu, &par_task->cpu);
            par_task->pend = 0  ;
            if (par_task->stat == task_none)                             {
                cpu_stack(&par_task->cpu, par_task->sp, par_task->sp_len);
                cpu_entry(&par_task->cpu, task_main) ;
                cpu_arg  (&par_task->cpu, par_task)  ;
            }
}

void
    task_yield
        (task* par)                                  {
            if (!par)                          return;
            if (trait_of(par)       != task_t) return;
            if (trait_of(par->pend) != task_t) return;

            if (par->stat == task_pend)        return               ;
            if (par->stat != task_none)        par->stat = task_pend;
            cpu_switch(&par->cpu, &par->pend->cpu);
            par->stat = task_run;
}

u64_t  
    task_poll
        (task* par)                                     {
            if (!par)                    return task_err;
            if (trait_of(par) != task_t) return task_err;
            return par->stat;
}

void* 
    task_ret
        (task* par)                              {
            if (!par)                    return 0;
            if (trait_of(par) != task_t) return 0;
            return par->ret;
}