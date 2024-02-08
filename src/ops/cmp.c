#include "cmp.h"
#include "../obj.h"

ord_t  
    ord(struct obj* par, any_t par_arg)                         {
        obj*       cmp   = par       ; if (!cmp)   return null_t;
        any_t      arg   = par_arg   ; if (!arg)   return null_t;
        obj_trait *trait = cmp->trait; if (!trait) return null_t;
        obj_ops   *ops   = trait->ops; if (!ops)   return null_t;

        if (!ops->cmp)      return null_t;
        if (!ops->cmp->ord) return null_t;
        return ops->cmp->ord(cmp, arg);
}

bool_t 
    gt(struct obj* par, any_t par_arg)                          {
        obj*       cmp   = par       ; if (!cmp)   return null_t;
        any_t      arg   = par_arg   ; if (!arg)   return null_t;
        obj_trait *trait = cmp->trait; if (!trait) return null_t;
        obj_ops   *ops   = trait->ops; if (!ops)   return null_t;

        if (!ops->cmp)      return null_t;
        if (!ops->cmp->ord) return null_t;
        return ord(cmp, arg) == ord_gt;
}

bool_t 
    gt_eq(struct obj* par, any_t par_arg)                        {
        obj*       cmp   = par       ; if (!cmp)   return false_t;
        any_t      arg   = par_arg   ; if (!arg)   return false_t;
        obj_trait *trait = cmp->trait; if (!trait) return false_t;
        obj_ops   *ops   = trait->ops; if (!ops)   return false_t;

        if (!ops->cmp)               return false_t;
        if (!ops->cmp->ord)          return false_t;
        if (ord(cmp, arg) == ord_lt) return false_t;
        return true_t;
}


bool_t 
    lt(struct obj* par, any_t par_arg)                          {
        obj*       cmp   = par       ; if (!cmp)   return null_t;
        any_t      arg   = par_arg   ; if (!arg)   return null_t;
        obj_trait *trait = cmp->trait; if (!trait) return null_t;
        obj_ops   *ops   = trait->ops; if (!ops)   return null_t;

        if (!ops->cmp)      return null_t;
        if (!ops->cmp->ord) return null_t;
        return ord(cmp, arg) == ord_lt;
}

bool_t 
    lt_eq(struct obj* par, any_t par_arg)                        {
        obj*       cmp   = par       ; if (!cmp)   return false_t;
        any_t      arg   = par_arg   ; if (!arg)   return false_t;
        obj_trait *trait = cmp->trait; if (!trait) return false_t;
        obj_ops   *ops   = trait->ops; if (!ops)   return false_t;

        if (!ops->cmp)               return false_t;
        if (!ops->cmp->ord)          return false_t;
        if (ord(cmp, arg) == ord_gt) return false_t;
        return true_t;
}

bool_t 
    eq(struct obj* par, any_t par_arg)                          {
        obj*       cmp   = par       ; if (!cmp)   return null_t;
        any_t      arg   = par_arg   ; if (!arg)   return null_t;
        obj_trait *trait = cmp->trait; if (!trait) return null_t;
        obj_ops   *ops   = trait->ops; if (!ops)   return null_t;

        if (!ops->cmp)      return null_t;
        if (!ops->cmp->ord) return null_t;
        return ord(cmp, arg) == ord_eq;
}

bool_t 
    ne(struct obj* par, any_t par_arg)                          {
        obj*       cmp   = par       ; if (!cmp)   return null_t;
        any_t      arg   = par_arg   ; if (!arg)   return null_t;
        obj_trait *trait = cmp->trait; if (!trait) return null_t;
        obj_ops   *ops   = trait->ops; if (!ops)   return null_t;

        if (!ops->cmp)      return null_t;
        if (!ops->cmp->ord) return null_t;
        return ord(cmp, arg) != ord_eq;
}