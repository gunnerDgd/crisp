#include <cpu.h>
#include <mem.h>

#include <stdio.h>
#include <stdlib.h>

bool_t cstd_mem_res_new() { return true_t; }
void   cstd_mem_res_del() { return true_t; }

void*  cstd_mem_new(mem_res* par, u64_t par_size) { return malloc(par_size); }
void   cstd_mem_del(mem_res* par, void* par_del)  { free(par_del); }

mem_res cstd_mem_res             = {
	.on_new     = &cstd_mem_res_new,
	.on_del     = &cstd_mem_res_del,

	.on_mem_new = &cstd_mem_new,
	.on_mem_del = &cstd_mem_del
};

void test(cpu* par, cpu* par_main) {
    printf("Hello\n");
    cpu_switch(par, par_main);
    printf("World\n");
    cpu_switch(par, par_main);
}

int main() {
    mem_res_new(&cstd_mem_res, 0);
    set_mem_res(&cstd_mem_res);

    void* stack     = mem_new(0, 1024 * 8);
    u64_t stack_ptr = (u64_t)stack + 1024 * 8 - 16;

    cpu *cpu_main = make(cpu_t) from(0)       ,
        *cpu      = make(cpu_t) from(1, stack);

    cpu_reg_write(cpu, cpu_rcx, cpu)      ;
    cpu_reg_write(cpu, cpu_rdx, cpu_main) ;
    cpu_reg_write(cpu, cpu_rip, &test)    ;
    cpu_reg_write(cpu, cpu_rsp, stack_ptr);
    cpu_reg_write(cpu, cpu_rbp, stack_ptr);
    cpu_switch   (cpu_main, cpu);
    cpu_switch   (cpu_main, cpu);
}