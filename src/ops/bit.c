#include "bit.h"
#include "../obj.h"

struct obj* 
    and(struct obj* par, any_t par_arg)                         {
        obj*       and   = par       ; if (!and)   return null_t;
        any_t      arg   = par_arg   ; if (!arg)   return null_t;
        obj_trait *trait = and->trait; if (!trait) return null_t;
        obj_ops   *ops   = trait->ops; if (!ops)   return null_t;

        if (!ops->bit)      return null_t;
        if (!ops->bit->and) return null_t;
        return ops->bit->and(and, arg);
}

struct obj* 
    and_eq(struct obj* par, any_t par_arg)                      {
        obj*       and   = par       ; if (!and)   return null_t;
        any_t      arg   = par_arg   ; if (!arg)   return null_t;
        obj_trait *trait = and->trait; if (!trait) return null_t;
        obj_ops   *ops   = trait->ops; if (!ops)   return null_t;

        if (!ops->bit)         return null_t;
        if (!ops->bit->and_eq) return null_t;
        ops->bit->and(and, arg);
        return and;
}


struct obj* 
    or(struct obj* par, any_t par_arg)                          {
        obj*       or    = par       ; if (!or)    return null_t;
        any_t      arg   = par_arg   ; if (!arg)   return null_t;
        obj_trait *trait = or->trait ; if (!trait) return null_t;
        obj_ops   *ops   = trait->ops; if (!ops)   return null_t;

        if (!ops->bit)     return null_t;
        if (!ops->bit->or) return null_t;
        return ops->bit->or(or, arg);
}

struct obj* 
    or_eq(struct obj* par, any_t par_arg)                       {
        obj*       or    = par       ; if (!or)    return null_t;
        any_t      arg   = par_arg   ; if (!arg)   return null_t;
        obj_trait *trait = or->trait ; if (!trait) return null_t;
        obj_ops   *ops   = trait->ops; if (!ops)   return null_t;
        
        if (!ops->bit)        return null_t;
        if (!ops->bit->or_eq) return null_t;
        ops->bit->or(or, arg);
        return or;
}


struct obj* 
    xor(struct obj* par, any_t par_arg)                         {
        obj*       xor   = par       ; if (!xor)   return null_t;
        any_t      arg   = par_arg   ; if (!arg)   return null_t;
        obj_trait *trait = xor->trait; if (!trait) return null_t;
        obj_ops   *ops   = trait->ops; if (!ops)   return null_t;
        
        if (!ops->bit)      return null_t;
        if (!ops->bit->xor) return null_t;
        return ops->bit->xor(xor, arg);
}

struct obj* 
    xor_eq(struct obj* par, any_t par_arg)                      {
        obj*       xor   = par       ; if (!xor)   return null_t;
        any_t      arg   = par_arg   ; if (!arg)   return null_t;
        obj_trait *trait = xor->trait; if (!trait) return null_t;
        obj_ops   *ops   = trait->ops; if (!ops)   return null_t;
        
        if (!ops->bit)         return null_t;
        if (!ops->bit->xor_eq) return null_t;
        ops->bit->xor_eq(xor, arg);
        return xor;
}


struct obj* 
    not(struct obj* par)                                        {
        obj*       not   = par       ; if (!not)   return null_t;
        obj_trait *trait = not->trait; if (!trait) return null_t;
        obj_ops   *ops   = trait->ops; if (!ops)   return null_t;
        if (!ops->bit)      return null_t;
        if (!ops->bit->not) return null_t;
        return ops->bit->not(not);
}