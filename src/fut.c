#include "fut.h"

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
        (fut* par, fut* par_clone) {
            return false_t;
}

void   
    fut_del
        (fut* par)        {
            del (par->fut);
}

u64_t  
    fut_poll
        (fut* par)                                    {
            if (!par)                   return fut_err;
            if (trait_of(par) != fut_t) return fut_err;
            
            par->stat = par->ops->poll(par->fut);
            if (par->stat == fut_ready) par->ret = par->ops->ret(par->fut);
            if (par->stat == fut_err)   par->ret = par->ops->ret(par->fut);
            return par->stat;
}

void*
    fut_ret
        (fut* par)                                   {
            if (!par)                   return null_t;
            if (trait_of(par) != fut_t) return null_t;
            if (par->stat == fut_pend)  return null_t;
            return par->ret;
}