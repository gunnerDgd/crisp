#include <obj.h>
#include <sync/mpmc.h>

#include <stdio.h>
#include <stdlib.h>

#include <Windows.h>

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
bool_t test_clone(test* par    , test* par_clone)			   { return true_t; }
bool_t test_ref  (test* par)								   { return true_t; }
void   test_del  (test* par)								   {  }

obj_trait test_t		 = {
	.on_new	  = &test_new  ,
	.on_clone = &test_clone,
	.on_ref   = &test_ref  ,
	.on_del	  = &test_del  ,
	.size	  = sizeof(test)
};

void tx_thd(mpmc* par)				  {
	for (int i = 1 ; i <= 1000 ; ++i) {
		mpmc_enq(par, make(&test_t) from (1, i));
	}
}

u64_t rx_thd(mpmc* par)				  {
	u64_t ret = 0;
	for (int i = 1 ; i <= 1000 ; ++i) {
		test*  deq = mpmc_deq(par);
		ret += deq->value;
	}

	return ret;
}

int main()			  {
	set_mem(&cstd_mem);
	mpmc  *mpmc = make (mpmc_t) from (0);
	u64_t  sum  = 0						;
	HANDLE rx [8];
	HANDLE tx [8];
	u64_t  ret[8];

	for(int i = 0 ; i < 8 ; ++i)				      {
		rx[i] = CreateThread(0, 0, rx_thd, mpmc, 0, 0);
		tx[i] = CreateThread(0, 0, tx_thd, mpmc, 0, 0);
	}

	for(int i = 0 ; i < 8 ; ++i)			{
		WaitForSingleObject(rx[i], INFINITE);
		WaitForSingleObject(tx[i], INFINITE);
		GetExitCodeThread  (rx[i], &ret[i]) ;

		sum += ret[i];
	}

	printf("%d\n", sum);
}