#include <obj.h>
#include <stdio.h>

bool_t
	TestObjInit
		(obj* par_obj) {
			printf("Object Created\n");
			return true_t;
}

bool_t
	TestObjInitAsClone
		(obj* par_obj, obj* par_obj_clone) {
			printf("Object Created As Clone\n");
			return true_t;
}

bool_t
	TestObjInitAsRef
		(obj* par_obj) {
			printf("Object Referenced (Use Count : %d)\n", obj_use_count(par_obj));
			return true_t;
}

void
	TestObjDeInit
		(obj* par_obj) {
			printf("Object Destroyed\n");
}

u64_t
	TestObjSize() {
		return sizeof(obj) + 32;	
}

obj_trait TestObjTrait = {
	.init		   = &TestObjInit		,
	.init_as_clone = &TestObjInitAsClone,
	.init_as_ref   = &TestObjInitAsRef  ,
	.deinit        = &TestObjDeInit	    ,
	.size		   = &TestObjSize
};

int main() {
	obj* TestObj = obj_init(0, &TestObjTrait, 0);
	obj_init_as_ref(TestObj);

	obj_deinit(TestObj); printf("Object Deinit Operation (Use Count : %d)\n", obj_use_count(TestObj));
	obj_deinit(TestObj);
}