#ifndef __SYNC_SPMC_H__
#define __SYNC_SPMC_H__

#include "../obj.h"

extern obj_trait *spmc_t;
typedef struct    spmc  {
    obj   head      ;
    obj  *spmc[1 KB];
    u64_t enq,
          deq;
}   spmc;

bool_t spmc_new    (spmc*, u32_t, va_list);
bool_t spmc_clone  (spmc*, spmc*)         ;
void   spmc_del    (spmc*)                ;

bool_t spmc_enq_try(spmc*, obj*);
void   spmc_enq    (spmc*, obj*);
obj*   spmc_deq_try(spmc*);
obj*   spmc_deq    (spmc*);

#endif