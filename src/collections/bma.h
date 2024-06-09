#ifndef __BMA_H__
#define __BMA_H__

#include "../core.h"

extern obj_trait *bma_t;
typedef struct    bma  {
    obj   head;
    any_t bma[PRESET_ARCH_BIT];
    reg_t out;
    reg_t in ;
}   bma;

bool_t bma_new  (bma*, u32_t, va_list);
bool_t bma_clone(bma*, bma*)          ;
void   bma_del  (bma*)                ;

bool_t bma_out_lock(bma*, any_t*);
bool_t bma_out     (bma*, any_t*);
bool_t bma_in_lock (bma*, any_t);
bool_t bma_in      (bma*, any_t);

#endif
