#include "mpmc.h"

#include "../atom.h"
#include "../bit.h"

obj_trait mpmc_trait     = {
    .on_new   = &mpmc_new  ,
    .on_clone = &mpmc_clone,
    .on_ref   = 0          ,
    .on_del   = &mpmc_del  ,
    .size     = sizeof(mpmc)
};

obj_trait *mpmc_t = &mpmc_trait;

bool_t 
    mpmc_new
        (mpmc* par_spsc, u32_t par_count, va_list par)           {
            mem_set(par_spsc->mpmc, 0x00, sizeof(par_spsc->mpmc));
            par_spsc->enq = 0;
            par_spsc->deq = 0;
            return true_t;
}

bool_t 
    mpmc_clone
        (mpmc* par, mpmc* par_clone) {
            return false_t;
}

void   
    mpmc_del
        (mpmc* par)                       {
            while (par->enq != par->deq)  {
                del  (par->mpmc[par->deq]);
                par->deq += 1       ;
                par->deq &= mask(10);
            }
}

bool_t
    mpmc_enq_try
        (mpmc* par, obj* par_enq)                          {
            if (trait_of(par)     != mpmc_t) return false_t;
            if (trait_of(par_enq) == null_t) return false_t;
            u64_t pos = par->enq            ;
            u64_t enq = (pos + 1) & mask(10);
            ref  (par_enq);

            if    (enq == par->deq)                                return false_t;
            if    (lock_cas_ptr(&par->enq, pos, enq) != pos)       return false_t;
            while (lock_cas_ptr(&par->mpmc[pos], null_t, par_enq));
            return true_t;
            
}

void 
    mpmc_enq
        (mpmc* par, obj* par_enq)                  {
            if (trait_of(par)     != mpmc_t) return;
            if (trait_of(par_enq) == null_t) return;
            while (!mpmc_enq_try(par, par_enq));
}

obj* 
    mpmc_deq_try
        (mpmc* par)                                   {
            if (trait_of(par) != mpmc_t) return null_t;
            u64_t pos = par->deq            ;
            u64_t deq = (pos + 1) & mask(10);
            obj  *ret = par->mpmc[pos]      ;

            if    (pos == par->enq)                                   return null_t;
            if    (!ret)                                              return null_t;
            if    (lock_cas_ptr(&par->deq, pos, deq)          != pos) return null_t;
            while (lock_cas_ptr(&par->mpmc[pos], ret, null_t) != ret) ret = par->mpmc[pos];
            del   (ret);
            return ret;
}

obj* 
    mpmc_deq
        (mpmc* par)                                             {
            if (trait_of(par) != mpmc_t) return null_t; obj* ret;
            while (!(ret = mpmc_deq_try(par)));
            return   ret;
}