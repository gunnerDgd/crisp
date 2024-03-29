#ifndef __SEQ_H__
#define __SEQ_H__

#include "../core.h"

extern obj_trait *seq_t;
typedef struct    seq  {
    obj   head;
    u64_t begin, end;
    mem  *mem;
    u8_t *ptr;
    u64_t len;
}   seq;

bool_t seq_new       (seq*, u32_t, va_list);
bool_t seq_clone     (seq*, seq*)          ;
void   seq_del       (seq*)                ;

void   seq_prep_front(seq*, u64_t)       ;
void   seq_prep_back (seq*, u64_t)       ;
void   seq_prep      (seq*, u64_t, u64_t);

u64_t  seq_free_front(seq*);
u64_t  seq_free_back (seq*);
bool_t seq_empty     (seq*);
u64_t  seq_len       (seq*);
void*  seq_ptr       (seq*);

void   seq_push_front(seq*, void*, u64_t)       ;
void   seq_push_back (seq*, void*, u64_t)       ;
void   seq_push      (seq*, void*, u64_t, u64_t);

void   seq_pop_front (seq*, u64_t)       ;
void   seq_pop_back  (seq*, u64_t)       ;
void   seq_pop       (seq*, u64_t, u64_t);

#endif