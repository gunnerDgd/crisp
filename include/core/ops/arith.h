#ifndef CORE_OPS_ARITH_H
#define CORE_OPS_ARITH_H

#include "../type.h"

struct obj;

typedef struct arith                         {
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
}   arith;

#ifndef __cplusplus

#define make_arith(do_add, do_sub, do_mul, do_div, do_mod, do_add_eq, do_sub_eq, do_mul_eq, do_div_eq, do_mod_eq) {\
    .add    = ((struct obj*(*)(struct obj*, any_t))(do_add)),   \
    .sub    = ((struct obj*(*)(struct obj*, any_t))(do_sub)),   \
    .mul    = ((struct obj*(*)(struct obj*, any_t))(do_mul)),   \
    .div    = ((struct obj*(*)(struct obj*, any_t))(do_div)),   \
    .mod    = ((struct obj*(*)(struct obj*, any_t))(do_mod)),   \
                                                                \
    .add_eq = ((struct obj*(*)(struct obj*, any_t))(do_add_eq)),\
    .sub_eq = ((struct obj*(*)(struct obj*, any_t))(do_sub_eq)),\
    .mul_eq = ((struct obj*(*)(struct obj*, any_t))(do_mul_eq)),\
    .div_eq = ((struct obj*(*)(struct obj*, any_t))(do_div_eq)),\
    .mod_eq = ((struct obj*(*)(struct obj*, any_t))(do_mod_eq)),\
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