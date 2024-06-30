#ifndef CORE_OPS_BIT_H
#define CORE_OPS_BIT_H

#include "../type.h"

struct obj;

typedef struct bit                           {
    struct obj* (*and)   (struct obj*, any_t);
    struct obj* (*or)    (struct obj*, any_t);
    struct obj* (*xor)   (struct obj*, any_t);
    struct obj* (*not)   (struct obj*)       ;

    void        (*and_eq)(struct obj*, any_t);
    void        (*or_eq) (struct obj*, any_t);
    void        (*xor_eq)(struct obj*, any_t);
}   bit;

#ifndef __cplusplus

#define make_bit (do_and, do_or, do_xor, do_not, do_and_eq, do_or_eq, do_xor_eq) {\
    .and    = ((struct obj*(*)(struct obj*, any_t))(do_and)),   \
    .or     = ((struct obj*(*)(struct obj*, any_t))(do_or)) ,   \
    .xor    = ((struct obj*(*)(struct obj*, any_t))(do_xor)),   \
    .not    = ((struct obj*(*)(struct obj*))       (do_not)),   \
                                                                \
    .and_eq = ((struct obj*(*)(struct obj*, any_t))(do_and_eq)),\
    .or_eq  = ((struct obj*(*)(struct obj*, any_t))(do_or_eq)) ,\
    .xor_eq = ((struct obj*(*)(struct obj*, any_t))(do_xor_eq)) \
}

#endif

struct obj* bit_and   (struct obj*, any_t);
struct obj* bit_or    (struct obj*, any_t);
struct obj* bit_xor   (struct obj*, any_t);
struct obj* bit_not   (struct obj*);

struct obj* bit_and_eq(struct obj*, any_t);
struct obj* bit_or_eq (struct obj*, any_t);
struct obj* bit_xor_eq(struct obj*, any_t);

#endif