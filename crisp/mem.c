#include "mem.h"
#include "details/mem.h"

mem
    mem_init(alloc* par_alloc, u64_t par_alloc_size) {
        return __mem_init(par_alloc, par_alloc_size);
}

mem
    mem_init_as_clone(mem par_clone) {
        return __mem_init_as_clone(par_clone);
}

bool_t
    mem_deinit(mem par_deinit) {
        return __mem_deinit(par_deinit);
}

u64_t
    mem_copy_from(mem par_dst, void* par_src, u64_t par_src_size) {
		return __mem_copy_from(par_dst, par_src, par_src_size);
}

u64_t
    mem_copy_to(mem par_src, void* par_dst, u64_t par_dst_size) {
		return __mem_copy_to(par_src, par_dst, par_dst_size);
}

u64_t
    mem_move(mem par_dst, mem par_src) {
		return __mem_move(par_dst, par_src);
}

u64_t
    mem_size(mem par_mem) {
		return ((__mem*)par_mem)->alloc_size;
}

void*
    mem_ptr(mem par_mem) {
        return __mem_ptr(par_mem);
}