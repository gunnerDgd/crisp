#include <mem.h>
#include <ptr.h>
#include <alloc.h>

#include <stdio.h>

int main() {
	mem mem = mem_init(NULL, 64);
	ptr ptr = mem_ptr (mem, 0);
	
	ptr_wr64(ptr, 1);
	ptr_wr64(ptr_seek(ptr, 8) , 2);
	ptr_wr64(ptr_seek(ptr, 16), 3);
	ptr_wr64(ptr_seek(ptr, 24), 4);

	ptr = mem_ptr(mem, 0);
	for(int i = 0 ; i < 4 ; i++) {
		u64_t rdval;
		ptr_rd64(ptr_seek(ptr, 8 * i), &rdval);
		printf("Written Value : %d\n", rdval);
	}
}