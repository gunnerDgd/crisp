#include "bit.h"

#include "../obj.h"

struct obj*
    bit_and
        (struct obj* self, any_t arg)                                   {
            obj_trait *trait = trait_of(self); if (!trait) return null_t;
            obj_ops   *ops   = trait->ops;     if (!ops)   return null_t;

            if (!ops->bit->and) return null_t;
            return ops->bit->and(self, arg);
}

struct obj*
    bit_and_eq
        (struct obj* self, any_t arg)                                   {
            obj_trait *trait = trait_of(self); if (!trait) return null_t;
            obj_ops   *ops   = trait->ops;     if (!ops)   return null_t;

            if (!ops->bit->and_eq) return null_t;
            ops->bit->and_eq(self, arg);
            return self;
}

struct obj*
    bit_or
        (struct obj* self, any_t arg)                                   {
            obj_trait *trait = trait_of(self); if (!trait) return null_t;
            obj_ops   *ops   = trait->ops;     if (!ops)   return null_t;

            if (!ops->bit->or) return null_t;
            return ops->bit->or(self, arg);
}

struct obj*
    bit_or_eq
        (struct obj* self, any_t arg)                                   {
            obj_trait *trait = trait_of(self); if (!trait) return null_t;
            obj_ops   *ops   = trait->ops;     if (!ops)   return null_t;

            if (!ops->bit->and_eq) return null_t;
            ops->bit->and_eq(self, arg);
            return self;
}

struct obj*
    bit_xor
        (struct obj* self, any_t arg)                                   {
            obj_trait *trait = trait_of(self); if (!trait) return null_t;
            obj_ops   *ops   = trait->ops;     if (!ops)   return null_t;

            if (!ops->bit->and) return null_t;
            return ops->bit->and(self, arg);
}

struct obj*
    bit_xor_eq
        (struct obj* self, any_t arg)                                   {
            obj_trait *trait = trait_of(self); if (!trait) return null_t;
            obj_ops   *ops   = trait->ops;     if (!ops)   return null_t;

            if (!ops->bit->xor_eq) return null_t;
            ops->bit->xor_eq(self, arg);
            return self;
}

struct obj*
    bit_not
        (struct obj* self)                                              {
            obj_trait *trait = trait_of(self); if (!trait) return null_t;
            obj_ops   *ops   = trait->ops;     if (!ops)   return null_t;

            if (!ops->bit->not) return null_t;
            return ops->bit->not(self);
}