#ifndef __SYNC_MPSC_H__
#define __SYNC_MPSC_H__

#include "../obj.h"
#include "../mem.h"

extern obj_trait *mpsc_t;
typedef struct    mpsc  { u8_t mpsc[10 KB]; }   mpsc;

bool_t mpsc_enq_try(mpsc*, obj*);
void   mpsc_enq    (mpsc*, obj*);
obj*   mpsc_deq_try(mpsc*);
obj*   mpsc_deq    (mpsc*);

#endif