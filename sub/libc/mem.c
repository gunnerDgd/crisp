#include "../../src/core.h"

#include <stdlib.h>
#include <string.h>

any_t libc_mem_do_new(u32_t, va_list);
void  libc_mem_do_del(any_t);

void* libc_mem_do_acq(any_t, void*, u64_t);
void  libc_mem_do_rel(any_t, void*, u64_t);

mem     libc_mem;
mem_ops libc_mem_do = make_mem_ops (
        libc_mem_do_acq,
        libc_mem_do_rel,
        libc_mem_do_new,
        libc_mem_do_del
);

any_t   libc_mem_do_new(u32_t par_count, va_list par) { return &libc_mem_do; }
void    libc_mem_do_del(any_t par)                    {  }

void*
    libc_mem_do_acq
        (any_t par, void* par_acq, u64_t par_len) {
            if (par != &libc_mem_do) return null_t;
            if (!par_len)            return null_t;

            void   *ret = malloc(par_len); if  (!ret) return null_t;
            mem_set(ret, 0x00, par_len);
            return  ret;
}

void
    libc_mem_do_rel
        (any_t par, void* par_rel, u64_t par_len) {
            if (par != &libc_mem_do) return;
            if (!par_rel)            return;
            free(par_rel);
}

void mem_set (u8_t* des, u8_t  set, u64_t len) { memset(des, set, len); }
void mem_copy(u8_t* des, u8_t* src, u64_t len) { memcpy(des, src, len); }
void mem_move(u8_t* des, u8_t* src, u64_t len) { memcpy(des, src, len); memset(src, 0x00, len); }

u64_t
    mem_find
        (u8_t* des, u8_t* src, u64_t dlen, u64_t slen) {
            if (dlen > slen) return -1;
            return (u64_t) strstr     (
                des,
                src
            );
}

ord_t
    mem_ord
        (u8_t* src, u8_t* ops, u64_t len) {
            if (!src) return ord_err;
            if (!ops) return ord_err;
            if (!len) return ord_err;
            int res = strncmp       (
                src,
                ops,
                len
            );

            if (res < 0) return ord_lt;
            if (res > 0) return ord_gt;
            return ord_eq;
}

bool_t mem_eq(u8_t* src, u8_t* ops, u64_t len) { return mem_ord(src, ops, len) == ord_eq; }
bool_t mem_gt(u8_t* src, u8_t* ops, u64_t len) { return mem_ord(src, ops, len) == ord_gt; }
bool_t mem_lt(u8_t* src, u8_t* ops, u64_t len) { return mem_ord(src, ops, len) == ord_lt; }