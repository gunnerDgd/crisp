#include <stdio.h>

#include <crisp/obj.h>
#include <crisp/list.h>

bool_t TestInit(obj* par_test, u32_t par_arg_count, va_list par_arg) {
	//printf("%d %d\n", par_arg_count, va_arg(par_arg, int));
	return true_t;
}

typedef struct Test 		 { obj head; int i; } Test;
obj_trait  TestObjectTrait = {
	.init 		   = TestInit,
	.init_as_clone = 		0,
	.init_as_ref   = 		0,
	.deinit 	   = 		0
};

int main() {
	list       list;
	list_init(&list, get_default_alloc());

	for(int i = 0 ; i < 10 ; i++) {
		Test* obj = obj_init(get_default_alloc(), sizeof(Test), &TestObjectTrait, 1, i);

		obj->i = i;
		list_push_front(&list, obj);
		printf("Use Count : %d\n", obj_use_count(obj));
		obj_deinit(obj);
		printf("Use Count : %d\n", obj_use_count(obj));
	}

	list_iter iter = list_iter_begin(&list);
	while(iter != list_iter_end(&list)) {
		Test* ptr = list_iter_object(iter);
		printf("%d\n", ptr->i);

		iter = list_iter_next(iter);
	}
}