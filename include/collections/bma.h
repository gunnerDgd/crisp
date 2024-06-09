#ifndef __BMA_H__
#define __BMA_H__

#include "../core.h"

extern obj_trait *bma_t;
typedef struct    bma { u8_t bma[1 KB]; } bma;

bool_t bma_out_lock(bma*, any_t*);
bool_t bma_out     (bma*, any_t*);
bool_t bma_in_lock (bma*, any_t);
bool_t bma_in      (bma*, any_t);

#endif
