#include <core.h>
#include <stdio.h>

typedef struct test { obj head; } test;

bool_t test_new	 (obj* par_obj, u32_t par_count, va_list par) { printf("Object Created\n")		   ; return true_t; }
bool_t test_clone(obj* par    , obj* par_clone)				  { printf("Object Created As Clone\n"); return true_t; }
bool_t test_ref  (obj* par)									  { printf("Object Referenced\n")	   ; return true_t; }
void   test_del  (obj* par)									  { printf("Object Destroyed\n")	   ; }

obj_trait test_trait = make_trait (
	test_new    ,
	test_clone  ,
	test_ref    ,
	test_del    ,
	sizeof(test),
	null_t
);

obj_trait* test_t = &test_trait;

use()

int run()			                  {
	obj* test_obj = make(test) from (0);
	ref (test_obj); printf("Use Count : %llu\n", use_count(test_obj));
	del (test_obj); printf("Use Count : %llu\n", use_count(test_obj));
	del (test_obj);
}