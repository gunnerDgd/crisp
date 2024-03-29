#include "str.h"

obj_trait str_trait = make_trait (
    str_new    ,
    str_clone  ,
    null_t     ,
    str_del    ,
    sizeof(str),
    null_t
);

obj_trait *str_t = &str_trait;

bool_t
    str_new
        (str* par_str, u32_t par_count, va_list par)                      {
            mem *mem = null_t; if (par_count > 0) mem = va_arg(par, void*);
            if (trait_of(mem) != mem_t) mem = get_mem();
            if (trait_of(mem) != mem_t) return false_t;

            if (!make_at(&par_str->str, seq) from (1, mem)) return false_t;
            return true_t;
}

bool_t str_clone(str* par, str* par_clone) { return clone_at(&par->str, &par_clone->str); }
void   str_del  (str* par)		           { del(&par->str); }

void
    str_push_back
        (str* par, str* par_push)                  {
            if (trait_of(par_push) != str_t) return;
            if (trait_of(par_push) != str_t) return;
            u64_t len = seq_len(&par_push->str);
            void *src = seq_ptr(&par_push->str);
            seq  *dst = &par->str;

            seq_push_back(dst, src, len);
}

void
    str_push_front
        (str* par, str* par_push)                  {
            if (trait_of(par_push) != str_t) return;
            if (trait_of(par_push) != str_t) return;
            u64_t len = seq_len(&par_push->str);
            void *src = seq_ptr(&par_push->str);
            seq  *dst = &par->str;

            seq_push_front(dst, src, len);
}

void
    str_push
        (str* par, str* par_push, u64_t par_off)   {
            if (trait_of(par_push) != str_t) return;
            if (trait_of(par_push) != str_t) return;
            u64_t len = seq_len(&par_push->str);
            void *src = seq_ptr(&par_push->str);
            seq  *dst = &par->str;

            seq_push(dst, src, len, par_off);
}

void
    str_push_front_cstr
        (str* par, const char* par_push, u64_t par_len) {
            if (trait_of(par) != str_t) return;
            seq_push_front                    (
                &par->str,
                par_push ,
                par_len
            );
}

void
    str_push_back_cstr
        (str* par, const char* par_push, u64_t par_len) {
            if (trait_of(par) != str_t) return;
            seq_push_back                     (
                &par->str,
                par_push ,
                par_len
            );
}

void
    str_push_cstr
        (str* par, const char* par_push, u64_t par_len, u64_t par_off) {
            if (trait_of(par) != str_t) return;
            seq_push                          (
                &par->str,
                par_push ,
                par_len  ,
                par_off
            );
}

void
    str_pop_front
        (str* par, u64_t par_len)             {
            if (trait_of(par) != str_t) return;
            seq_pop_front(&par->str, par_len);
}

void
    str_pop_back
        (str* par, u64_t par_len)             {
            if (trait_of(par) != str_t) return;
            seq_pop_back(&par->str, par_len);
}

void
    str_pop
        (str* par, u64_t par_len, u64_t par_off) {
            if (trait_of(par) != str_t) return;
            seq_pop                           (
                &par->str,
                par_len,
                par_off
            );
}

void
    str_prep_front
        (str* par, u64_t par_len)             {
            if (trait_of(par) != str_t) return;
            seq_prep_front(&par->str, par_len);
}

void
    str_prep_back
        (str* par, u64_t par_len)             {
            if (trait_of(par) != str_t) return;
            seq_prep_back (&par->str, par_len);
}

u64_t
    str_find
        (str* par, u64_t par_off, str* par_find)      {
            if (trait_of(par_find) != str_t) return -1;
            if (trait_of(par)      != str_t) return -1;
            return mem_find                           (
                str_ptr(par) + par_off,
                str_ptr(par_find)     ,
                str_len(par)          ,
                str_len(par_find)
            );
}

