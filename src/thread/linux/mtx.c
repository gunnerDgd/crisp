#include "mtx.h"

obj_trait mtx_trait = make_trait (
    mtx_new    ,
    mtx_clone  ,
    null_t     ,
    mtx_del    ,
    sizeof(mtx),
    null_t
);

obj_trait *mtx_t = &mtx_trait;

bool_t
    mtx_new
        (mtx* par_mtx, u32_t par_count, va_list par)             {
            return pthread_mutex_init(&par_mtx->mtx, null_t) == 0;
}

bool_t
    mtx_clone
        (mtx* par, mtx* par_clone) {
            return false_t;
}

void
    mtx_del
        (mtx* par)                          {
            pthread_mutex_destroy(&par->mtx);
}

bool_t
    mtx_lock_try
        (mtx* par)                                              {
            if (trait_of(par) != mtx_t)           return false_t;
            if (pthread_mutex_trylock(&par->mtx)) return false_t;
            return true_t;
}

void
    mtx_lock
        (mtx* par)                            {
            if (trait_of(par) != mtx_t) return;
            pthread_mutex_lock(&par->mtx);

}

void
    mtx_unlock
        (mtx* par)                            {
            if (trait_of(par) != mtx_t) return;
            pthread_mutex_unlock(&par->mtx);
}