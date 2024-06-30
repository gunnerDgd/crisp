#include "str.h"

static str*
    do_add
        (str* self, str* arg)                         {
            if (trait_of(self) != str_t) return null_t;
            if (trait_of(arg)  != str_t) return null_t;
            str* ret = make (str) from (0);

            if (trait_of(ret) != str_t) return null_t;
            seq_push_back(&ret->str, &self->str, str_len(self));
            seq_push_back(&ret->str, &arg ->str, str_len(arg)) ;
            return ret;
}

static str*
    do_add_eq
        (str* self, str* arg)                         {
            if (trait_of(self) != str_t) return null_t;
            if (trait_of(arg)  != str_t) return null_t;

            seq_push_back(&self->str, &arg->str, str_len(arg));
            return self;
}

static str*
    do_mul
        (str* self, u64_t num)                        {
            if (trait_of(self) != str_t) return null_t;
            if (!num)                    return null_t;
            str* ret = make (str) from (0);

            if (trait_of(ret) != str_t) return null_t;
            while (num --) seq_push_back(&ret->str, &self->str, str_len(self));
            return ret;
}

static arith
    do_arith = make_arith (
        do_add   ,
        null_t   ,
        do_mul   ,
        null_t   ,
        null_t   ,
        do_add_eq,
        null_t   ,
        null_t   ,
        null_t   ,
        null_t
);

static ord_t
    do_ord
        (str* self, str* arg)                          {
            if (trait_of(self) != str_t) return ord_err;
            if (trait_of(arg)  != str_t) return ord_err;
            u64_t len;

            len = min (str_len(self), str_len(arg));
            return mem_ord    (
                str_ptr(self),
                str_ptr(arg) ,
                len
            );
}

static ord_t
    do_ord_arg
        (str* self, const char* arg)                   {
            if (trait_of(self) != str_t) return ord_err;
            if (!arg)                    return ord_err;
            u64_t len = str_len(self);
            u8_t* pos = str_ptr(self);

            for (u64_t i = 0 ; i < len ; ++i)     {
                if (pos[i] > arg[i]) return ord_gt;
                if (pos[i] < arg[i]) return ord_lt;
                if (arg[i] == '\0')  return ord_gt;
            }

            if (arg[len] != '\0') return ord_lt;
            return ord_eq;
}

static cmp
    do_cmp = make_cmp (
        do_ord_arg,
        do_ord
);

static obj_ops
    do_ops =              {
        .arith = &do_arith,
        .cmp   = &do_cmp
};

static bool_t
    do_new
        (str* self, u32_t count, va_list arg)                         {
            mem *mem = null_t; if (count > 0) mem = va_arg(arg, void*);
            if (trait_of(mem) != mem_t) mem = get_mem();
            if (trait_of(mem) != mem_t) return false_t;

            if (!make_at(&self->str, seq) from (2, 16, mem)) return false_t;
            return true_t;
}

static bool_t
    do_clone
        (str* self, str* clone)                     {
            return clone_at(&self->str, &clone->str);
}

static void
    do_del
        (str* self)        {
            del(&self->str);
}

static obj_trait
    do_obj = make_trait (
        do_new     ,
        do_clone   ,
        null_t     ,
        do_del     ,
        sizeof(str),
        &do_ops
);

obj_trait *str_t = &do_obj;

void
    str_push
        (str* self, const char* push, u64_t len, u64_t off) {
            if (trait_of(self) != str_t) return;
            seq_push         (
                &self->str,
                push      ,
                len       ,
                off
            );
}

void
    str_push_front
        (str* self, const char* push, u64_t len) {
            if (trait_of(self) != str_t) return;
            seq_push_front   (
                &self->str,
                push      ,
                len
            );
}

void
    str_push_back
        (str* self, const char* push, u64_t len) {
            if (trait_of(self) != str_t) return;
            seq_push_back (
                &self->str,
                push      ,
                len
            );
}

void
    str_pop_front
        (str* self, u64_t len)                 {
            if (trait_of(self) != str_t) return;
            seq_pop_front(&self->str, len);
}

void
    str_pop_back
        (str* self, u64_t len)                 {
            if (trait_of(self) != str_t) return;
            seq_pop_back(&self->str, len);
}

void
    str_pop
        (str* self, u64_t len, u64_t off)      {
            if (trait_of(self) != str_t) return;
            seq_pop          (
                &self->str,
                len       ,
                off
            );
}

void
    str_prep_front
        (str* self, u64_t len)                 {
            if (trait_of(self) != str_t) return;
            seq_prep_front(&self->str, len);
}

void
    str_prep_back
        (str* self, u64_t len)                 {
            if (trait_of(self) != str_t) return;
            seq_prep_back (&self->str, len);
}

u64_t
    str_find
        (str* self, u64_t off, const char* find, u64_t len) {
            if (trait_of(self) != str_t) return -1;
            if (!find)                   return -1;
            return mem_find                       (
                str_ptr(self) + off,
                find               ,
                str_len(self)      ,
                len
            );
}

bool_t
    str_begin
        (str* self, const char* cmp, u64_t len)        {
            if (trait_of(self) != str_t) return false_t;
            if (!cmp)                    return false_t;
            if (!len)                    return false_t;
            u64_t ret = str_find (
                self,
                0   ,
                cmp ,
                len
            );

            return ret == 0;
}

bool_t
    str_end
        (str* self, const char* cmp, u64_t len)        {
            if (trait_of(self) != str_t) return false_t;
            if (!cmp)                    return false_t;
            if (!len)                    return false_t;
            u64_t  off = str_len (self) - len;
            u64_t  ret = str_find            (
                self,
                off ,
                cmp ,
                len
            );

            return ret == off;
}

bool_t      str_empty(str* self) { if (trait_of(self) != str_t) return true_t; return seq_empty(&self->str); }
u64_t       str_len  (str* self) { if (trait_of(self) != str_t) return 0;      return seq_len  (&self->str); }
const char* str_ptr  (str* self) { if (trait_of(self) != str_t) return null_t; return seq_ptr  (&self->str); }