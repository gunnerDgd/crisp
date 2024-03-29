#ifndef __OPS_BIT_H__
#define __OPS_BIT_H__

#include "../type.h"

struct obj;

typedef struct ops_bit                       {
    struct obj* (*and)   (struct obj*, any_t);
    struct obj* (*or)    (struct obj*, any_t);
    struct obj* (*xor)   (struct obj*, any_t);
    struct obj* (*not)   (struct obj*)       ;
    
    void        (*and_eq)(struct obj*, any_t);
    void        (*or_eq) (struct obj*, any_t);
    void        (*xor_eq)(struct obj*, any_t);
}   ops_bit;

#ifndef __cplusplus

#define make_bit_ops (par_and, par_or, par_xor, par_and_eq, par_or_eq, par_xor_eq) {\
    .and    = ((struct obj*(*)(struct obj*, any_t))(par_and)),   \
    .or     = ((struct obj*(*)(struct obj*, any_t))(par_or)) ,   \
    .xor    = ((struct obj*(*)(struct obj*, any_t))(par_xor)),   \
    .not    = ((struct obj*(*)(struct obj*))       (par_not)),   \
                                                                 \
    .and_eq = ((struct obj*(*)(struct obj*, any_t))(par_and_eq)),\
    .or_eq  = ((struct obj*(*)(struct obj*, any_t))(par_or_eq)) ,\
    .xor_eq = ((struct obj*(*)(struct obj*, any_t))(par_xor_eq)) \
}

#endif

struct obj* op_and   (struct obj*, any_t);
struct obj* op_or    (struct obj*, any_t);
struct obj* op_xor   (struct obj*, any_t);
struct obj* op_not   (struct obj*)       ;

struct obj* op_and_eq(struct obj*, any_t);
struct obj* op_or_eq (struct obj*, any_t);
struct obj* op_xor_eq(struct obj*, any_t);

#endif