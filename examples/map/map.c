#include <map.h>
#include <stdlib.h>

void* cstd_mem_new(mem* par, u64_t par_size) { return malloc(par_size); }
void  cstd_mem_del(mem* par, void* par_del)  { free(par_del); }

mem cstd_mem		     = {
	.on_new = &cstd_mem_new,
	.on_del = &cstd_mem_del
};

typedef struct test {
	obj   head ;
	u64_t value;
}	test;

bool_t test_new	 (test* par_obj, u32_t par_count, va_list par) { par_obj->value = va_arg(par, u64_t); return true_t; }
bool_t test_clone(test* par    , test* par_clone)			   { par->value     = par_clone->value  ; return true_t; }
bool_t test_ref  (test* par)								   { return true_t; }
void   test_del  (test* par)								   { }

obj_trait test_t		 = {
	.on_new	  = &test_new  ,
	.on_clone = &test_clone,
	.on_ref   = &test_ref  ,
	.on_del	  = &test_del  ,
	.size	  = sizeof(test)
};

bool_t map_eq (test* par, test* par_cmp) { return par->value == par_cmp->value; }
bool_t map_lt (test* par, test* par_cmp) { return par->value <  par_cmp->value; }
bool_t map_gt (test* par, test* par_cmp) { return par->value >  par_cmp->value; }

map_key ops =		 {
	.eq     = &map_eq,
	.lt     = &map_lt,
	.gt     = &map_gt
};

int main()			  {
	set_mem(&cstd_mem);

	map* map   = make (map_t)   from (1, &ops);
	obj* push1 = make (&test_t) from (1, 0)   ; node* elem1 = map_push(map, push1);
	obj* push2 = make (&test_t) from (1, 1)   ; node* elem2 = map_push(map, push2);
	obj* key1  = make (&test_t) from (1, 0)   ;
	obj* key2  = make (&test_t) from (1, 2)   ;

	obj* key_val1 = value(map_find(map, key1));
	obj* key_val2 = value(map_find(map, key2));
}