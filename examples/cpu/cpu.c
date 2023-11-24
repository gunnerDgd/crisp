#include <cpu.h>
#include <stdio.h>

void test(cpu* par, cpu* par_main) {
    printf("Hello World\n");
    cpu_switch(par, par_main);
}

int main() {
    mem   stack     = mem_new(0, 1024 * 8);
    u64_t stack_ptr = (u64_t)mem_ptr_raw(stack) + 1024 * 8 - 16;

    cpu *cpu_main = make(cpu_t) from(0)       ,
        *cpu      = make(cpu_t) from(1, stack);

    cpu_reg_write(cpu, cpu_rcx, cpu)      ;
    cpu_reg_write(cpu, cpu_rdx, cpu_main) ;
    cpu_reg_write(cpu, cpu_rip, &test)    ;
    cpu_reg_write(cpu, cpu_rsp, stack_ptr);
    cpu_reg_write(cpu, cpu_rbp, stack_ptr);

    cpu_switch(cpu_main, cpu);
}