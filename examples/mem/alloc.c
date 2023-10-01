#include <mem.h>
#include <details/mem.h>

#include <alloc.h>
#include <details/alloc.h>

#include <string.h>
#include <stdlib.h>

#include <stdio.h>

bool_t rd8 (__ptr* par_ptr, u8_t * par_rd) { *par_rd = *((u8_t *)(par_ptr->mem->ptr + par_ptr->mem_cur)); return true_t; }
bool_t rd16(__ptr* par_ptr, u16_t* par_rd) { *par_rd = *((u16_t*)(par_ptr->mem->ptr + par_ptr->mem_cur)); return true_t; }
bool_t rd32(__ptr* par_ptr, u32_t* par_rd) { *par_rd = *((u32_t*)(par_ptr->mem->ptr + par_ptr->mem_cur)); return true_t; }
bool_t rd64(__ptr* par_ptr, u64_t* par_rd) { *par_rd = *((u64_t*)(par_ptr->mem->ptr + par_ptr->mem_cur)); return true_t; }
u64_t  read(__ptr* par_ptr, void* par_rd, u64_t par_rd_len) { memcpy(par_rd, par_ptr->mem->ptr + par_ptr->mem_cur, par_rd_len); return par_rd_len; }

bool_t wr8  (__ptr* par_ptr, u8_t  par_wr) { *((u8_t *)(par_ptr->mem->ptr + par_ptr->mem_cur)) = par_wr; return true_t; }
bool_t wr16 (__ptr* par_ptr, u16_t par_wr) { *((u16_t*)(par_ptr->mem->ptr + par_ptr->mem_cur)) = par_wr; return true_t; }
bool_t wr32 (__ptr* par_ptr, u32_t par_wr) { *((u32_t*)(par_ptr->mem->ptr + par_ptr->mem_cur)) = par_wr; return true_t; }
bool_t wr64 (__ptr* par_ptr, u64_t par_wr) { *((u64_t*)(par_ptr->mem->ptr + par_ptr->mem_cur)) = par_wr; return true_t; }
u64_t  write(__ptr* par_ptr, void* par_wr, u64_t par_wr_len) { memcpy(par_ptr->mem->ptr + par_ptr->mem_cur, par_wr, par_wr_len); return par_wr_len; }

__mem_trait AllocMemTrait = {
	.rd8   = &rd8  ,
	.rd16  = &rd16 ,
	.rd32  = &rd32 ,
	.rd64  = &rd64 ,
	.read  = &read ,

	.wr8   = &wr8  ,
	.wr16  = &wr16 ,
	.wr32  = &wr32 ,
	.wr64  = &wr64 ,
	.write = &write
};

bool_t cstd_alloc_init		   (__alloc* par_alloc)							  { return true_t; }
bool_t cstd_alloc_init_as_clone(__alloc* par_alloc, __alloc* par_alloc_clone) { return true_t; }
void   cstd_alloc_deinit	   (__alloc* par_alloc)							  {  }

__mem* 
	cstd_alloc_mem_init
		(__alloc* par_alloc, u64_t par_size) {
			__mem* ret = malloc(par_size + sizeof(__mem));
			if (!ret) return 0;

			ret->ptr		= (u8_t*)ret + sizeof(__mem);
			ret->alloc		= par_alloc		;
			ret->alloc_size = par_size		;
			ret->trait		= &AllocMemTrait;

			return ret;
}
__mem* 
	cstd_alloc_mem_init_as_clone
		(__alloc* par_alloc, __mem* par_mem) {
			__mem* ret = cstd_alloc_mem_init(par_alloc, par_mem);
			if (!ret) return 0;
			
			memcpy(ret->ptr, par_mem->ptr, par_mem->alloc_size);
			return ret;
}
void
	cstd_alloc_mem_deinit
		(__alloc* par_alloc, __mem* par_mem) {
			if(par_mem->alloc == par_alloc)
				free(par_mem);
}

__alloc_trait AllocTrait							= {
	.init		       = &cstd_alloc_init			  ,
	.init_as_clone	   = &cstd_alloc_init_as_clone	  ,
	.deinit			   = &cstd_alloc_deinit			  ,
	.mem_init		   = &cstd_alloc_mem_init		  ,
	.mem_init_as_clone = &cstd_alloc_mem_init_as_clone,
	.mem_deinit		   = &cstd_alloc_mem_deinit
};

int main() {
	alloc		Alloc;
	alloc_init(&Alloc, &AllocTrait);

	mem Mem = mem_init(&Alloc, 8);
	ptr Ptr = mem_ptr(Mem);

	u64_t rdval;
	if (!ptr_wr64(Ptr, 1234))   return 1;
	if (!ptr_rd64(Ptr, &rdval)) return 2;

	printf("Result Value : %d\n", rdval);
}