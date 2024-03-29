#include "mtx.h"
#include <Windows.h>

obj_trait mtx_trait = make_trait (
    mtx_new    ,
    mtx_clone  ,
    null_t     ,
    mtx_del    ,
    sizeof(mtx),
    null_t
);

obj_trait* mtx_t = &mtx_trait;

bool_t 
    mtx_new
        (mtx* par_mtx, u32_t par_count, va_list par)        {
            par_mtx->mtx = CreateMutex(null_t, TRUE, null_t);
            return par_mtx->mtx != INVALID_HANDLE_VALUE;
}

bool_t 
    mtx_clone
        (mtx* par, mtx* par_clone) {
            return false_t;
}

void
    mtx_del
        (mtx* par)               {
            CloseHandle(par->mtx);
}

bool_t 
    mtx_lock_try
        (mtx* par)                                    {
            if (trait_of(par) != mtx_t) return false_t;
            return WaitForSingleObject(par->mtx, 0) == WAIT_OBJECT_0;
}

void   
    mtx_lock
        (mtx* par)                                    {
            if (trait_of(par) != mtx_t) return false_t;
            return WaitForSingleObject(par->mtx, INFINITE);
}

void   
    mtx_unlock
        (mtx* par)                                    {
            if (trait_of(par) != mtx_t) return false_t;
            ReleaseMutex(&par->mtx);
}