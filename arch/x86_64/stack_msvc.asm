global __atomic_stack_push
global __atomic_stack_pop

section .text
;void
;	__atomic_stack_push
;		(__atomic_stack_head*,
;        __atomic_stack_node*);
;
; RCX : (__atomic_stack_head*) pHead
; RDX : (__atomic_stack_node*) pNode

__atomic_stack_push:
    mov rax,      qword[rcx]      ; pHead->node
    mov           qword[rdx], rax ; pNode->next = pHead->node;
    lock cmpxchg  qword[rcx], rdx
    jnz           __atomic_stack_push
    ret

;__atomic_dynamic_stack_node*
;	__atomic_stack_pop
;		(__atomic_stack_head*);
;
; RCX : (__atomic_stack_head*)pHead

__atomic_stack_pop:
    mov  rax, qword[rcx]         ; pHead->node
    test rax, rax                ; if(!pHead->node)
    je        __atomic_stack_pop ;      goto __atomic_stack_pop;

    mov     r10, qword[rax]          ; pHead->node->next
    lock cmpxchg qword[rcx], r10
    jnz          __atomic_stack_pop

    ret