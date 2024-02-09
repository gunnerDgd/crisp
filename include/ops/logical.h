#ifndef __OPS_LOGICAL_H__
#define __OPS_LOGICAL_H__

#include "../type.h"

struct obj;

typedef struct ops_logical                {
    struct obj* (*and)(struct obj*, any_t);
    struct obj* (*or) (struct obj*, any_t);
    struct obj* (*not)(struct obj*)       ;
}   ops_logical;

struct obj* op_log_and(struct obj*, any_t);
struct obj* op_log_or (struct obj*, any_t);
struct obj* op_log_not(struct obj*)       ;

#endif