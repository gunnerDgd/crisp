#include "logical.h"
#include "../obj.h"

struct obj* 
    log_and(struct obj* par, any_t par_arg)                     {
        obj*       and   = par       ; if (!and)   return null_t;
        any_t      arg   = par_arg   ; if (!arg)   return null_t;
        obj_trait *trait = and->trait; if (!trait) return null_t;
        obj_ops   *ops   = trait->ops; if (!ops)   return null_t;

        if (!ops->logical)      return null_t;
        if (!ops->logical->and) return null_t;
        return ops->logical->and(and, arg);
}

struct obj* 
    log_or(struct obj* par, any_t par_arg)                      {
        obj*       or    = par       ; if (!or)    return null_t;
        any_t      arg   = par_arg   ; if (!arg)   return null_t;
        obj_trait *trait = or->trait ; if (!trait) return null_t;
        obj_ops   *ops   = trait->ops; if (!ops)   return null_t;

        if (!ops->logical)     return null_t;
        if (!ops->logical->or) return null_t;
        return ops->logical->or(or, arg);
}

struct obj* 
    log_not(struct obj* par)                                    {
        obj*       not   = par       ; if (!not)   return null_t;
        obj_trait *trait = not->trait; if (!trait) return null_t;
        obj_ops   *ops   = trait->ops; if (!ops)   return null_t;

        if (!ops->logical)      return null_t;
        if (!ops->logical->not) return null_t;
        return ops->logical->not(not);
}