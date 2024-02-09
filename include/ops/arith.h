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