#ifndef __COLLECTIONS_SEQ_H__
#define __COLLECTIONS_SEQ_H__

#include "../core.h"

extern obj_trait *seq_t;
typedef struct    seq  { u8_t seq[128]; } seq;

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