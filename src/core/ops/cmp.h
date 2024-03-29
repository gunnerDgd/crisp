#ifndef __OPS_CMP_H__
#define __OPS_CMP_H__

#include "../type.h"

struct obj;

typedef enum ord_t {
    ord_lt = -1,
    ord_eq =  0,
    ord_gt =  1
}   ord_t;

typedef struct ops_cmp              {
    ord_t (*ord)(struct obj*, any_t);
}   ops_cmp;

ord_t  op_ord  (struct obj*, any_t);
bool_t op_gt   (struct obj*, any_t);
bool_t op_gt_eq(struct obj*, any_t);
bool_t op_lt   (struct obj*, any_t);
bool_t op_lt_eq(struct obj*, any_t);
bool_t op_eq   (struct obj*, any_t);
bool_t op_ne   (struct obj*, any_t);

#endif