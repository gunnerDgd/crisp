#ifndef __SYNC_MPMC_H__
#define __SYNC_MPMC_H__

#include "../obj.h"

extern obj_trait *mpmc_t;
typedef struct    mpmc  {
    obj   head      ;
    obj*  mpmc[1 KB];
    u64_t enq,
          deq;
}   mpmc;

bool_t mpmc_new    (mpmc*, u32_t, va_list);
bool_t mpmc_clone  (mpmc*, mpmc*)         ;
void   mpmc_del    (mpmc*)                ;

bool_t mpmc_enq_try(mpmc*, obj*);
void   mpmc_enq    (mpmc*, obj*);
obj*   mpmc_deq_try(mpmc*);
obj*   mpmc_deq    (mpmc*);

#endif