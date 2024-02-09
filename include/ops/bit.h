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

struct obj* op_and   (struct obj*, any_t);
struct obj* op_or    (struct obj*, any_t);
struct obj* op_xor   (struct obj*, any_t);
struct obj* op_not   (struct obj*)       ;

struct obj* op_and_eq(struct obj*, any_t);
struct obj* op_or_eq (struct obj*, any_t);
struct obj* op_xor_eq(struct obj*, any_t);

#endif