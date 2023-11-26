#include "str.h"
#include "details/str.h"

obj_trait* str_t = &__str_trait;

void 
    str_rsv_back 
        (str* par, u64_t par_size)            {
            if (!par)                   return;
            if (trait_of(par) != str_t) return;

            __str_rsv_back (par, par_size); 
}

void 
    str_rsv_front
        (str* par, u64_t par_size)            {
            if (!par)                   return;
            if (trait_of(par) != str_t) return;

            __str_rsv_front(par, par_size); 
}

void 
    str_push_back	    
        (str* par, str*  par_size)            {
            if (!par)                   return;
            if (trait_of(par) != str_t) return;
            __str_push_back	   (par, par_size); 
}

void 
    str_push_back_cstr 
        (str* par, const char* par_push, u64_t par_len) {
            if (!par)                   return;
            if (trait_of(par) != str_t) return;
            __str_push_back_cstr (par, par_push, par_len); 
}

void 
    str_push_front	    
        (str* par, str* par_push)             { 
            if (!par)                   return;
            if (trait_of(par) != str_t) return;

            __str_push_front(par, par_push); 
}

void 
    str_push_front_cstr
        (str* par, const char* par_push, u64_t par_len) { 
            if (!par)                   return;
            if (trait_of(par) != str_t) return;

            __str_push_front_cstr(par, par_push, par_len); 
}

void 
    str_push_at		
        (str* par, u64_t par_off, str* par_push)      {
            if (!par)                   return;
            if (trait_of(par) != str_t) return;

            __str_push_at		  (par, par_off, par_push); 
}

void 
    str_push_at_cstr   
        (str* par, u64_t par_off, const char* par_push, u64_t par_len) { 
            if (!par)                   return;
            if (trait_of(par) != str_t) return;
            __str_push_at_cstr   (par, par_off, par_push, par_len); 
}

void 
    str_pop_front
        (str* par, u64_t par_len)             { 
            if (!par)                   return;
            if (trait_of(par) != str_t) return;
            
            __str_pop_front(par, par_len); 
}

void 
    str_pop_back 
        (str* par, u64_t par_len)             {
            if (!par)                   return;
            if (trait_of(par) != str_t) return;

            __str_pop_back (par, par_len);
}

void 
    str_pop_at   
        (str* par, u64_t par_off, u64_t par_len)      { 
            if (!par)                   return;
            if (trait_of(par) != str_t) return;
            __str_pop_at   (par, par_off, par_len); 
}

u64_t
    str_find
        (str* par, u64_t par_off, str* par_find) {
            if (!par)                   return -1;
            if (trait_of(par) != str_t) return -1;

            return __str_find(par, par_off, par_find); 
}

u64_t
    str_find_cstr
        (str* par, u64_t par_off, const char* par_find, u64_t par_len) { 
            if (!par)                   return -1;
            if (trait_of(par) != str_t) return -1;

            return __str_find_cstr (
                par     ,
                par_off , 
                par_find, 
                par_len
            ); 
}

bool_t 
    str_eq
        (str* par, str* par_cmp)                      { 
            if (!par)                   return false_t;
            if (trait_of(par) != str_t) return false_t;

            return __str_eq(par, par_cmp);
}

bool_t 
    str_eq_cstr
        (str* par, const char* par_cmp, u64_t par_len) {
            if (!par)                   return false_t;
            if (trait_of(par) != str_t) return false_t;

            return __str_eq_cstr(par, par_cmp, par_len); 
}

bool_t 
    str_gt
        (str* par, str* par_cmp)                      {
            if (!par)                   return false_t;
            if (trait_of(par) != str_t) return false_t;

            return __str_gt(par, par_cmp);
}

bool_t 
    str_gt_cstr
        (str* par, const char* par_cmp, u64_t par_len) { 
            if (!par)                   return false_t;
            if (trait_of(par) != str_t) return false_t;

            return __str_gt_cstr(par, par_cmp, par_len); 
}

bool_t 
    str_lt
        (str* par, str* par_cmp)                      {
            if (!par)                   return false_t;
            if (trait_of(par) != str_t) return false_t;

            return __str_lt(par, par_cmp);
}

bool_t 
    str_lt_from_cstr
        (str* par, const char* par_cmp, u64_t par_len) { 
            if (!par)                   return false_t;
            if (trait_of(par) != str_t) return false_t;

            return __str_lt_cstr(par, par_cmp, par_len); 
}

bool_t 
    str_starts
        (str* par, str* par_cmp)                      {
            if (!par)                   return false_t;
            if (trait_of(par) != str_t) return false_t;

            return __str_starts(par, par_cmp);
}

bool_t 
    str_starts_cstr
        (str* par, const char* par_cmp, u64_t par_len) { 
            if (!par)                   return false_t;
            if (trait_of(par) != str_t) return false_t;

            return __str_starts_cstr(par, par_cmp, par_len); 
}

bool_t 
    str_ends
        (str* par, str* par_cmp)                      { 
            if (!par)                   return false_t;
            if (trait_of(par) != str_t) return false_t;

            return __str_ends(par, par_cmp); 
}

bool_t 
    str_ends_cstr
        (str* par, const char* par_cmp, u64_t par_len) {
            if (!par)                   return false_t;
            if (trait_of(par) != str_t) return false_t;

            return __str_ends_cstr(par, par_cmp, par_len);
}

bool_t 
    str_empty(str* par)                          {
        if (!par)                   return true_t;
        if (trait_of(par) != str_t) return true_t;
        return __str_empty(par); 
}

u64_t  
    str_len	
        (str* par)                              { 
            if (!par)                   return 0;
            if (trait_of(par) != str_t) return 0;
            return __str_len(par);
}

const char*
    str_ptr	
        (str* par)                              { 
            if (!par)                   return 0;
            if (trait_of(par) != str_t) return 0;
            return ((__str*)par)->mem + ((__str*)par)->front; 
}