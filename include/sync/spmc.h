#ifndef __SYNC_SPMC_H__
#define __SYNC_SPMC_H__

#include "../obj.h"

extern obj_trait *spmc_t;
typedef struct    spmc  { u8_t spmc[10 KB]; } spmc;

bool_t spmc_enq_try(spmc*, obj*);
void   spmc_enq    (spmc*, obj*);
obj*   spmc_deq_try(spmc*);
obj*   spmc_deq    (spmc*);

#endif