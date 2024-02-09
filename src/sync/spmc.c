#include "spmc.h"

#include "../atom.h"
#include "../bit.h"

obj_trait spmc_trait     = {
    .on_new   = &spmc_new  ,
    .on_clone = &spmc_clone,
    .on_ref   = 0          ,
    .on_del   = &spmc_del  ,
    .size     = sizeof(spmc)
};

obj_trait *spmc_t = &spmc_trait;

bool_t 
    spmc_new
        (spmc* par_spsc, u32_t par_count, va_list par)           {
            mem_set(par_spsc->spmc, 0x00, sizeof(par_spsc->spmc));
            par_spsc->enq = 0;
            par_spsc->deq = 0;
            return true_t;
}

bool_t 
    spmc_clone
        (spmc* par, spmc* par_clone) {
            return false_t;
}

void   
    spmc_del
        (spmc* par)                      {
            while (par->enq != par->deq) {
                del (par->spmc[par->deq]);
                par->deq += 1       ;
                par->deq &= mask(10);
            }
}

bool_t
    spmc_enq_try
        (spmc* par, obj* par_enq)                          {
            if (trait_of(par)     != spmc_t) return false_t;
            if (trait_of(par_enq) == null_t) return false_t;
            u64_t pos = par->enq            ;
            u64_t enq = (pos + 1) & mask(10);

            if    (enq == par->deq) return false_t;
            while (par->spmc[pos]);

            par->spmc[pos] = ref(par_enq);
            par->enq       = pos         ;
            return true_t;
            
}

void 
    spmc_enq
        (spmc* par, obj* par_enq)                  {
            if (trait_of(par)     != spmc_t) return;
            if (trait_of(par_enq) == null_t) return;
            while (!spmc_enq_try(par, par_enq));
}

obj* 
    spmc_deq_try
        (spmc* par)                                   {
            if (trait_of(par) != spmc_t) return null_t;
            u64_t pos = par->deq            ;
            u64_t deq = (pos + 1) & mask(10);
            obj  *ret = 0                   ;

            if    (pos == par->enq)                          return null_t;
            if    (lock_cas_ptr(&par->deq, pos, deq) != pos) return null_t;
            while (!par->spmc[pos]);

            ret = par->spmc[pos];
            par->spmc[pos]   = 0;
            del   (ret);
            return ret;
}

obj* 
    spmc_deq
        (spmc* par)                                             {
            if (trait_of(par) != spmc_t) return null_t; obj* ret;
            while (!(ret = spmc_deq_try(par)));
            return   ret;
}