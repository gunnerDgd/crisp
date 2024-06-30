#ifndef COLLECTIONS_SEQ_H
#define COLLECTIONS_SEQ_H

#include "../core.h"

extern obj_trait *seq_t;
typedef struct    seq  {
    obj   head;
    u64_t begin, end;
    mem  *mem;
    u8_t *ptr;
    u64_t len;
}   seq;

void   seq_prep_front(seq* self, u64_t prep);
void   seq_prep_back (seq* self, u64_t prep);
void   seq_prep      (seq* self, u64_t prep, u64_t off);

u64_t  seq_free_front(seq* self);
u64_t  seq_free_back (seq* self);
bool_t seq_empty     (seq* self);
u64_t  seq_len       (seq* self);
void*  seq_ptr       (seq* self);

void   seq_push_front(seq* self, void* push, u64_t len);
void   seq_push_back (seq* self, void* push, u64_t len);
void   seq_push      (seq* self, void* push, u64_t len, u64_t off);

void   seq_pop_front (seq* self, u64_t pop);
void   seq_pop_back  (seq* self, u64_t pop);
void   seq_pop       (seq* self, u64_t pop, u64_t off);

#endif