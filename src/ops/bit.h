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

struct obj* and   (struct obj*, any_t);
struct obj* or    (struct obj*, any_t);
struct obj* xor   (struct obj*, any_t);
struct obj* not   (struct obj*)       ;

struct obj* and_eq(struct obj*, any_t);
struct obj* or_eq (struct obj*, any_t);
struct obj* xor_eq(struct obj*, any_t);

#endif