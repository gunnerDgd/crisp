#include "bma.h"

bool_t
    bma_new
        (bma* self, u32_t count, va_list arg) {
            self->in  = (reg_t) -1;
            self->out = 0;
            return true_t;
}

bool_t bma_clone(bma* self, bma* clone) { return false_t; }
void   bma_del  (bma* self)             {                 }

bool_t
    bma_in_lock
        (bma* self, any_t in)                          {
            if (trait_of(self) != bma_t) return false_t;
            if (!self->in)               return false_t;
            u64_t pos = bsr64 (self->in);

            if (!lock_btr64(&self->in , pos)) return false_t;
            self->bma[pos] = in;

            if (lock_bts64(&self->out, pos)) return false_t;
            return true_t;
}

bool_t
    bma_in
        (bma* self, any_t in)                          {
            if (trait_of(self) != bma_t) return false_t;
            if (!self->in)               return false_t;
            u64_t pos = bsr64 (self->in);

            if (!btr64(&self->in , pos)) return false_t;
            self->bma[pos] = in;

            bts64(&self->out, pos);
            return true_t;
}

bool_t
    bma_out_lock
        (bma* self, any_t* out)                        {
            if (trait_of(self) != bma_t) return false_t;
            if (!out)                    return false_t;
            u64_t pos = bsr64 (self->out);

            if (!lock_btr64(&self->out, pos)) return false_t;
            *out = self->bma[pos];

            if (lock_bts64(&self->in , pos)) return false_t;
            return true_t;
}

bool_t
    bma_out
        (bma* self, any_t* out)                        {
            if (trait_of(self) != bma_t) return false_t;
            if (!out)                    return false_t;
            u64_t pos = bsr64 (self->out);

            if (!btr64(&self->out, pos)) return null_t;
            *out = self->bma[pos];

            bts64(&self->in , pos);
            return true_t;
}