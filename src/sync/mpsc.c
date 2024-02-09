#include "mpsc.h"

#include "../atom.h"
#include "../bit.h"

obj_trait mpsc_trait     = {
    .on_new   = &mpsc_new  ,
    .on_clone = &mpsc_clone,
    .on_ref   = 0          ,
    .on_del   = &mpsc_del  ,
    .size     = sizeof(mpsc)
};

obj_trait *mpsc_t = &mpsc_trait;

bool_t 
    mpsc_new
        (mpsc* par_spsc, u32_t par_count, va_list par)           {
            mem_set(par_spsc->mpsc, 0x00, sizeof(par_spsc->mpsc));
            par_spsc->enq = 0;
            par_spsc->deq = 0;
            return true_t;
}

bool_t 
    mpsc_clone
        (mpsc* par, mpsc* par_clone) {
            return false_t;
}

void   
    mpsc_del
        (mpsc* par)                       {
            while (par->enq != par->deq)  {
                del  (par->mpsc[par->deq]);
                par->deq += 1       ;
                par->deq &= mask(10);
            }
}

bool_t
    mpsc_enq_try
        (mpsc* par, obj* par_enq)                          {
            if (trait_of(par)     != mpsc_t) return false_t;
            if (trait_of(par_enq) == null_t) return false_t;
            u64_t pos = par->enq            ;
            u64_t enq = (pos + 1) & mask(10);

            if    (enq == par->deq)                          return false_t;
            if    (lock_cas_ptr(&par->enq, pos, enq) != pos) return false_t;
            while (par->mpsc[pos]);

            par->mpsc[pos] = ref(par_enq);
            return true_t;
            
}

void 
    mpsc_enq
        (mpsc* par, obj* par_enq)                  {
            if (trait_of(par)     != mpsc_t) return;
            if (trait_of(par_enq) == null_t) return;
            while (!mpsc_enq_try(par, par_enq));
}

obj* 
    mpsc_deq_try
        (mpsc* par)                                   {
            if (trait_of(par) != mpsc_t) return null_t;
            u64_t pos = par->deq            ;
            u64_t deq = (pos + 1) & mask(10);
            obj  *ret = 0                   ;

            if    (pos == par->enq) return null_t;
            while (!par->mpsc[pos]);

            ret            = par->mpsc[pos];
            par->mpsc[pos] = 0  ;
            par->deq       = deq;
            del   (ret);
            return ret;
}

obj* 
    mpsc_deq
        (mpsc* par)                                             {
            if (trait_of(par) != mpsc_t) return null_t; obj* ret;
            while (!(ret = mpsc_deq_try(par)));
            return   ret;
}