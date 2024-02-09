#include "str.h"

obj_trait str_trait     = {
    .on_new   = &str_new  ,
    .on_clone = &str_clone,
    .on_ref   = 0         ,
    .on_del   = &str_del  ,
    .size     = sizeof(str)
};

obj_trait* str_t = &str_trait;

bool_t
	str_new
		(str* par_str, u32_t par_count, va_list par)                {
            mem *res = 0; if (par_count > 0) res = va_arg(par, mem*);
			if (!res)         res = get_mem();
			if (!res)         return false_t;
            if (!res->on_new) return false_t;
            if (!res->on_del) return false_t;

			par_str->mem = mem_new(res, 16); if (!par_str->mem) return false_t;
			mem_set(par_str->mem, 0x00, 16);
            par_str->res   = res;
			par_str->front = 0 ;
			par_str->back  = 0 ;
			par_str->size  = 16;
			par_str->len   = 0 ;

			return true_t;
}

bool_t
	str_clone
		(str* par, str* par_clone)		        {
			if (!par_clone->res)  return false_t;
			if (!par_clone->mem)  return false_t;
			if (!par_clone->size) return false_t;

			par->res  = par_clone->res ;
			par->size = par_clone->size;

			par->mem  = mem_new(par->res, par->size);
            if (!par->mem)
                return false_t;

			mem_copy(par->mem, par_clone->mem, par->size);
			par->len   = par_clone->len  ;
			par->front = par_clone->front;
			par->back  = par_clone->back ;

			return true_t;
}

void
	str_del
		(str* par)				       {
			mem_del(par->res, par->mem);
}

void 
    str_rsv_back 
        (str* par, u64_t par_size)                                  {
            if (trait_of(par) != str_t) return; u64_t len = par_size;
            if (!len) len = par->size;

            if (par_size > shl(len, 1)) len += par_size;

			u8_t* rsv = mem_new(par->res, len);
			if  (!rsv) return;

			mem_set (rsv, 0x00, len)							       ;
			mem_copy(rsv + par->front, par->mem + par->front, par->len);
			mem_del (par->res  , par->mem);

            par->mem  = rsv;
			par->size = len;
}

void 
    str_rsv_front
        (str* par, u64_t par_size)            {
            if (!par)                   return;
            if (trait_of(par) != str_t) return;

            u64_t rsv_size = shl(par->size, 1)          ; if (rsv_size < par_size) rsv_size = par_size + par->size;
			u8_t *rsv	   = mem_new(par->res, rsv_size); 
            if  (!rsv) return;

			mem_copy(rsv + par->front + par_size, par->mem + par->front, par->len);
			mem_del (par->res  , par->mem);

			par->mem    = rsv	  ;
			par->size   = rsv_size;
			par->front += rsv_size;
			par->back  += rsv_size;
}

void 
    str_push_back	    
        (str* par, str* par_push)                  {
            if (!par_push)                   return;
            if (trait_of(par_push) != str_t) return;
            str_push_back_cstr(par, str_as_cstr(par_push));
}

void 
    str_push_back_cstr 
        (str* par, cstr_t par_cstr)                                           {
            if (!par_cstr.len)          return; u64_t       len = par_cstr.len;
            if (!par_cstr.str)          return; const char *str = par_cstr.str;
            if (trait_of(par) != str_t) return; 

            if(par->size < (par->back + len + 1)) str_rsv_back(par, len + 1);
            if(par->size < (par->back + len + 1)) return;

			mem_copy(par->mem + par->back, str, len);
			par->back += len;
			par->len  += len;
}

void 
    str_push_front	    
        (str* par, str* par_push)                  {
            if (trait_of(par_push) != str_t) return;
            if (trait_of(par)      != str_t) return;
            str_push_front_cstr(par, str_as_cstr(par_push)); 
}

void 
    str_push_front_cstr
        (str* par, cstr_t par_cstr)                                           {
            if (!par_cstr.len)          return; u64_t       len = par_cstr.len;
            if (!par_cstr.str)          return; const char *str = par_cstr.str;
            if (trait_of(par) != str_t) return;

            if (len < par->front) str_rsv_front(par, len);
            if (len < par->front) return;

			par->front -= len;
			par->len   += len;
			mem_copy                 (
                par->mem + par->front, 
                str                  ,
                len
            );
}

