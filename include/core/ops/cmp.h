#ifndef __OPS_CMP_H__
#define __OPS_CMP_H__

#include "../type.h"

struct obj;

typedef enum ord_t {
    ord_err = -1,
    ord_lt  =  0,
    ord_eq  =  1,
    ord_gt  =  2
}   ord_t;

typedef struct ops_cmp                        {
    ord_t (*ord)    (struct obj*, struct obj*);
    ord_t (*ord_arg)(struct obj*, any_t)      ;
}   ops_cmp;

#define make_ops_cmp(par_ord, par_ord_arg) {                     \
    .ord_arg = (ord_t(*)(struct obj*, any_t))      (par_ord_arg),\
    .ord     = (ord_t(*)(struct obj*, struct obj*))(par_ord)     \
}

ord_t  op_ord      (struct obj*, struct obj*);
ord_t  op_org_arg  (struct obj*, any_t)      ;

bool_t op_gt       (struct obj*, struct obj*);
bool_t op_gt_arg   (struct obj*, any_t)      ;

bool_t op_gt_eq    (struct obj*, struct obj*);
bool_t op_gt_eq_arg(struct obj*, any_t)      ;

bool_t op_lt       (struct obj*, struct obj*);
bool_t op_lt_arg   (struct obj*, any_t)      ;

bool_t op_lt_eq    (struct obj*, struct obj*);
bool_t op_lt_eq_arg(struct obj*, any_t)      ;

bool_t op_eq       (struct obj*, struct obj*);
bool_t op_eq_arg   (struct obj*, any_t)      ;

bool_t op_ne       (struct obj*, struct obj*);
bool_t op_ne_arg   (struct obj*, any_t)      ;

#endif