u64_t
    str_find_cstr
        (str* par, u64_t par_off, const char* par_find, u64_t par_len) {
            if (trait_of(par_find) != str_t) return -1;
            return mem_find                           (
                str_ptr(par) + par_off,
                par_find              ,
                str_len(par)          ,
                par_len
            );
}

bool_t
    str_eq
        (str* par, str* par_cmp)                                {
            if (trait_of(par_cmp) != str_t)       return false_t;
            if (trait_of(par)     != str_t)       return false_t;
            if (str_len(par) != str_len(par_cmp)) return false_t;
            return mem_eq                                       (
                str_ptr(par)    ,
                str_ptr(par_cmp),
                str_len(par)    ,
                str_len(par_cmp)
            );
}

bool_t
    str_gt
        (str* par, str* par_cmp)                          {
            if (trait_of(par_cmp) != str_t) return false_t;
            if (trait_of(par)     != str_t) return false_t;
            return mem_gt                                 (
                str_ptr(par)    ,
                str_ptr(par_cmp),
                str_len(par)    ,
                str_len(par_cmp)
            );
}

bool_t
    str_lt
        (str* par, str* par_cmp)                          {
            if (trait_of(par_cmp) != str_t) return false_t;
            if (trait_of(par)     != str_t) return false_t;
            return mem_lt                                 (
                str_ptr(par)    ,
                str_ptr(par_cmp),
                str_len(par)    ,
                str_len(par_cmp)
            );
}

bool_t
    str_eq_cstr
        (str* par, const char* par_cmp, u64_t par_len) {
            if (trait_of(par) != str_t) return false_t;
            return mem_eq                             (
                str_ptr(par),
                par_cmp     ,
                str_len(par),
                par_len
            );
}

bool_t
    str_gt_cstr
        (str* par, const char* par_cmp, u64_t par_len) {
            if (trait_of(par) != str_t) return false_t;
            return mem_gt                             (
                str_ptr(par),
                par_cmp     ,
                str_len(par),
                par_len
            );
}

bool_t
    str_lt_cstr
        (str* par, const char* par_cmp, u64_t par_len) {
            if (trait_of(par) != str_t) return false_t;
            return mem_lt                             (
                str_ptr(par),
                par_cmp     ,
                str_len(par),
                par_len
            );
}

bool_t
    str_begin
        (str* par, str* par_cmp)                          {
            if (trait_of(par_cmp) != str_t) return false_t;
            if (trait_of(par)     != str_t) return false_t;
            u64_t  ret = str_find(par, 0, par_cmp);
            return ret == 0;
}

bool_t
    str_end
        (str* par, str* par_cmp)                          {
            if (trait_of(par_cmp) != str_t) return false_t;
            if (trait_of(par)     != str_t) return false_t;
            u64_t  off = str_len (par) - str_len(par_cmp);
            u64_t  ret = str_find(par, off, par_cmp);
            return ret == off;
}

bool_t
    str_begin_cstr
        (str* par, const char* par_cmp, u64_t par_len) {
            if (trait_of(par) != str_t) return false_t;
            u64_t ret = str_find_cstr                 (
                par    ,
                0      ,
                par_cmp,
                par_len
            );

            return ret == 0;
}

bool_t
    str_end_cstr
        (str* par, const char* par_cmp, u64_t par_len) {
            if (trait_of(par) != str_t) return false_t;
            u64_t  off = str_len (par) - par_len;
            u64_t  ret = str_find_cstr          (
                par    ,
                off    ,
                par_cmp,
                par_len
            );

            return ret == off;
}

bool_t
    str_empty
        (str* par)                                   {
            if (trait_of(par) != str_t) return true_t;
            return seq_empty(&par->str);
}

u64_t
    str_len
        (str* par)                              {
            if (trait_of(par) != str_t) return 0;
            return seq_len(&par->str);
}

const char*
    str_ptr
        (str* par)                                   {
            if (trait_of(par) != str_t) return null_t;
            return seq_ptr(&par->str);
}