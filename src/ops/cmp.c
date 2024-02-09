#include "cmp.h"
#include "../obj.h"

ord_t  
    op_ord(struct obj* par, any_t par_arg)                 {
        obj*       cmp   = par       ; if (!cmp)   return 0;
        any_t      arg   = par_arg   ; if (!arg)   return 0;
        obj_trait *trait = cmp->trait; if (!trait) return 0;
        obj_ops   *ops   = trait->ops; if (!ops)   return 0;

        if (!ops->cmp)      return 0;
        if (!ops->cmp->ord) return 0;
        return ops->cmp->ord(cmp, arg);
}

bool_t 
    op_gt(struct obj* par, any_t par_arg)                        {
        obj*       cmp   = par       ; if (!cmp)   return false_t;
        any_t      arg   = par_arg   ; if (!arg)   return false_t;
        obj_trait *trait = cmp->trait; if (!trait) return false_t;
        obj_ops   *ops   = trait->ops; if (!ops)   return false_t;

        if (!ops->cmp)      return false_t;
        if (!ops->cmp->ord) return false_t;
        return op_ord(cmp, arg) == ord_gt;
}

bool_t 
    op_gt_eq(struct obj* par, any_t par_arg)                     {
        obj*       cmp   = par       ; if (!cmp)   return false_t;
        any_t      arg   = par_arg   ; if (!arg)   return false_t;
        obj_trait *trait = cmp->trait; if (!trait) return false_t;
        obj_ops   *ops   = trait->ops; if (!ops)   return false_t;

        if (!ops->cmp)                  return false_t;
        if (!ops->cmp->ord)             return false_t;
        if (op_ord(cmp, arg) == ord_lt) return false_t;
        return true_t;
}


bool_t 
    op_lt(struct obj* par, any_t par_arg)                        {
        obj*       cmp   = par       ; if (!cmp)   return false_t;
        any_t      arg   = par_arg   ; if (!arg)   return false_t;
        obj_trait *trait = cmp->trait; if (!trait) return false_t;
        obj_ops   *ops   = trait->ops; if (!ops)   return false_t;

        if (!ops->cmp)      return false_t;
        if (!ops->cmp->ord) return false_t;
        return op_ord(cmp, arg) == ord_lt;
}

bool_t 
    op_lt_eq(struct obj* par, any_t par_arg)                     {
        obj*       cmp   = par       ; if (!cmp)   return false_t;
        any_t      arg   = par_arg   ; if (!arg)   return false_t;
        obj_trait *trait = cmp->trait; if (!trait) return false_t;
        obj_ops   *ops   = trait->ops; if (!ops)   return false_t;

        if (!ops->cmp)                  return false_t;
        if (!ops->cmp->ord)             return false_t;
        if (op_ord(cmp, arg) == ord_gt) return false_t;
        return true_t;
}

bool_t 
    op_eq(struct obj* par, any_t par_arg)                        {
        obj*       cmp   = par       ; if (!cmp)   return false_t;
        any_t      arg   = par_arg   ; if (!arg)   return false_t;
        obj_trait *trait = cmp->trait; if (!trait) return false_t;
        obj_ops   *ops   = trait->ops; if (!ops)   return false_t;

        if (!ops->cmp)      return false_t;
        if (!ops->cmp->ord) return false_t;
        return op_ord(cmp, arg) == ord_eq;
}

bool_t 
    op_ne(struct obj* par, any_t par_arg)                        {
        obj*       cmp   = par       ; if (!cmp)   return false_t;
        any_t      arg   = par_arg   ; if (!arg)   return false_t;
        obj_trait *trait = cmp->trait; if (!trait) return false_t;
        obj_ops   *ops   = trait->ops; if (!ops)   return false_t;

        if (!ops->cmp)      return false_t;
        if (!ops->cmp->ord) return false_t;
        return op_ord(cmp, arg) != ord_eq;
}