#include "arith.h"
#include "../obj.h"

struct obj* 
    add
        (struct obj* self, any_t arg)                                   {
            obj_trait *trait = trait_of(self); if (!trait) return null_t;
            obj_ops   *ops   = trait->ops;     if (!ops)   return null_t;

            if (!ops->arith->add) return null_t;
            return ops->arith->add(self, arg);
}

struct obj*
    add_eq
        (struct obj* self, any_t arg)                                   {
            obj_trait *trait = trait_of(self); if (!trait) return null_t;
            obj_ops   *ops   = trait->ops;     if (!ops)   return null_t;

            if (!ops->arith->add_eq) return null_t;
            ops->arith->add_eq(self, arg);
            return self;
}

struct obj*
    sub
        (struct obj* self, any_t arg)                                   {
            obj_trait *trait = trait_of(self); if (!trait) return null_t;
            obj_ops   *ops   = trait->ops;     if (!ops)   return null_t;

            if (!ops->arith->sub) return null_t;
            return ops->arith->sub(self, arg);
}

struct obj*
    sub_eq
        (struct obj* self, any_t arg)                                   {
            obj_trait *trait = trait_of(self); if (!trait) return null_t;
            obj_ops   *ops   = trait->ops;     if (!ops)   return null_t;

            if (!ops->arith->sub_eq) return null_t;
            ops->arith->sub_eq(self, arg);
            return self;
}

struct obj*
    mul
        (struct obj* self, any_t arg)                                   {
            obj_trait *trait = trait_of(self); if (!trait) return null_t;
            obj_ops   *ops   = trait->ops;     if (!ops)   return null_t;

            if (!ops->arith->mul) return null_t;
            return ops->arith->mul(self, arg);
}

struct obj*
    mul_eq
        (struct obj* self, any_t arg)                                   {
            obj_trait *trait = trait_of(self); if (!trait) return null_t;
            obj_ops   *ops   = trait->ops;     if (!ops)   return null_t;

            if (!ops->arith->mul_eq) return null_t;
            ops->arith->mul_eq(self, arg);
            return self;
}

struct obj*
    div
        (struct obj* self, any_t arg)                                   {
            obj_trait *trait = trait_of(self); if (!trait) return null_t;
            obj_ops   *ops   = trait->ops;     if (!ops)   return null_t;

            if (!ops->arith->div) return null_t;
            return ops->arith->div(self, arg);
}

struct obj*
    div_eq
        (struct obj* self, any_t arg)                                   {
            obj_trait *trait = trait_of(self); if (!trait) return null_t;
            obj_ops   *ops   = trait->ops;     if (!ops)   return null_t;

            if (!ops->arith->div_eq) return null_t;
            ops->arith->div_eq(self, arg);
            return self;
}

struct obj*
    mod
        (struct obj* self, any_t arg)                                   {
            obj_trait *trait = trait_of(self); if (!trait) return null_t;
            obj_ops   *ops   = trait->ops;     if (!ops)   return null_t;

            if (!ops->arith->mod) return null_t;
            return ops->arith->mod(self, arg);
}

struct obj*
    mod_eq
        (struct obj* self, any_t arg)                                   {
            obj_trait *trait = trait_of(self); if (!trait) return null_t;
            obj_ops   *ops   = trait->ops;     if (!ops)   return null_t;

            if (!ops->arith->mod_eq) return null_t;
            ops->arith->mod_eq(self, arg);
            return self;
}