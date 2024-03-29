#ifndef __OPS_LOGICAL_H__
#define __OPS_LOGICAL_H__

#include "../type.h"

struct obj;

typedef struct ops_logical                {
    struct obj* (*and)(struct obj*, any_t);
    struct obj* (*or) (struct obj*, any_t);
    struct obj* (*not)(struct obj*)       ;
}   ops_logical;

#ifndef __cplusplus

#define make_logical_ops (par_and, par_or, par_not)       {\
    .and = ((struct obj*(*)(struct obj*, any_t))(par_and)),\
    .or  = ((struct obj*(*)(struct obj*, any_t))(par_or)) ,\
    .not = ((struct obj*(*)(struct obj*))       (par_not)) \
}

#endif

struct obj* log_and(struct obj*, any_t);
struct obj* log_or (struct obj*, any_t);
struct obj* log_not(struct obj*)       ;

#endif