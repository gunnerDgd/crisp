#include "sched.h"
#include "task.h"

obj_trait sched_trait     = {
    .on_new   = &sched_new  ,
    .on_clone = &sched_clone,
    .on_ref   = 0           ,
    .on_del   = &sched_del  ,
    .size     = sizeof(sched)
};

obj_trait *sched_t = &sched_trait;

bool_t       
    sched_new
        (sched* par_sched, u32_t par_count, va_list par)                    {
            u64_t sp_len = 0; if (par_count > 0) sp_len = va_arg(par, u64_t);
            mem  *sp     = 0; if (par_count > 1) sp     = va_arg(par, mem*) ;

            if (!make_at(&par_sched->task, task_t) from (0)) return false_t;
            if (!make_at(&par_sched->run , list_t) from (0)) return false_t;
            if (!sp_len)     sp_len = 1 MB ;
            if (!sp)         sp = get_mem();
            if (!sp)         return false_t;
            if (!sp->on_new) return false_t;
            if (!sp->on_del) return false_t;

            par_sched->sp_len = sp_len;
            par_sched->sp     = sp    ;
            par_sched->cur    = 0     ;
            return true_t;
}

bool_t
    sched_clone
        (sched* par, sched* par_clone) {
            return false_t;
}

void         
    sched_del
        (sched* par)                                  {
            list_for (&par->task, run_node)           {
                task *run = value_as(run_node, task*) ;
                if  (!run)                    continue;
                if  (trait_of(run) != task_t) continue;
                
                mem_del(par->sp, run->sp);
            }
            del (&par->task);
            del (&par->run) ; 
}

fut*
    sched_dispatch
        (sched* par, void*(*par_func)(task*, void*), void* par_arg) {
            if (!par_func)                return;
            if (!par)                     return;
            if (trait_of(par) != sched_t) return;

            u64_t sp_len = par->sp_len             ; if (!sp_len) return;
            u64_t sp     = mem_new(par->sp, sp_len); if (!sp)     return;
            task *ret    = make (task_t) from      (
                4         ,
                par_func  ,
                par_arg   ,
                sp        ,
                sp_len - 24
            );

            if (!ret)                    return;
            if (trait_of(ret) != task_t) return;

            list_push_back(&par->run, ret);
            if (!par->cur)  par->cur = list_begin(&par->run);
            return task_fut(ret);
}

bool_t
    sched_idle
        (sched* par)                              {
            if (!par)                     return 0;
            if (trait_of(par) != sched_t) return 0;
            return list_empty(&par->run);
}

void
    sched_run
        (sched* par)                            {
            if (!par)                     return;
            if (trait_of(par) != sched_t) return;
            if (!par->cur)                return;

            node *run_node = par->cur       ;
            task *run      = value(run_node);
            if (!run_node)                    return 0;
            if (!run)                         return 0;
            if (trait_of(run_node) != node_t) return 0;
            if (trait_of(run)      != task_t) return 0;
            par->cur = next(run_node);

            task_switch(&par->task, run);
            if (run->stat == fut_ready)  {
                mem_del(par->sp, run->sp);
                del    (run_node);
                del    (run)     ;
            }

            if (par->cur == list_end(&par->run)) par->cur = list_begin(&par->run);
            if (par->cur == list_end(&par->run)) par->cur = 0;
}