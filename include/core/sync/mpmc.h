#ifndef __SYNC_MPMC_H__
#define __SYNC_MPMC_H__

#include "../obj.h"
#include "../mem.h"

extern obj_trait *mpmc_t;
typedef struct    mpmc  { u8_t mpmc[10 KB]; }   mpmc;

bool_t mpmc_enq_try(mpmc*, obj*);
void   mpmc_enq    (mpmc*, obj*);
obj*   mpmc_deq_try(mpmc*);
obj*   mpmc_deq    (mpmc*);

#endif