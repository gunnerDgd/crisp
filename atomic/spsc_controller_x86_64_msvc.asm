
global __spsc_do_push
global __spsc_do_push_until_success

global __spsc_do_pop
global __spsc_do_pop_until_success

section .text

;crisp_bool (a.k.a char)
;	__spsc_do_push
;		(__spsc_head*, void*);

; RCX : __spsc_head*
; RDX : void*

__spsc_do_push:
    mov r8, qword[rcx + 0x10] ; __spsc_head::write (R8)
    mov r9, qword[r8]         ; __spsc_node::next  (R9)

    mov rax, qword[r8 + 0x08]      ; __spsc_node::entity (void*, RAX)
    cmpxchg  qword[r8 + 0x08], rdx ; cmpxchg to write.entity
    jnz      __do_push_failed

    mov      rax, 1
    cmpxchg  qword[rcx + 0x10], r9 ; Advance Write Pointer
    ret
__do_push_failed:
    mov rax, 0
    ret

;void
;	__spsc_do_push_until_success
;		(__spsc_head*, void*);

; RCX : __spsc_head*
; RDX : void*

__spsc_do_push_until_success:
    mov  r8, qword[rcx + 0x10] ; __spsc_head::write (R8)
    test r8, qword[rcx + 0x08] ; Compare if Write Pointer is same with Read Pointer.
    jz __spsc_do_push_until_success

    mov       r9 , qword[r8]             ; __spsc_node::next  (R9)
    mov       rax, qword[r8 + 0x08]      ; __spsc_node::entity (void*, RAX)
    cmpxchg        qword[r8 + 0x08], rdx ; cmpxchg to write.entity
    
    jnz __spsc_do_push_until_success
    cmpxchg  qword[rcx + 0x10], r9 ; Advance Write Pointer
    ret

;void* (a.k.a char)
;	__spsc_do_pop
;		(__spsc_head*);

__spsc_do_pop:
    mov r8, qword[rcx + 0x08] ; __spsc_head::read (R8)
    mov r9, qword[r8]         ; __spsc_node::next (R9)

    mov rax, qword[r8 + 0x08] ; __spsc_node::entity (void*, RAX)
    cmpxchg  qword[rcx + 0x08], r9

    jnz __do_pop_failed
    ret

__do_pop_failed:
    mov rax, 0
    ret

;void
;	__spsc_do_pop_until_success
;		(__spsc_head*, void*);

__spsc_do_pop_until_success:
    mov  r8, qword[rcx + 0x08] ; __spsc_head::read (R8)
    mov  r9, qword[r8]         ; __spsc_node::next (R9)
    test r9, qword[rcx + 0x10] ; Compare if Next of Read Pointer is same with Write Pointer.
    jz __spsc_do_pop_until_success

    mov rax, qword[r8 + 0x08] ; __spsc_node::entity (void*, RAX)
    cmpxchg  qword[rcx + 0x08], r9

    jnz __spsc_do_pop_until_success
    ret