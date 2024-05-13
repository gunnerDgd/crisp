#include "mem.h"
#include "macro.h"

obj_trait mem_trait = make_trait (
    mem_new    ,
    mem_clone  ,
    null_t     ,
    mem_del    ,
    sizeof(mem),
    null_t
);

obj_trait *mem_t = &mem_trait;

bool_t
    mem_new
        (mem* par_mem, u32_t par_count, va_list par)                             {
            mem_ops *ops = null_t; if (par_count > 0) ops = va_arg(par, mem_ops*);
            if (!ops)         return false_t;
            if (!ops->on_acq) return false_t;
            if (!ops->on_rel) return false_t;
            if (!ops->on_new) return false_t;
            if (!ops->on_del) return false_t;

            par_mem->mem = ops->on_new(par_count - 1, par);
            par_mem->ops = ops;

            if (!par_mem->mem) return false_t;
            return true_t;
}

bool_t
    mem_clone
        (mem* par, mem* par_clone) {
            return false_t;
}

void
    mem_del
        (mem* par)                    {
            par->ops->on_del(par->mem);
}

void*
    mem_acq
        (mem* self, void* hint, u64_t len)            {
            if (trait_of(self) != mem_t) return null_t;
            if (!len)                    return null_t;
            void* ret = self->ops->on_acq             (
                self->mem,
                hint     ,
                len
            );

            mem_set(ret, 0x00, len);
            return  ret;
}

void
    mem_rel
        (mem* self, void* rel, u64_t len)      {
            if (trait_of(self) != mem_t) return;
            if (!rel)                    return;
            return self->ops->on_rel           (
                self->mem,
                rel      ,
                len
            );
}

void
    mem_set
        (void* par, u8_t par_set, u64_t par_size)      {
            if (!par_size) return; u64_t len = par_size;
            if (!par)      return; u8_t* dst = par     ;
            while(len--) dst[len] = par_set;
}

void
    mem_copy
        (void* par, void* par_src, u64_t par_size)    {
            if(!par_size) return; u64_t len = par_size;
            if(!par_src)  return; u8_t *src = par_src ;
            if(!par)      return; u8_t *dst = par     ;
            while(len--) *dst++ = *src++;
}

void
    mem_move
        (void* par, void* par_src, u64_t par_size)    {
            if(!par_size) return; u64_t len = par_size;
            if(!par_src)  return; u8_t *src = par_src ;
            if(!par)      return; u8_t *dst = par     ;
            for (u64_t i = 0 ; i < len ; ++i)         {
                dst[i] = src[i];
                src[i] = 0     ;
            }
}

u64_t
    mem_find
        (void* par, void* par_cmp, u64_t par_len, u64_t par_cmp_len)           {
            if (!par_cmp_len)      return -1; u64_t cmp_len = par_cmp_len      ;
            if (!par_len)          return -1; u64_t src_len = par_len          ;
            if (!par_cmp)          return -1; u8_t *cmp     = par_cmp          ;
            if (!par)              return -1; u8_t *src     = par              ;
            if (src_len < cmp_len) return -1; u64_t len     = src_len - cmp_len;
            for(u8_t i = 0 ; i <= len ; ++i)                                   {
                if (mem_eq(src + i, cmp, src_len, cmp_len))
                    return i;
            }

            return -1;
}

bool_t
    mem_eq
        (void* par, void* par_cmp, u64_t par_len, u64_t par_cmp_len)       {
            if (!par_cmp)               return false_t; u8_t *cmp = par_cmp;
            if (!par)                   return false_t; u8_t *src = par    ;
            if (par_cmp_len != par_len) return false_t; u64_t len = par_len;

            for (u64_t i = 0 ; i < len ; ++i) if (src[i] != cmp[i]) return false_t;
            return true_t;
}

bool_t
    mem_gt
        (void* par, void* par_cmp, u64_t par_len, u64_t par_cmp_len)     {
            if (!par_cmp)     return false_t; u8_t *cmp = par_cmp;
            if (!par)         return false_t; u8_t *src = par    ;
            if (!par_cmp_len) return false_t;
            if (!par_len)     return false_t;

            u64_t len = max(par_len, par_cmp_len);
            for (u64_t i = 0 ; i < len ; ++i) if (src[i] < cmp[i]) return false_t;

            if (par_cmp_len == par_len)                         {
                if (src[len - 1] == cmp[len - 1]) return false_t;
                return true_t;
            }

            if (par_cmp_len > par_len) return false_t;
            return true_t;
}

bool_t
    mem_lt
        (void* par, void* par_cmp, u64_t par_len, u64_t par_cmp_len)     {
            if (!par_cmp)     return false_t; u8_t *cmp = par_cmp;
            if (!par)         return false_t; u8_t *src = par    ;
            if (!par_cmp_len) return false_t;
            if (!par_len)     return false_t;

            u64_t len = max(par_len, par_cmp_len);
            for (u64_t i = 0 ; i < len ; ++i) if (src[i] < cmp[i]) return false_t;

            if (par_cmp_len == par_len)                         {
                if (src[len - 1] == cmp[len - 1]) return false_t;
                return true_t;
            }

            if (par_cmp_len < par_len) return false_t;
            return true_t;
}