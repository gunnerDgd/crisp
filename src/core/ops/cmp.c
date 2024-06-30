#include "cmp.h"
#include "../obj.h"

ord_t  
    ord_arg
        (struct obj* self, any_t arg)          {
            if (!trait_of(self)) return ord_err;

            obj_ops* ops = self->trait->ops; if (!ops) return ord_err;
            cmp     *cmp = ops->cmp;         if (!cmp) return ord_err;
            if   (!cmp->ord_arg) return ord_err;
            return cmp->ord_arg(self, arg);
}

ord_t
    ord
        (struct obj* self, struct obj* arg)    {
            if (!trait_of(self)) return ord_err;
            if (!trait_of(arg))  return ord_err;

            obj_ops *ops = self->trait->ops; if (!ops) return ord_err;
            cmp     *cmp = ops->cmp;         if (!cmp) return ord_err;
            if   (!cmp->ord) return ord_err;
            return cmp->ord(self, arg);
}

bool_t gt_arg   (struct obj* self, any_t       arg) { return ord_arg(self, arg) == ord_gt; }
bool_t gt       (struct obj* self, struct obj* arg) { return ord    (self, arg) == ord_gt; }

bool_t gt_eq_arg(struct obj* self, any_t       arg) { return ord_arg(self, arg) == ord_gt | ord_arg(self, arg) == ord_eq; }
bool_t gt_eq    (struct obj* self, struct obj* arg) { return ord    (self, arg) == ord_gt | ord_arg(self, arg) == ord_eq; }

bool_t lt_arg   (struct obj* self, any_t       arg) { return ord_arg(self, arg) == ord_lt; }
bool_t lt       (struct obj* self, struct obj* arg) { return ord    (self, arg) == ord_lt; }

bool_t lt_eq_arg(struct obj* self, any_t       arg) { return ord_arg(self, arg) == ord_lt | ord_arg(self, arg) == ord_eq; }
bool_t lt_eq    (struct obj* self, struct obj* arg) { return ord    (self, arg) == ord_lt | ord_arg(self, arg) == ord_eq; }

bool_t eq_arg   (struct obj* self, any_t       arg) { return ord_arg(self, arg) == ord_eq; }
bool_t eq       (struct obj* self, struct obj* arg) { return ord    (self, arg) == ord_eq; }

bool_t ne_arg   (struct obj* self, any_t       arg) { return ord_arg(self, arg) != ord_eq; }
bool_t ne       (struct obj* self, struct obj* arg) { return ord    (self, arg) != ord_eq; }