#include "arith.h"
#include "../obj.h"

struct obj* 
    add(struct obj* par, any_t par_arg)                         {
        obj*       add   = par       ; if (!add)   return null_t;
        any_t      arg   = par_arg   ; if (!arg)   return null_t;
        obj_trait *trait = add->trait; if (!trait) return null_t;
        obj_ops   *ops   = trait->ops; if (!ops)   return null_t;

        if (!ops->arith)      return null_t;
        if (!ops->arith->add) return null_t;
        return ops->arith->add(add, arg);
}

struct obj* 
    add_eq(struct obj* par, any_t par_arg)                      {
        obj*       add   = par       ; if (!add)   return null_t;
        any_t      arg   = par_arg   ; if (!arg)   return null_t;
        obj_trait *trait = add->trait; if (!trait) return null_t;
        obj_ops   *ops   = trait->ops; if (!ops)   return null_t;

        if (!ops->arith)         return null_t;
        if (!ops->arith->add_eq) return null_t;
        ops->arith->add_eq(add, arg);
        return add;
}


struct obj* 
    sub(struct obj* par, any_t par_arg)                         {
        obj*       sub   = par       ; if (!sub)   return null_t;
        any_t      arg   = par_arg   ; if (!arg)   return null_t;
        obj_trait *trait = sub->trait; if (!trait) return null_t;
        obj_ops   *ops   = trait->ops; if (!ops)   return null_t;

        if (!ops->arith)      return null_t;
        if (!ops->arith->sub) return null_t;
        return ops->arith->sub(sub, arg);
}

struct obj* 
    sub_eq(struct obj* par, any_t par_arg)                      {
        obj*       sub   = par       ; if (!sub)   return null_t;
        any_t      arg   = par_arg   ; if (!arg)   return null_t;
        obj_trait *trait = sub->trait; if (!trait) return null_t;
        obj_ops   *ops   = trait->ops; if (!ops)   return null_t;
        
        if (!ops->arith)         return null_t;
        if (!ops->arith->sub_eq) return null_t;
        ops->arith->sub_eq(sub, arg);
        return sub;
}


struct obj* 
    mul(struct obj* par, any_t par_arg)                         {
        obj*       mul   = par       ; if (!mul)   return null_t;
        any_t      arg   = par_arg   ; if (!arg)   return null_t;
        obj_trait *trait = mul->trait; if (!trait) return null_t;
        obj_ops   *ops   = trait->ops; if (!ops)   return null_t;
        
        if (!ops->arith)      return null_t;
        if (!ops->arith->mul) return null_t;
        return ops->arith->mul(mul, arg);
}

struct obj* 
    mul_eq(struct obj* par, any_t par_arg)                         {
        obj*       mul   = par       ; if (!mul)   return null_t;
        any_t      arg   = par_arg   ; if (!arg)   return null_t;
        obj_trait *trait = mul->trait; if (!trait) return null_t;
        obj_ops   *ops   = trait->ops; if (!ops)   return null_t;
        
        if (!ops->arith)         return null_t;
        if (!ops->arith->mul_eq) return null_t;
        ops->arith->mul_eq(mul, arg);
        return mul;
}


struct obj* 
    div(struct obj* par, any_t par_arg)                         {
        obj*       div   = par       ; if (!div)   return null_t;
        any_t      arg   = par_arg   ; if (!arg)   return null_t;
        obj_trait *trait = div->trait; if (!trait) return null_t;
        obj_ops   *ops   = trait->ops; if (!ops)   return null_t;
        if (!ops->arith)      return null_t;
        if (!ops->arith->div) return null_t;
        return ops->arith->div(div, arg);
}

struct obj* 
    div_eq(struct obj* par, any_t par_arg)                      {
        obj*       div   = par       ; if (!div)   return null_t;
        any_t      arg   = par_arg   ; if (!arg)   return null_t;
        obj_trait *trait = div->trait; if (!trait) return null_t;
        obj_ops   *ops   = trait->ops; if (!ops)   return null_t;
        
        if (!ops->arith)         return null_t;
        if (!ops->arith->div_eq) return null_t;
        ops->arith->div_eq(div, arg);
        return div;
}


struct obj* 
    mod(struct obj* par, any_t par_arg)                         {
        obj*       mod   = par       ; if (!mod)   return null_t;
        any_t      arg   = par_arg   ; if (!arg)   return null_t;
        obj_trait *trait = mod->trait; if (!trait) return null_t;
        obj_ops   *ops   = trait->ops; if (!ops)   return null_t;
        
        if (!ops->arith)      return false_t;
        if (!ops->arith->mod) return false_t;
        return ops->arith->mod(mod, arg);
}

struct obj* 
    mod_eq(struct obj* par, any_t par_arg)                      {
        obj*       mod   = par       ; if (!mod)   return null_t;
        any_t      arg   = par_arg   ; if (!arg)   return null_t;
        obj_trait *trait = mod->trait; if (!trait) return null_t;
        obj_ops   *ops   = trait->ops; if (!ops)   return null_t;
        
        if (!ops->arith)         return false_t;
        if (!ops->arith->mod_eq) return false_t;
        ops->arith->mod_eq(mod, arg);
        return mod;
}