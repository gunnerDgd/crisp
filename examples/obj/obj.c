#include <obj.h>
#include <stdio.h>

#include <intrin.h>

bool_t TestObjInit		 (obj* par_obj, u32_t par_count, va_list par) { printf("Object Created\n")									  ; return true_t; }
bool_t TestObjInitAsClone(obj* par    , obj* par_clone)				  { printf("Object Created As Clone\n")							  ; return true_t; }
bool_t TestObjInitAsRef  (obj* par)									  { printf("Object Referenced (Use Count : %d)\n", use_count(par)); return true_t; }
void   TestObjDeInit     (obj* par)									  { printf("Object Destroyed\n"); }

obj_trait TestObjTrait		     = {
	.on_new	  = &TestObjInit	   ,
	.on_clone = &TestObjInitAsClone,
	.on_ref   = &TestObjInitAsRef  ,
	.on_del	  = &TestObjDeInit	   ,
	.size	  = sizeof(obj) + 8
};

int main() {	
	obj* TestObj = make(&TestObjTrait) from (0);
	ref (TestObj);

	del (TestObj); printf("Object Dereferenced (Use Count : %d)\n", use_count(TestObj));
	del (TestObj);
}