void 
    str_push	
        (str* par, u64_t par_off, str* par_push)   {
            if (!par_push)                   return;
            if (trait_of(par_push) != str_t) return;
            str_push_cstr           (
                par                 ,
                par_off             ,
                str_as_cstr(par_push)
            );
}

void 
    str_push_cstr
        (str* par, u64_t par_off, cstr_t par_cstr)                            {
            if (!par_cstr.len)          return; u64_t       len = par_cstr.len;
            if (!par_cstr.str)          return; const char *str = par_cstr.str;
            if (trait_of(par) != str_t) return; u64_t       off = par->front  ;
            
            if (par_off > par->len) return str_push_back_cstr (par, par_cstr);
			if (par_off == 0)       return str_push_front_cstr(par, par_cstr);
			u8_t *ret = mem_new(par->res, len + par->size + 1);
            u8_t *old = par->mem;
            if  (!ret) return;

			par->size = par_cstr.len + par->size + 1;
            par->mem  = ret                         ;

			mem_set (ret, 0x00     , par->size)         ;
			mem_copy(ret, old + off, par_off)           ; ret += par_off; off += par_off   ;
			mem_copy(ret, str      , len)               ; ret += len    ; off += par->front;
			mem_copy(ret, old + off, par->len - par_off);

            mem_del (par->res, old);
			par->len  += len;
            par->front =   0;
            par->back  = len;
}

void 
    str_pop_front
        (str* par, u64_t par_len)             { 
            if (trait_of(par) != str_t) return;
            if (!par_len)               return;
            u64_t len = 0;

            if (par_len > par->len) len = par->len;
            if (!len)               len = par_len ;
            if (!len)               return;

            mem_set(par->mem + par->front, 0x00, len);
            par->len   -= len;
            par->front += len;
}

void 
    str_pop_back 
        (str* par, u64_t par_len)             {
            if (trait_of(par) != str_t) return;
            if (!par_len)               return;
            u64_t len = 0;

            if (par_len > par->len) len = par->len;
            if (!len)               len = par_len ;
            if (!len)               return;
            par->len  -= len;
            par->back -= len;

            mem_set                 (
                par->mem + par->back,
                0x00                ,
                len
            );
            
}

void 
    str_pop
        (str* par, u64_t par_off, u64_t par_len)                   {
            if (trait_of(par) != str_t) return; u64_t off = par_off;
            if (!par_len)               return; u64_t len = par_len;
            if ((off + len) > par->len) return;

            if (off > par->len) return str_pop_back (par, len);
			if (off == 0)       return str_pop_front(par, len);
			mem_copy                             (
				par->mem + par->front + off      ,
				par->mem + par->front + off + len,
				par->len - off - len
			);

			par->len          -= len;
			par->back         -= len;
			mem_set                 (
                par->mem + par->back,
                0x00                ,
                len
            );
}

u64_t
    str_find
        (str* par, u64_t par_off, str* par_find)           {
            if (!par_find)                   return false_t;
            if (trait_of(par_find) != str_t) return false_t;
            return str_find_cstr                           (
                par                 ,
                par_off             ,
                str_as_cstr(par_find)
            );
}

u64_t
    str_find_cstr
        (str* par, u64_t par_off, cstr_t par_cstr)                               {
            if (!par_cstr.str)          return -1; const char *str = par_cstr.str;
            if (!par_cstr.len)          return -1; u64_t       len = par_cstr.len;
            if (trait_of(par) != str_t) return -1; u64_t       off = par_off     ;
            if (par->len < off)         return -1;
            if (par->len < (off + len)) return -1;

            u64_t find = par->mem + par->front + off  ;
            u64_t ran  = par->len - par_off           ;
            u64_t ret  = mem_find(find, str, ran, len);

            if (ret == -1) return -1;
			return off + ret;
}

bool_t 
    str_eq
        (str* par, str* par_cmp)                          {
            if (trait_of(par_cmp) != str_t) return false_t;
            if (trait_of(par)     != str_t) return false_t;
            return str_eq_cstr(par, str_as_cstr(par_cmp));
}

