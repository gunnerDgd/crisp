#include <core.h>
#include <collections.h>

use()

typedef struct foo {
    obj head;
    int num;
}   foo;

bool_t foo_new	(foo* self, u32_t count, va_list arg) { println("Object Created")         ; self->num = va_arg(arg, u64_t); return true_t; }
bool_t foo_clone(foo* self, foo* clone)               { println("Object Created As Clone"); return true_t; }
bool_t foo_ref  (foo* self)                           { println("Object Referenced")      ; return true_t; }
void   foo_del  (foo* self)                           { println("Object Destroyed")       ; }

ord_t
    foo_ord_arg
        (foo* self, u64_t ops)                 {
	        if (self->num == ops) return ord_eq;
	        if (self->num <  ops) return ord_lt;
	        if (self->num >  ops) return ord_gt;
	        return ord_err;
}

ord_t
    foo_ord
        (foo* self, foo* ops)		                {
	        if (self->num == ops->num) return ord_eq;
	        if (self->num <  ops->num) return ord_lt;
	        if (self->num >  ops->num) return ord_gt;
	        return ord_err;
}

ops_cmp foo_cmp = make_ops_cmp(foo_ord, foo_ord_arg);
obj_ops foo_ops = {
    .cmp = &foo_cmp
};

obj_trait foo_trait = make_trait (
    foo_new    ,
    foo_clone  ,
    foo_ref    ,
    foo_del    ,
	sizeof(foo),
	&foo_ops
);

obj_trait* foo_t = &foo_trait;

int run()			                  {
	map* fma  = make (map) from (0)   ;
	obj* foo1 = make (foo) from (1, 0);
	obj* foo2 = make (foo) from (1, 1);

    node* fno1 = map_move(fma, foo1);
    node* fno2 = map_move(fma, foo2);

	foo* val1 = value(map_find(fma, (any_t) 0));
	foo* val2 = value(map_find(fma, (any_t) 1));

	println ("VAL1 : %d", (trait_of(val1) == foo_t) ? val1->num : -1);
	println ("VAL2 : %d", (trait_of(val2) == foo_t) ? val2->num : -1);

	del (fma);
}