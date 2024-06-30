#ifndef CORE_OPS_CMP_H
#define CORE_OPS_CMP_H

#include "../type.h"

struct obj;

typedef enum ord_t {
    ord_err = -1,
    ord_lt  =  0,
    ord_eq  =  1,
    ord_gt  =  2
}   ord_t;

typedef struct cmp                            {
    ord_t (*ord)    (struct obj*, struct obj*);
    ord_t (*ord_arg)(struct obj*, any_t)      ;
}   cmp;

#define make_cmp(do_ord_arg, do_ord)                           {\
    .ord_arg = (ord_t(*)(struct obj*, any_t))      (do_ord_arg),\
    .ord     = (ord_t(*)(struct obj*, struct obj*))(do_ord)    ,\
}                                                               \

ord_t  ord    (struct obj*, struct obj*);
ord_t  ord_arg(struct obj*, any_t)      ;

bool_t gt_eq(struct obj*, struct obj*);
bool_t lt_eq(struct obj*, struct obj*);
bool_t gt   (struct obj*, struct obj*);
bool_t lt   (struct obj*, struct obj*);
bool_t eq   (struct obj*, struct obj*);
bool_t ne   (struct obj*, struct obj*);

bool_t lt_eq_arg(struct obj*, any_t);
bool_t gt_eq_arg(struct obj*, any_t);
bool_t gt_arg   (struct obj*, any_t);
bool_t lt_arg   (struct obj*, any_t);
bool_t eq_arg   (struct obj*, any_t);
bool_t ne_arg   (struct obj*, any_t);

#endif