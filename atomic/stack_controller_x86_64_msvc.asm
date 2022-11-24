global __atomic_stack_push
global __atomic_stack_pop

section .text
;void
;	__atomic_stack_push
;		(__atomic_dynamic_stack_head*,
;        __atomic_dynamic_stack_node*);
;
; RCX : __atomic_dynamic_stack_head*
; RDX : __atomic_dynamic_stack_node*

__atomic_stack_push:
    mov rax, qword[rcx]
__do_stack_push:
    mov     qword[rdx], rax
    cmpxchg qword[rcx], rdx

    jnz __do_stack_push
    ret

;__atomic_dynamic_stack_node*
;	__atomic_stack_pop
;		(__atomic_dynamic_stack_head*);
;
; RCX : __atomic_dynamic_stack_node*

__atomic_stack_pop:
    mov rax, qword[rcx]
__do_stack_pop:
    mov rbx, qword[rax] ; next pointer
    cmpxchg  qword[rcx], rbx
    jnz __do_stack_pop

    ret