#include "seq.h"

obj_trait seq_trait = make_trait (
    seq_new    ,
    seq_clone  ,
    null_t     ,
    seq_del    ,
    sizeof(seq),
    null_t
);

obj_trait *seq_t = &seq_trait;

bool_t
    seq_new
        (seq* par_seq, u32_t par_count, va_list par)                       {
            u64_t len = 16    ; if (par_count > 0) len = va_arg(par, u64_t);
            mem*  mem = null_t; if (par_count > 1) mem = va_arg(par, void*);
            if (trait_of(mem) != mem_t) mem = get_mem();
            if (trait_of(mem) != mem_t) return false_t ;

            par_seq->ptr   = mem_acq (mem, null_t, len);
            par_seq->begin = 0  ;
            par_seq->end   = 0  ;
            par_seq->mem   = mem;
            par_seq->len   = len;
            return true_t;
}

bool_t
    seq_clone
        (seq* par, seq* par_clone)       {
            par->begin = par_clone->begin;
            par->end   = par_clone->end  ;
            par->len   = par_clone->len  ;
            par->mem   = par_clone->mem  ;

            par->ptr = mem_acq(par->mem, null_t, par->len); if (!par->ptr) return false_t;
            mem_copy(par->ptr, par_clone->ptr, par->len);
            return true_t;
}

void
    seq_del
        (seq* par)                               {
            mem_rel(par->mem, par->ptr, par->len);
}

void
    seq_prep_front
        (seq* par, u64_t par_len)             {
            if (trait_of(par) != seq_t) return;
            if (!par_len)               return;

            u8_t *ptr = mem_acq(par->mem, null_t, par->len + par_len);
            u8_t *dst = ptr      + par->begin + par_len;
            u8_t *src = par->ptr + par->begin;
            u64_t len = seq_len(par);

            mem_copy(dst, src, len)               ;
            mem_rel (par->mem, par->ptr, par->len);
            par->begin += par_len;
            par->end   += par_len;
            par->len   += len;
            par->ptr    = ptr;
}

void
    seq_prep_back
        (seq* par, u64_t par_len)             {
            if (trait_of(par) != seq_t) return;
            if (!par_len)               return;

            u8_t *ptr = mem_acq(par->mem, null_t, par->len + par_len);
            u8_t *dst = ptr      + par->begin;
            u8_t *src = par->ptr + par->begin;
            u64_t len = seq_len(par);

            mem_copy(dst, src, len);
            mem_rel (par->mem, par->ptr, par->len);
            par->len += par_len;
            par->ptr  = ptr    ;
}

void
    seq_prep
        (seq* par, u64_t par_off, u64_t par_len) {
            if (trait_of(par) != seq_t) return;
            if (!par_len)               return;

            if (par_off >= seq_len(par)) { seq_prep_back (par, par_len); return; }
            if (par_off == 0)            { seq_prep_front(par, par_len); return; }
            u8_t *ptr = mem_acq(par->mem, null_t, par_len + par->len);
            u8_t *dst = ptr      + par->begin;
            u8_t *src = par->ptr + par->begin;
            u64_t len = par_off;

            mem_copy(dst, src, len);
            len  = seq_len(par) - par_off;
            dst += (par_off + par_len);
            src += (par_off);

            mem_copy(dst, src, len)               ;
            mem_rel (par->mem, par->ptr, par->len);
            par->end += par_len;
            par->ptr  = ptr    ;
            par->len += par_len;
}

u64_t
    seq_free_front
        (seq* par)                              {
            if (trait_of(par) != seq_t) return 0;
            return par->begin;
}

u64_t
    seq_free_back
        (seq* par)                              {
            if (trait_of(par) != seq_t) return 0;
            return par->len - par->end;
}

bool_t
    seq_empty
        (seq* par)                                   {
            if (trait_of(par) != seq_t) return true_t;
            return par->begin == par->end;
}

u64_t
    seq_len
        (seq* par)                              {
            if (trait_of(par) != seq_t) return 0;
            return par->end - par->begin;
}

void*
    seq_ptr
        (seq* par)                                   {
            if (trait_of(par) != seq_t) return null_t;
            return par->ptr + par->begin;
}

void
    seq_push_front
        (seq* par, void* par_src, u64_t par_len) {
            if (trait_of(par) != seq_t) return;
            if (!par_src)               return;
            if (!par_len)               return;

            if (seq_free_front(par) < par_len) seq_prep_front(par, par_len);
            par->begin -= par_len;

            u8_t *dst = par->ptr + par->begin;
            u8_t *src = par_src;
            u64_t len = par_len;

            mem_copy(dst, src, len);
}

void
    seq_push_back
        (seq* par, void* par_src, u64_t par_len) {
            if (trait_of(par) != seq_t) return;
            if (!par_src)               return;
            if (!par_len)               return;

            if (seq_free_back(par) < par_len) seq_prep_back(par, par_len);
            u8_t *dst = par->ptr + par->end;
            u8_t *src = par_src;
            u64_t len = par_len;

            mem_copy(dst, src, len);
            par->end += par_len;
}

void
    seq_push
        (seq* par, void* par_src, u64_t par_len, u64_t par_off) {
            if (trait_of(par) != seq_t) return;
            if (!par_src)               return;
            if (!par_len)               return;

            if (par_off > seq_len(par)) { seq_push_back (par, par_src, par_len); return; }
            if (par_off == 0)           { seq_push_front(par, par_src, par_len); return; }
            seq_prep(par, par_off, par_len);

            u8_t *dst = par->ptr + par->begin + par_off;
            u8_t *src = par_src;
            u64_t len = par_len;

            mem_copy(dst, src, len);
}

void
    seq_pop_front
        (seq* par, u64_t par_len)             {
            if (trait_of(par) != seq_t) return;
            if (!par_len)               return;
            if (par->begin < par_len)         {
                par->begin = 0;
                return;
            }

            par->begin -= par_len;
            mem_set(par->ptr + par->begin, 0x00, par_len);
}

void
    seq_pop_back
        (seq* par, u64_t par_len)             {
            if (trait_of(par) != seq_t) return;
            if (!par_len)               return;
            if (par_len >= seq_len(par))                          {
                mem_set(par->ptr + par->begin, 0x00, seq_len(par));
                par->end = par->begin;
            }

            par->end -= par_len;
            mem_set(par->ptr + par->end, 0x00, par_len);
}

void
    seq_pop
        (seq* par, u64_t par_off, u64_t par_len) {
            if (trait_of(par) != seq_t) return;
            if (!par_len)               return;

            if (par_off > par->end) { seq_pop_back (par, par_len); return; }
            if (par_off == 0)       { seq_pop_front(par, par_len); return; }
            u8_t *dst = par->ptr + par_off;
            u8_t *src = dst      + par_len;
            u64_t len = par_len;

            if (len > (par->end - par_off)) len = (par->end - par_off);
            mem_copy(dst, src, len);

            par->end -= par_len;
            mem_set(par->ptr + par->end, 0x00, par_len);
}