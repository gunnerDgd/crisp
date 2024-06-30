#ifndef COLLECTIONS_BMA_H
#define COLLECTIONS_BMA_H

#include "../core.h"

extern obj_trait *bma_t;
typedef struct    bma { u8_t bma[1 KB]; } bma;

bool_t bma_out_lock(bma* self, any_t* out);
bool_t bma_out     (bma* self, any_t* out);
bool_t bma_in_lock (bma* self, any_t  out);
bool_t bma_in      (bma* self, any_t  out);

#endif
