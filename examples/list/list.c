#include <list.h>
#include <obj.h>

#include <stdio.h>

typedef struct TestObj {
	obj   head ;
	u64_t value;
}	TestObj;

bool_t TestObjInit(TestObj* par_obj, u32_t par_count, va_list par) { par_obj->value = va_arg(par, u64_t); return true_t; }
u64_t  TestObjSize()											   { return sizeof(TestObj); }

obj_trait TestObjTrait		   = {
	.init		   = &TestObjInit,
	.init_as_clone = 0			 ,
	.init_as_ref   = 0			 ,
	.deinit		   = 0			 ,
	.size		   = &TestObjSize
};

int main() {
	list* list = make(list_t) from (1, NULL);

	for(u64_t i = 0 ; i < 10 ; ++i)				  {
		obj* push = make(&TestObjTrait) from(1, i);
		list_push_front(list, push);
		del (push);
	}

	it it     = list_begin(list), 
	   it_end = list_end  (list);

	for( ; neq(it, it_end) ; next(it))
		printf("List Element : %d\n", get_as(it, TestObj*)->value);
}