#ifndef __SYNC_SPSC_H__
#define __SYNC_SPSC_H__

#include "../obj.h"

extern obj_trait *spsc_t;
typedef struct    spsc  { u8_t spsc[10 KB]; } spsc;

bool_t spsc_enq_try(spsc*, obj*);
void   spsc_enq    (spsc*, obj*);
obj*   spsc_deq_try(spsc*);
obj*   spsc_deq    (spsc*);

#endif