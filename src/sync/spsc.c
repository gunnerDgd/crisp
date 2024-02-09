#include "spsc.h"

#include "../atom.h"
#include "../bit.h"

obj_trait spsc_trait     = {
    .on_new   = &spsc_new  ,
    .on_clone = &spsc_clone,
    .on_ref   = 0          ,
    .on_del   = &spsc_del  ,
    .size     = sizeof(spsc)
};

obj_trait *spsc_t = &spsc_trait;

bool_t 
    spsc_new
        (spsc* par_spsc, u32_t par_count, va_list par)           {
            mem_set(par_spsc->spsc, 0x00, sizeof(par_spsc->spsc));
            par_spsc->enq = 0;
            par_spsc->deq = 0;
            return true_t;
}

bool_t 
    spsc_clone
        (spsc* par, spsc* par_clone) {
            return false_t;
}

void   
    spsc_del
        (spsc* par)                           {
            while (par->enq != par->deq)      {
                obj *ret = par->spsc[par->deq];
                del (ret);

                par->deq += 1       ;
                par->deq &= mask(10);
            }
}

bool_t
    spsc_enq_try
        (spsc* par, obj* par_enq)                      {
            if (trait_of(par) != spsc_t) return false_t;
            u64_t pos = par->enq            ;
            u64_t enq = (pos + 1) & mask(10);

            if (enq == par->deq) return false_t;
            par->spsc[pos] = ref(par_enq);
            par->enq       = enq         ;
            return true_t;
            
}

void 
    spsc_enq
        (spsc* par, obj* par_enq)              {
            if (trait_of(par) != spsc_t) return;
            while (!spsc_enq_try(par, par_enq));
}

obj* 
    spsc_deq_try
        (spsc* par)                                   {
            if (trait_of(par) != spsc_t) return null_t;
            u64_t pos = par->deq            ;
            u64_t deq = (pos + 1) & mask(10);
            obj  *ret = par->spsc[pos]      ;

            if (pos == par->enq) return null_t;
            par->deq = deq;
            del   (ret);
            return ret ;
}

obj* 
    spsc_deq
        (spsc* par)                                             {
            if (trait_of(par) != spsc_t) return null_t; obj* ret;
            while (!(ret = spsc_deq_try(par)));
            return   ret;
}