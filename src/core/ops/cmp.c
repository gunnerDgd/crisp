#include "cmp.h"
#include "../obj.h"

ord_t  
    op_ord_arg(struct obj* self, any_t arg) {
        if (!trait_of(self)) return ord_err;

        obj_ops* ops = self->trait->ops; if (!ops) return ord_err;
        ops_cmp* cmp = ops->cmp;         if (!cmp) return ord_err;
        if   (!cmp->ord_arg) return ord_err;
        return cmp->ord_arg(self, arg);
}

ord_t
    op_ord(struct obj* self, struct obj* arg) {
        if (!trait_of(self)) return ord_err;
        if (!trait_of(arg))  return ord_err;

        obj_ops* ops = self->trait->ops; if (!ops) return ord_err;
        ops_cmp* cmp = ops->cmp;         if (!cmp) return ord_err;
        if   (!cmp->ord) return ord_err;
        return cmp->ord(self, arg);
}

bool_t op_gt_arg   (struct obj* self, any_t       arg) { return op_ord_arg(self, arg) == ord_gt; }
bool_t op_gt       (struct obj* self, struct obj* arg) { return op_ord    (self, arg) == ord_gt; }

bool_t op_gt_eq_arg(struct obj* self, any_t       arg) { return op_ord_arg(self, arg) == ord_gt | op_ord_arg(self, arg) == ord_eq; }
bool_t op_gt_eq    (struct obj* self, struct obj* arg) { return op_ord    (self, arg) == ord_gt | op_ord_arg(self, arg) == ord_eq; }

bool_t op_lt_arg   (struct obj* self, any_t       arg) { return op_ord_arg(self, arg) == ord_lt; }
bool_t op_lt       (struct obj* self, struct obj* arg) { return op_ord    (self, arg) == ord_lt; }

bool_t op_lt_eq_arg(struct obj* self, any_t       arg) { return op_ord_arg(self, arg) == ord_lt | op_ord_arg(self, arg) == ord_eq; }
bool_t op_lt_eq    (struct obj* self, struct obj* arg) { return op_ord    (self, arg) == ord_lt | op_ord_arg(self, arg) == ord_eq; }

bool_t op_eq_arg   (struct obj* self, any_t       arg) { return op_ord_arg(self, arg) == ord_eq; }
bool_t op_eq       (struct obj* self, struct obj* arg) { return op_ord    (self, arg) == ord_eq; }

bool_t op_ne_arg   (struct obj* self, any_t       arg) { return op_ord_arg(self, arg) != ord_eq; }
bool_t op_ne       (struct obj* self, struct obj* arg) { return op_ord    (self, arg) != ord_eq; }