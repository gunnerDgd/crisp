#include "../../core.h"
#include <string.h>

void
    mem_set
        (u8_t* des, u8_t set, u64_t len) {
            if (!des) return;
            if (!len) return;

            for ( ; len-- ; des[len] = set);
}

void
    mem_copy
        (u8_t* des, u8_t* src, u64_t len)    {
            if (!des) return;
            if (!src) return;
            if (!len) return;

            while(len--) *des++ = *src++;
}

void
    mem_move
        (u8_t* des, u8_t* src, u64_t len) {
            if (!des) return;
            if (!src) return;
            if (!len) return;

            for (u64_t i = 0 ; i < len ; ++i) {
                des[i] = src[i];
                src[i] = 0     ;
            }
}

u64_t
    mem_find
        (u8_t* tar, u8_t* src, u64_t len, u64_t end) {
            if (len < end) return -1;
            if (!end)      return -1;
            if (!tar)      return -1;
            if (!src)      return -1;
            len -= end;

            for (u64_t i = 0 ; i < len ; ++i) if (mem_eq(tar + i, src, end)) return i;
            return -1;
}

ord_t
    mem_ord
        (u8_t* src, u8_t* cmp, u64_t len) {
            if (!src) return ord_err;
            if (!cmp) return ord_err;
            if (!len) return ord_err;

            while (len--)                     {
                if (*src > *cmp) return ord_gt;
                if (*src < *cmp) return ord_lt;
                ++src;
                ++cmp;
            }
            return ord_eq;
}

bool_t mem_eq(u8_t* src, u8_t* cmp, u64_t len) { return mem_ord(src, cmp, len) == ord_eq; }
bool_t mem_gt(u8_t* src, u8_t* cmp, u64_t len) { return mem_ord(src, cmp, len) == ord_gt; }
bool_t mem_lt(u8_t* src, u8_t* cmp, u64_t len) { return mem_ord(src, cmp, len) == ord_lt; }