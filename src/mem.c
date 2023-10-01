#include "mem.h"
#include "details/mem.h"

mem
    mem_init(alloc* par_alloc, u64_t par_alloc_size) {
        if (!par_alloc)      return 0;
        if (!par_alloc_size) return 0;

        __mem*  ret = __mem_init(par_alloc, par_alloc_size);
        if (!ret)
            return 0;
        if (!ret->trait) {
            __mem_deinit(par_alloc, ret);
            return 0;
        }

        return ret;
}

mem
    mem_init_as_clone(mem par_clone) {
        if (!par_clone) return 0;
        return __mem_init_as_clone(par_clone);
}

void
    mem_deinit(mem par_deinit) {
        __mem_deinit(par_deinit);
}

ptr
    mem_ptr(mem par_mem) {
        ptr ret  = {
            .ptr = { par_mem, 0 }
        };

        return ret;
}

void*
    mem_ptr_raw(mem par_ptr) {
        return ((__mem*)par_ptr)->ptr;
}

ptr
    ptr_move
        (ptr par_ptr, u64_t par_move)            {
            __ptr* ret_mem_ptr = &par_ptr        ;
            __mem* ret_mem     = ret_mem_ptr->mem;
            ptr    ret;

            if (!ret_mem) 
                goto ptr_move_failed;
            if ((par_move + ret_mem_ptr->mem_cur) > ret_mem->alloc_size)
                goto ptr_move_failed;

            ret.ptr[0] = ret_mem;
            ret.ptr[1] = ret_mem_ptr->mem_cur + par_move;

            return ret;
    ptr_move_failed:
            ret.ptr[0] = 0;
            ret.ptr[1] = 0;

            return     ret;
}

bool_t
    ptr_rd8
        (ptr par_ptr, u8_t* par_rd) {
            __ptr* ptr = &par_ptr;

            if (!ptr->mem)                                            return false_t;
            if ((ptr->mem_cur + sizeof(u8_t)) > ptr->mem->alloc_size) return false_t;

            return ptr->mem->trait->rd8(ptr, par_rd);
}

bool_t
    ptr_rd16
        (ptr par_ptr, u16_t* par_rd) {
            __ptr* ptr = &par_ptr;

            if (!ptr->mem)                                             return false_t;
            if ((ptr->mem_cur + sizeof(u16_t)) > ptr->mem->alloc_size) return false_t;

            return ptr->mem->trait->rd16(ptr, par_rd);
}

bool_t
    ptr_rd32
        (ptr par_ptr, u32_t* par_rd) {
            __ptr* ptr = &par_ptr;

            if (!ptr->mem)                                             return false_t;
            if ((ptr->mem_cur + sizeof(u32_t)) > ptr->mem->alloc_size) return false_t;

            return ptr->mem->trait->rd32(ptr, par_rd);
}

bool_t
    ptr_rd64
        (ptr par_ptr, u64_t* par_rd) {
            __ptr* ptr = &par_ptr;

            if (!ptr->mem)                                             return false_t;
            if ((ptr->mem_cur + sizeof(u64_t)) > ptr->mem->alloc_size) return false_t;

            return ptr->mem->trait->rd64(ptr, par_rd);
}

u64_t
    ptr_read
        (ptr par_ptr, void* par_rd, u64_t par_rd_len) {
            __ptr* ptr = &par_ptr;

            if (!ptr->mem)                                          return false_t;
            if ((ptr->mem_cur + par_rd_len) > ptr->mem->alloc_size) return false_t;

            return ptr->mem->trait->read(ptr, par_rd, par_rd_len);
}

bool_t
    ptr_wr8
        (ptr par_ptr, u8_t par_wr) {
            __ptr* ptr = &par_ptr;

            if (!ptr->mem)                                            return false_t;
            if ((ptr->mem_cur + sizeof(u8_t)) > ptr->mem->alloc_size) return false_t;

            return ptr->mem->trait->wr8(ptr, par_wr);
}

bool_t
    ptr_wr16
        (ptr par_ptr, u16_t par_wr) {
            __ptr* ptr = &par_ptr;

            if (!ptr->mem)                                             return false_t;
            if ((ptr->mem_cur + sizeof(u16_t)) > ptr->mem->alloc_size) return false_t;

            return ptr->mem->trait->wr16(ptr, par_wr);
}

bool_t
    ptr_wr32
        (ptr par_ptr, u32_t par_wr) {
            __ptr* ptr = &par_ptr;

            if (!ptr->mem)                                             return false_t;
            if ((ptr->mem_cur + sizeof(u32_t)) > ptr->mem->alloc_size) return false_t;

            return ptr->mem->trait->rd32(ptr, par_wr);
}

bool_t
    ptr_wr64
        (ptr par_ptr, u64_t par_wr) {
            __ptr* ptr = &par_ptr;

            if (!ptr->mem)                                             return false_t;
            if ((ptr->mem_cur + sizeof(u64_t)) > ptr->mem->alloc_size) return false_t;

            return ptr->mem->trait->wr64(ptr, par_wr);
}

u64_t
    ptr_write
        (ptr par_ptr, void* par_wr, u64_t par_wr_len) {
            __ptr* ptr = &par_ptr;

            if (!ptr->mem)                                          return false_t;
            if ((ptr->mem_cur + par_wr_len) > ptr->mem->alloc_size) return false_t;

            return ptr->mem->trait->write(ptr, par_wr, par_wr_len);
}