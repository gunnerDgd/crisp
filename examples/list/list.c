#include <list.h>
#include <obj.h>
#include <iter.h>
#include <mem.h>

#include <stdio.h>
#include <stdlib.h>

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

obj_trait ob_type	   = {
	.on_new	  = &ob_init ,
	.on_clone = 0		 ,
	.on_ref   = 0		 ,
	.on_del	  = 0		 ,
	.size	  = sizeof(ob)
};

bool_t cstd_mem_res_new() { return true_t; }
void   cstd_mem_res_del() { return true_t; }

void*  cstd_mem_new(mem_res* par, u64_t par_size) { return malloc(par_size); }
void   cstd_mem_del(mem_res* par, void* par_del)  { free(par_del); }

mem_res_trait cstd_mem_res_trait = {
	.on_new = &cstd_mem_res_new,
	.on_del = &cstd_mem_res_del,

	.on_mem_new = &cstd_mem_new,
	.on_mem_del = &cstd_mem_del
};

mem_res cstd_mem_res;


int main() {
	mem_res_new(&cstd_mem_res, &cstd_mem_res_trait, 0);
	set_mem_res(&cstd_mem_res);

	list* list = make(list_t) from (0);

	for(u64_t i = 0 ; i < 3 ; ++i)			 {
		obj* push = make(&ob_type) from(1, i);
		list_push_front(list, push);
		del (push);
	}

	for (iter it = list_iter(list) ; !npos(it) ; it = next(it)) {
		printf("Value : %d\n", get_as(it, ob*)->value);
	}


	del(list);
}