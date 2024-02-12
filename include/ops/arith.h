#ifndef __OPS_ARITH_H__
#define __OPS_ARITH_H__

#include "../type.h"

struct obj;

typedef struct ops_arith                     {
    struct obj* (*add)   (struct obj*, any_t);
    struct obj* (*sub)   (struct obj*, any_t);
    struct obj* (*mul)   (struct obj*, any_t);
    struct obj* (*div)   (struct obj*, any_t);
    struct obj* (*mod)   (struct obj*, any_t);
    
    void        (*add_eq)(struct obj*, any_t);
    void        (*sub_eq)(struct obj*, any_t);
    void        (*mul_eq)(struct obj*, any_t);
    void        (*div_eq)(struct obj*, any_t);
    void        (*mod_eq)(struct obj*, any_t);
}   ops_arith;

#ifndef __cplusplus

#define make_arith_ops(par_add, par_sub, par_mul, par_div, par_mod, par_add_eq, par_sub_eq, par_mul_eq, par_div_eq, par_mod_eq) {\
    .add    = ((struct obj*(*)(struct obj*, any_t))(par_add)),   \
    .sub    = ((struct obj*(*)(struct obj*, any_t))(par_sub)),   \
    .mul    = ((struct obj*(*)(struct obj*, any_t))(par_mul)),   \
    .div    = ((struct obj*(*)(struct obj*, any_t))(par_div)),   \
    .mod    = ((struct obj*(*)(struct obj*, any_t))(par_mod)),   \
                                                                 \
    .add_eq = ((struct obj*(*)(struct obj*, any_t))(par_add_eq)),\
    .sub_eq = ((struct obj*(*)(struct obj*, any_t))(par_sub_eq)),\
    .mul_eq = ((struct obj*(*)(struct obj*, any_t))(par_mul_eq)),\
    .div_eq = ((struct obj*(*)(struct obj*, any_t))(par_div_eq)),\
    .mod_eq = ((struct obj*(*)(struct obj*, any_t))(par_mod_eq)),\
}

#endif

struct obj* op_add   (struct obj*, any_t);
struct obj* op_sub   (struct obj*, any_t);
struct obj* op_mul   (struct obj*, any_t);
struct obj* op_div   (struct obj*, any_t);
struct obj* op_mod   (struct obj*, any_t);

struct obj* op_add_eq(struct obj*, any_t);
struct obj* op_sub_eq(struct obj*, any_t);
struct obj* op_mul_eq(struct obj*, any_t);
struct obj* op_div_eq(struct obj*, any_t);
struct obj* op_mod_eq(struct obj*, any_t);

#endif