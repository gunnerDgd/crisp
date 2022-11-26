
global __spsc_push
global __spsc_push_until_success

global __spsc_pop
global __spsc_pop_until_success

section .text

;crisp_bool (a.k.a char)
;	__spsc_push
;		(__spsc_head*, void*);

; RCX : (__spsc_head*) pHead
; RDX : (void*) pEntity

__spsc_push:
    mov rax, qword[rcx + 0x08] ; pHead->push_ptr       (RAX)
    mov r9 , qword[rax]        ; pHead->push_ptr->next (R9)

    cmp rax, qword[rcx + 0x10] ; Compare if Write Pointer is same with Read Pointer.
    je  __push_failed

    mov     qword[rax + 0x10], rdx
    cmpxchg qword[rcx + 0x08], r9

    mov rax, 1 ; Set Return Value as True
    ret

__push_failed:
    mov rax, 0
    ret

;void
;	__spsc_push_until_success
;		(__spsc_head*, void*);

; RCX : (__spsc_head*) pHead
; RDX : (void*) pEntity

__spsc_push_until_success:
    mov rax, qword[rcx + 0x08]    ; pHead->push_ptr       (RAX)
    mov r9 , qword[rax]           ; pHead->push_ptr->next (R9)

    cmp rax, qword[rcx + 0x10]    ; Compare if Write Pointer is same with pop_ptr.
    je __spsc_push_until_success

    mov      qword[rax + 0x10], rdx
    cmpxchg  qword[rcx + 0x08], r9

    ret

;void* (a.k.a char)
;	__spsc_pop
;		(__spsc_head*);

; RCX : (__spsc_head*)pHead

__spsc_pop:
    mov rax, qword[rcx + 0x10]     ; pHead->pop_ptr       (RAX)
    mov r9 , qword[rax]            ; pHead->pop_ptr->next (R9)

    cmp r9, qword[rcx + 0x08]      ; Compare if Next of Read Pointer is same with Write Pointer.
    je  __pop_failed

    cmpxchg  qword[rcx + 0x10], r9 ; pHead->pop_ptr = pHead->pop_ptr_next (advance)
    mov rax, qword[r9  + 0x10]     ; pHead->pop_ptr->next->entity (RAX)
    ret

__pop_failed:
    mov rax, 0
    ret

;void*
;	__spsc_pop_until_success
;		(__spsc_head*);

; RCX : (__spsc_head*) pHead

__spsc_pop_until_success:
    mov rax, qword[rcx + 0x10] ; pHead->pop_ptr      (RAX)
    mov r9 , qword[rax]        ; pHead->pop_ptr->next (R9)

    cmp r9, qword[rcx + 0x08]  ; Compare if Next of Read Pointer is same with Write Pointer.
    je  __spsc_pop_until_success

    cmpxchg  qword[rcx + 0x10], r9 ; pHead->pop_ptr = pHead->pop_ptr_next (advance)
    mov rax, qword[r9  + 0x10]     ; pHead->pop_ptr->next->entity (RAX)

    ret