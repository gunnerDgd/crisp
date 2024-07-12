#include "arith.h"
#include "../obj.h"

struct obj* 
    op_add
        (struct obj* self, any_t arg)                                   {
            obj_trait *trait = trait_of(self); if (!trait) return null_t;
            obj_ops   *ops   = trait->ops;     if (!ops)   return null_t;

            if (!ops->arith->add) return null_t;
            return ops->arith->add(self, arg);
}

struct obj*
    op_add_eq
        (struct obj* self, any_t arg)                                   {
            obj_trait *trait = trait_of(self); if (!trait) return null_t;
            obj_ops   *ops   = trait->ops;     if (!ops)   return null_t;

            if (!ops->arith->add_eq) return null_t;
            ops->arith->add_eq(self, arg);
            return self;
}

struct obj*
    op_sub
        (struct obj* self, any_t arg)                                   {
            obj_trait *trait = trait_of(self); if (!trait) return null_t;
            obj_ops   *ops   = trait->ops;     if (!ops)   return null_t;

            if (!ops->arith->sub) return null_t;
            return ops->arith->sub(self, arg);
}

struct obj*
    op_sub_eq
        (struct obj* self, any_t arg)                                   {
            obj_trait *trait = trait_of(self); if (!trait) return null_t;
            obj_ops   *ops   = trait->ops;     if (!ops)   return null_t;

            if (!ops->arith->sub_eq) return null_t;
            ops->arith->sub_eq(self, arg);
            return self;
}

struct obj*
    op_mul
        (struct obj* self, any_t arg)                                   {
            obj_trait *trait = trait_of(self); if (!trait) return null_t;
            obj_ops   *ops   = trait->ops;     if (!ops)   return null_t;

            if (!ops->arith->mul) return null_t;
            return ops->arith->mul(self, arg);
}

struct obj*
    op_mul_eq
        (struct obj* self, any_t arg)                                   {
            obj_trait *trait = trait_of(self); if (!trait) return null_t;
            obj_ops   *ops   = trait->ops;     if (!ops)   return null_t;

            if (!ops->arith->mul_eq) return null_t;
            ops->arith->mul_eq(self, arg);
            return self;
}

struct obj*
    op_div
        (struct obj* self, any_t arg)                                   {
            obj_trait *trait = trait_of(self); if (!trait) return null_t;
            obj_ops   *ops   = trait->ops;     if (!ops)   return null_t;

            if (!ops->arith->div) return null_t;
            return ops->arith->div(self, arg);
}

struct obj*
    op_div_eq
        (struct obj* self, any_t arg)                                   {
            obj_trait *trait = trait_of(self); if (!trait) return null_t;
            obj_ops   *ops   = trait->ops;     if (!ops)   return null_t;

            if (!ops->arith->div_eq) return null_t;
            ops->arith->div_eq(self, arg);
            return self;
}

struct obj*
    op_mod
        (struct obj* self, any_t arg)                                   {
            obj_trait *trait = trait_of(self); if (!trait) return null_t;
            obj_ops   *ops   = trait->ops;     if (!ops)   return null_t;

            if (!ops->arith->mod) return null_t;
            return ops->arith->mod(self, arg);
}

struct obj*
    op_mod_eq
        (struct obj* self, any_t arg)                                   {
            obj_trait *trait = trait_of(self); if (!trait) return null_t;
            obj_ops   *ops   = trait->ops;     if (!ops)   return null_t;

            if (!ops->arith->mod_eq) return null_t;
            ops->arith->mod_eq(self, arg);
            return self;
}