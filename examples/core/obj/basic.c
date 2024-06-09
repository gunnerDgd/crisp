#include <core.h>

typedef struct foo {
    obj head;
}   foo;

bool_t foo_new	(foo* self, u32_t count, va_list arg) { println("Object Created")         ; return true_t; }
bool_t foo_clone(foo* self, foo* clone)               { println("Object Created As Clone"); return true_t; }
bool_t foo_ref  (foo* self)                           { println("Object Referenced")      ; return true_t; }
void   foo_del  (foo* self)                           { println("Object Destroyed")       ; }

obj_trait foo_trait = make_trait (
    foo_new    ,
    foo_clone  ,
    foo_ref    ,
    foo_del    ,
	sizeof(foo),
	null_t
);

obj_trait* foo_t = &foo_trait;

use()

int run()			             {
	obj* fob = make(foo) from (0);
	ref (fob); println("Use Count : %llu", use_count(fob));
	del (fob); println("Use Count : %llu", use_count(fob));
	del (fob);
}