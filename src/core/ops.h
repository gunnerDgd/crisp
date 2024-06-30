#ifndef CORE_OPS_H
#define CORE_OPS_H

#include "ops/arith.h"
#include "ops/cmp.h"
#include "ops/bit.h"
#include "ops/cast.h"

typedef struct obj_ops {
    arith *arith;
    cast  *cast;
    cmp   *cmp;
    bit   *bit;
}   obj_ops;

#endif