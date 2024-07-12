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

obj_trait foo_trait = make_trait (
    foo_new    ,
    foo_clone  ,
    foo_ref    ,
    foo_del    ,
	sizeof(foo),
	null_t
);

obj_trait* foo_t = &foo_trait;

int run()                          {
	list* fli = make(list) from (0);

	for(u64_t i = 0 ; i < 3 ; ++i) list_push_front(fli, make(foo) from(1, i));
	list_for(fli, pos)                  {
	    foo* ret = (foo*) as(pos, foo_t);
		println("%d", ret->num);
		del    (ret);
	}

	del(fli);
}