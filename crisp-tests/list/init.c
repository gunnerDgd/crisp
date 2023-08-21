#include <stdio.h>

#include <crisp/obj.h>
#include <crisp/list.h>

c_bool_t TestInit(void* par_test, int par_arg_count, va_list par_arg) {
	printf("%d %d\n", par_arg_count, va_arg(par_arg, int));
	return c_true;
}

typedef struct Test 		     { int i; } Test;
c_obj_trait_t  TestObjectTrait = {
	.init 		   = TestInit,
	.init_as_clone = 0,
	.init_as_ref   = 0,
	.deinit 	   = 0,
};

int main() {
	c_list_t     list;
	c_list_init(&list, c_global_alloc());

	for(int i = 0 ; i < 10 ; i++) {
		c_obj_t obj     = c_obj_init(c_global_alloc(), sizeof(Test), &TestObjectTrait, 1, i);
		Test*   obj_ptr = c_obj_ptr(obj);

		obj_ptr->i = i;
		c_list_push_front(&list, obj);
	}

	c_list_iter_t iter = c_list_iter_begin(&list);
	while(iter != c_list_iter_end(&list)) {
		Test* ptr = c_obj_ptr(c_list_iter_object(iter));
		printf("%d\n", ptr->i);

		iter = c_list_iter_next(iter);
	}
}