#include "iter.h"
#include "details/iter.h"

iter
    iter_npos()      { 
        iter   ret = { .it = { 0, &__iter_npos } };
        return ret;
}

bool_t 
    iter_same
        (iter par, iter par_cmp) {
            return (par.it[0] == par_cmp.it[0]) && (par.it[1] == par_cmp.it[1]);
}

iter  iter_next(iter par)                { return (__iter_next(&par)) ? par : iter_npos(); }
void* iter_get (iter par)				 { return __iter_get(&par)         ; }
void* iter_set (iter par, void* par_set) { return __iter_set(&par, par_set); }