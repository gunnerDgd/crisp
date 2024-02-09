#ifndef __SYNC_SPSC_H__
#define __SYNC_SPSC_H__

#include "../obj.h"

extern obj_trait *spsc_t;
typedef struct    spsc  {
    obj   head      ;
    obj*  spsc[1 KB];
    u64_t enq,
          deq;
}   spsc;

bool_t spsc_new    (spsc*, u32_t, va_list);
bool_t spsc_clone  (spsc*, spsc*)         ;
void   spsc_del    (spsc*)                ;

bool_t spsc_enq_try(spsc*, obj*);
void   spsc_enq    (spsc*, obj*);
obj*   spsc_deq_try(spsc*);
obj*   spsc_deq    (spsc*);

#endif