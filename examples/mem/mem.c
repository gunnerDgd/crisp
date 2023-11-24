#include <mem.h>
#include <ptr.h>
#include <alloc.h>

#include <stdio.h>

int main() {
	mem mem = mem_new(NULL, 64);
	ptr ptr = mem_ptr(mem , 0) ;
	
	ptr = ptr_wr64(ptr, 1);
	ptr = ptr_wr64(ptr, 2);
	ptr = ptr_wr64(ptr, 3);
	ptr = ptr_wr64(ptr, 4);

	ptr = mem_ptr(mem, 0);
	for(int i = 0 ; i < 4 ; i++) {
		u64_t rdval;
		ptr = ptr_rd64(ptr, &rdval);
		printf("Written Value : %lld\n", rdval);
	}

	mem_del(mem);
}