bool_t 
    str_eq_cstr
        (str* par, cstr_t par_cstr)                                                           {
            if (!par_cstr.str)                  return false_t; const char *str = par_cstr.str;
            if (!par_cstr.len)                  return false_t; u64_t       len = par_cstr.len;
            if (trait_of(par) != str_t)         return false_t;
            if (par->back < (par->front + len)) return false_t;
            return mem_eq                                     (
                par->mem + par->front,
                str                  ,
                len
            );
}

bool_t
    str_gt
        (str* par, str* par_cmp)                          {
            if (trait_of(par_cmp) != str_t) return false_t;
            if (trait_of(par)     != str_t) return false_t;
            return str_gt_cstr(par, str_as_cstr(par_cmp));
}

bool_t 
    str_gt_cstr
        (str* par, cstr_t par_cstr)                                                           {
            if (!par_cstr.str)                  return false_t; const char *str = par_cstr.str;
            if (!par_cstr.len)                  return false_t; u64_t       len = par_cstr.len;
            if (trait_of(par) != str_t)         return false_t;
            if (par->back < (par->front + len)) return false_t;
            return mem_gt			                          (
				par->mem + par->front, 
                str                  ,
                len
			); 
}

bool_t 
    str_lt
        (str* par, str* par_cmp)                          {
            if (!par_cmp)                   return false_t;
            if (trait_of(par_cmp) != str_t) return false_t;
            return str_lt_cstr(par, str_as_cstr(par_cmp));
}

bool_t 
    str_lt_cstr
        (str* par, cstr_t par_cstr)                                                   {
            if (!par_cstr.str)          return false_t; const char *str = par_cstr.str;
            if (!par_cstr.len)          return false_t; u64_t       len = par_cstr.len;
            if (trait_of(par) != str_t) return false_t;
            return mem_lt			                  (
				par->mem + par->front,
                str                  ,
                len
			); 
}

bool_t 
    str_starts
        (str* par, str* par_cmp)                          {
            if (trait_of(par_cmp) != str_t) return false_t;
            if (trait_of(par)     != str_t) return false_t;
            return str_starts_cstr(par, str_as_cstr(par_cmp));
}

bool_t 
    str_starts_cstr
        (str* par, cstr_t par_cstr)                                                   {
            if (!par_cstr.str)          return false_t; const char* str = par_cstr.str;
            if (!par_cstr.len)          return false_t; u64_t       len = par_cstr.len;
            if (trait_of(par) != str_t) return false_t;
            if (len > str_len(par))     return false_t;
			return mem_eq			                  (
                par->mem + par->front, 
                str				     ,
                len
			);
}

bool_t 
    str_ends
        (str* par, str* par_cmp)                          { 
            if (!par_cmp)                   return false_t;
            if (trait_of(par_cmp) != str_t) return false_t;
            return str_ends_cstr(par, str_as_cstr(par_cmp));
}

bool_t 
    str_ends_cstr
        (str* par, cstr_t par_cstr)                                                   {
            if (!par_cstr.str)          return false_t; const char* str = par_cstr.str;
            if (!par_cstr.len)          return false_t; u64_t       len = par_cstr.len;
            if (trait_of(par) != str_t) return false_t;
            if (len > par->len)         return false_t;
			return mem_eq					          (
				par->mem + par->back - len,
                str                       ,
                len
			);
}

bool_t 
    str_empty
        (str* par)                                   {
            if (trait_of(par) != str_t) return true_t;
            return par->len == 0; 
}

u64_t  
    str_len	
        (str* par)                              {
            if (trait_of(par) != str_t) return 0;
            return par->len;
}

const char*
    str_as_raw	
        (str* par)                              {
            if (trait_of(par) != str_t) return 0;
            return par->mem + par->front;
}

cstr_t
    str_as_cstr
        (str* par)       {
            cstr_t ret = {
                .str = 0,
                .len = 0
            };

            if (trait_of(par) != str_t) return ret;
            ret.str = str_as_raw(par);
            ret.len = str_len   (par);
            return ret;
}