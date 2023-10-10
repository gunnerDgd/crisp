#include <list.h>
#include <stdio.h>

struct ListElement {
	obj   head ;
	u64_t value;
};

u64_t
	ListElementSize() {
		return sizeof(struct ListElement);
}

bool_t
	ListElementInit
		(struct ListElement* par_obj, u32_t par_arg_count, va_list par_arg) {
			par_obj->value = va_arg(par_arg, u64_t);
			return true_t;
}

obj_trait ListElementTrait = {
	.init		   = &ListElementInit,
	.init_as_clone = 0				 ,
	.init_as_ref   = 0				 ,
	.deinit		   = 0				 ,
	.size		   = &ListElementSize
};

int main() {
	list List;
	list_init(&List, 0);

	for(u64_t i = 0 ; i < 10 ; ++i) {
		list_push_front(&List, obj_init(0, &ListElementTrait, 1, i));
	}

	it i = list_begin(&List), i_end = list_end(&List);

	for( ; !it_eq(&i, &i_end) ; it_next(&i))
		printf("List Element : %d\n", ((struct ListElement*)it_get(&i))->value);
}