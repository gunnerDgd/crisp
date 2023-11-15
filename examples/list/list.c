#include <list.h>
#include <obj.h>

#include <stdio.h>

typedef struct ob {
	obj   head ;
	u64_t value;
}	ob;

bool_t 
	ob_init
		(ob* par_obj, u32_t par_count, va_list par) { 
			par_obj->value = va_arg(par, u64_t); 
			return true_t; 
}

u64_t 
	ob_size()			 {
		return sizeof(ob); 
}

obj_trait ob_type		   = {
	.init		   = &ob_init,
	.init_as_clone = 0		 ,
	.init_as_ref   = 0		 ,
	.deinit		   = 0		 ,
	.size		   = &ob_size
};

int main() {
	list* list = make(list_t) from (0);

	for(u64_t i = 0 ; i < 10 ; ++i)			 {
		obj* push = make(&ob_type) from(1, i);
		list_push_front(list, push);
		del (push);
	}

	list_for(list, ob_it)
		printf("List Element : %d\n", get_as(ob_it, ob*)->value);
}