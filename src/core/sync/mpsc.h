#ifndef __SYNC_MPSC_H__
#define __SYNC_MPSC_H__

#include "../obj.h"
#include "../mem.h"

extern obj_trait *mpsc_t;
typedef struct    mpsc  {
    obj   head;
    obj  *mpsc[1 KB];
    u64_t enq,
          deq;
}   mpsc;

bool_t mpsc_new    (mpsc*, u32_t, va_list);
bool_t mpsc_clone  (mpsc*, mpsc*)         ;
void   mpsc_del    (mpsc*)                ;

bool_t mpsc_enq_try(mpsc*, obj*);
void   mpsc_enq    (mpsc*, obj*);
obj*   mpsc_deq_try(mpsc*);
obj*   mpsc_deq    (mpsc*);

#endif