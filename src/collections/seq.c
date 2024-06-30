#include "seq.h"

static bool_t
    do_new
        (seq* self, u32_t count, va_list arg)                          {
            u64_t len = 16    ; if (count > 0) len = va_arg(arg, u64_t);
            mem*  mem = null_t; if (count > 1) mem = va_arg(arg, any_t);
            if (trait_of(mem) != mem_t) mem = get_mem();
            if (trait_of(mem) != mem_t) return false_t ;

            self->ptr   = mem_use (mem, null_t, len);
            self->begin = 0  ;
            self->end   = 0  ;
            self->mem   = mem;
            self->len   = len;
            return true_t;
}

static bool_t
    do_clone
        (seq* self, seq* clone)       {
            self->begin = clone->begin;
            self->end   = clone->end;
            self->len   = clone->len;
            self->mem   = clone->mem;

            self->ptr = mem_use(self->mem, null_t, self->len);
            if (!self->ptr) return false_t;
            mem_copy      (
                self ->ptr,
                clone->ptr,
                self ->len
            );

            return true_t;
}

static void
    do_del
        (seq* self)                                   {
            mem_free (self->mem, self->ptr, self->len);
}

static obj_trait
    do_obj = make_trait (
        do_new     ,
        do_clone   ,
        null_t     ,
        do_del     ,
        sizeof(seq),
        null_t
);

obj_trait *seq_t = &do_obj;



void
    seq_prep_front
        (seq* self, u64_t prep)                {
            if (trait_of(self) != seq_t) return;
            if (!prep)                   return;

            u8_t *ptr = mem_use(self->mem, null_t, self->len + prep);
            u8_t *dst = ptr       + self->begin + prep;
            u8_t *src = self->ptr + self->begin;
            u64_t len = seq_len(self);
            mem_copy (dst, src, len);

            mem_free(self->mem, self->ptr, self->len);
            self->begin += prep;
            self->end   += prep;
            self->len   += len;
            self->ptr    = ptr;
}

void
    seq_prep_back
        (seq* self, u64_t prep)                {
            if (trait_of(self) != seq_t) return;
            if (!prep)                   return;

            u8_t *ptr = mem_use(self->mem, null_t, self->len + prep);
            u8_t *dst = ptr       + self->begin;
            u8_t *src = self->ptr + self->begin;
            u64_t len = seq_len(self);
            mem_copy(dst, src, len);

            mem_free(self->mem, self->ptr, self->len);
            self->len += prep;
            self->ptr  = ptr;
}

void
    seq_prep
        (seq* self, u64_t off, u64_t prep)     {
            if (trait_of(self) != seq_t) return;
            if (!prep)                   return;

            if (off >= seq_len(self)) { seq_prep_back (self, prep); return; }
            if (off == 0)             { seq_prep_front(self, prep); return; }
            u8_t *ptr = mem_use(self->mem, null_t, prep + self->len);
            u8_t *dst = ptr       + self->begin;
            u8_t *src = self->ptr + self->begin;
            u64_t len = off;

            mem_copy(dst, src, len);
            len  = seq_len(self) - off;
            dst += (off + prep);
            src += (off);

            mem_copy(dst, src, len)                  ;
            mem_free(self->mem, self->ptr, self->len);
            self->end += prep;
            self->ptr  = ptr ;
            self->len += prep;
}

u64_t  seq_free_front(seq* par) { if (trait_of(par) != seq_t) return 0; return par->begin; }
u64_t  seq_free_back (seq* par) { if (trait_of(par) != seq_t) return 0; return par->len - par->end; }

bool_t seq_empty(seq* par) { if (trait_of(par) != seq_t) return true_t; return par->begin == par->end; }
u64_t  seq_len  (seq* par) { if (trait_of(par) != seq_t) return 0;      return par->end    - par->begin; }
void*  seq_ptr  (seq* par) { if (trait_of(par) != seq_t) return null_t; return par->ptr + par->begin; }

void
    seq_push_front
        (seq* self, void* src, u64_t len)      {
            if (trait_of(self) != seq_t) return;
            if (!src)                    return;
            if (!len)                    return;

            if (seq_free_front(self) < len) seq_prep_front(self, len);
            self->begin -= len;

            u8_t *dst = self->ptr + self->begin;
            mem_copy(dst, src, len);
}

void
    seq_push_back
        (seq* self, void* src, u64_t len)      {
            if (trait_of(self) != seq_t) return;
            if (!src)                    return;
            if (!len)                    return;

            if (seq_free_back(self) < len) seq_prep_back(self, len);
            u8_t *dst = self->ptr + self->end;

            mem_copy(dst, src, len);
            self->end += len;
}

void
    seq_push
        (seq* self, void* src, u64_t len, u64_t off) {
            if (trait_of(self) != seq_t) return;
            if (!src)                    return;
            if (!len)                    return;

            if (off > seq_len(self)) { seq_push_back (self, src, len); return; }
            if (off == 0)            { seq_push_front(self, src, len); return; }
            seq_prep(self, off, len);

            u8_t *dst = self->ptr + self->begin + off;
            mem_copy(dst, src, len);
}

void
    seq_pop_front
        (seq* self, u64_t len)                 {
            if (trait_of(self) != seq_t) return;
            if (!len)                    return;
            if (self->begin < len)             {
                self->begin = 0;
                return;
            }

            self->begin -= len;
            mem_set(self->ptr + self->begin, 0x00, len);
}

void
    seq_pop_back
        (seq* self, u64_t len)                 {
            if (trait_of(self) != seq_t) return;
            if (!len)                    return;
            if (len >= seq_len(self))                                {
                mem_set(self->ptr + self->begin, 0x00, seq_len(self));
                self->end = self->begin;
            }

            self->end -= len;
            mem_set(self->ptr + self->end, 0x00, len);
}

void
    seq_pop
        (seq* self, u64_t off, u64_t len)      {
            if (trait_of(self) != seq_t) return;
            if (!len)                    return;

            if (off > self->end) { seq_pop_back (self, len); return; }
            if (off == 0)        { seq_pop_front(self, len); return; }
            u8_t *dst = self->ptr + off;
            u8_t *src = dst       + len;

            if (len > (self->end - off)) len = (self->end - off);
            mem_copy(dst, src, len);

            self->end -= len;
            mem_set(self->ptr + self->end, 0x00, len);
}