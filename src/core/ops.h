#ifndef __OPS_H__
#define __OPS_H__

#include "ops/arith.h"
#include "ops/bit.h"
#include "ops/cmp.h"
#include "ops/logical.h"
#include "ops/cast.h"

typedef struct obj_ops  {
    ops_arith   *arith  ;
    ops_bit     *bit    ;
    ops_cmp     *cmp    ;
    ops_logical *logical;
    ops_cast    *cast   ;
}   obj_ops;

#endif