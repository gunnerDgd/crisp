#include "cast.h"
#include "../obj.h"

struct obj* 
    as(struct obj* par, struct obj_trait* par_trait)            {
        obj       *as    = par       ; if (!as)    return null_t;
        obj_trait *trait = as->trait ; if (!trait) return null_t;
        obj_ops   *ops   = trait->ops; if (!ops)   return null_t;
        
        if (!ops->cast)     return null_t;
        if (!ops->cast->as) return null_t;
        return ops->cast->as(as, par_trait);
}

i8_t 
    as_i8(struct obj* par)                                 {
        obj       *as    = par       ; if (!as)    return 0;
        obj_trait *trait = as->trait ; if (!trait) return 0;
        obj_ops   *ops   = trait->ops; if (!ops)   return 0;
        if (!ops->cast)        return 0;
        if (!ops->cast->as_i8) return 0;
        return ops->cast->as_i8(as);
}

u8_t 
    as_u8(struct obj* par)                                 {
        obj       *as    = par       ; if (!as)    return 0;
        obj_trait *trait = as->trait ; if (!trait) return 0;
        obj_ops   *ops   = trait->ops; if (!ops)   return 0;
        if (!ops->cast)        return 0;
        if (!ops->cast->as_u8) return 0;
        return ops->cast->as_u8(as);
}

i16_t 
    as_i16(struct obj* par)                                {
        obj       *as    = par       ; if (!as)    return 0;
        obj_trait *trait = as->trait ; if (!trait) return 0;
        obj_ops   *ops   = trait->ops; if (!ops)   return 0;
        if (!ops->cast)         return 0;
        if (!ops->cast->as_i16) return 0;
        return ops->cast->as_i16(as);
}

u16_t 
    as_u16(struct obj* par)                                {
        obj       *as    = par       ; if (!as)    return 0;
        obj_trait *trait = as->trait ; if (!trait) return 0;
        obj_ops   *ops   = trait->ops; if (!ops)   return 0;
        if (!ops->cast)         return 0;
        if (!ops->cast->as_u16) return 0;
        return ops->cast->as_u16(as);
}

i32_t 
    as_i32(struct obj* par)                                {
        obj       *as    = par       ; if (!as)    return 0;
        obj_trait *trait = as->trait ; if (!trait) return 0;
        obj_ops   *ops   = trait->ops; if (!ops)   return 0;
        if (!ops->cast)         return 0;
        if (!ops->cast->as_i32) return 0;
        return ops->cast->as_i32(as);
}

u32_t 
    as_u32(struct obj* par)                                {
        obj       *as    = par       ; if (!as)    return 0;
        obj_trait *trait = as->trait ; if (!trait) return 0;
        obj_ops   *ops   = trait->ops; if (!ops)   return 0;
        if (!ops->cast)         return 0;
        if (!ops->cast->as_u32) return 0;
        return ops->cast->as_u32(as);
}

i64_t 
    as_i64(struct obj* par)                                {
        obj       *as    = par       ; if (!as)    return 0;
        obj_trait *trait = as->trait ; if (!trait) return 0;
        obj_ops   *ops   = trait->ops; if (!ops)   return 0;
        if (!ops->cast)         return 0;
        if (!ops->cast->as_i64) return 0;
        return ops->cast->as_i64(as);
}

u64_t 
    as_u64(struct obj* par)                                {
        obj       *as    = par       ; if (!as)    return 0;
        obj_trait *trait = as->trait ; if (!trait) return 0;
        obj_ops   *ops   = trait->ops; if (!ops)   return 0;
        if (!ops->cast)         return 0;
        if (!ops->cast->as_u64) return 0;
        return ops->cast->as_u64(as);
}

f32_t
    as_f32(struct obj* par)                                   {
        obj       *as    = par       ; if (!as)    return 0.0f;
        obj_trait *trait = as->trait ; if (!trait) return 0.0f;
        obj_ops   *ops   = trait->ops; if (!ops)   return 0.0f;
        if (!ops->cast)         return 0.0f;
        if (!ops->cast->as_f32) return 0.0f;
        return ops->cast->as_f32(as);
}

f64_t
    as_f64(struct obj* par)                                  {
        obj       *as    = par       ; if (!as)    return 0.0;
        obj_trait *trait = as->trait ; if (!trait) return 0.0;
        obj_ops   *ops   = trait->ops; if (!ops)   return 0.0;
        if (!ops->cast)         return  0.0;
        if (!ops->cast->as_f64) return  0.0;
        return ops->cast->as_f64(as);
}

any_t
    as_any(struct obj* par)                                     {
        obj       *as    = par       ; if (!as)    return null_t;
        obj_trait *trait = as->trait ; if (!trait) return null_t;
        obj_ops   *ops   = trait->ops; if (!ops)   return null_t;
        if (!ops->cast)         return null_t;
        if (!ops->cast->as_f64) return null_t;
        return ops->cast->as_any(as);
}