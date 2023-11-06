#include <obj.h>
#include <stdio.h>

#include <intrin.h>

bool_t TestObjInit		 (obj* par_obj, u32_t par_count, va_list par) { printf("Object Created\n")									  ; return true_t; }
bool_t TestObjInitAsClone(obj* par    , obj* par_clone)				  { printf("Object Created As Clone\n")							  ; return true_t; }
bool_t TestObjInitAsRef  (obj* par)									  { printf("Object Referenced (Use Count : %d)\n", use_count(par)); return true_t; }
void   TestObjDeInit     (obj* par)									  { printf("Object Destroyed\n"); }
u64_t  TestObjSize()												  { return sizeof(obj) + 4; }

obj_trait TestObjTrait				  = {
	.init		   = &TestObjInit		,
	.init_as_clone = &TestObjInitAsClone,
	.init_as_ref   = &TestObjInitAsRef  ,
	.deinit		   = &TestObjDeInit		,
	.name		   =				   0,
	.size		   = &TestObjSize
};

int main() {	
	obj* TestObj = make(&TestObjTrait) from (0);
	ref (TestObj);

	del (TestObj); printf("Object Dereferenced (Use Count : %d)\n", use_count(TestObj));
	del (TestObj);
}