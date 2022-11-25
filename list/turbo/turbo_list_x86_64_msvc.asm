global __turbo_list_push_front
global __turbo_list_push_back
global __turbo_list_push_at

global __turbo_list_pop_front
global __turbo_list_pop_back
global __turbo_list_pop_at

section .text

; void
;   __turbo_list_push_front
;       (__list_head*, __list_node*)

; RCX : (__list_head*) pHead
; RDX : (__list_node*) pNode

__turbo_list_push_front:
    mov rbx, qword[rcx]              ; pHead->frontmost
    
    mov      qword[rdx + 0x08], rbx  ; pNode->next = pHead->frontmost
    mov      qword[rdx]       , 0x00 ; pNode->prev = 0
    mov      qword[rcx]       , rdx  ; pHead->frontmost = pNode;

    test rbx, rbx
    jne  __turbo_list_set_old_frontmost ; if(pHead->frontmost)
    mov  qword[rcx + 0x08], rdx         ; if(pHead->frontmost)
                                        ;   pHead->backmost = pNode;
    ret

__turbo_list_set_old_frontmost:
    mov      qword[rbx], rdx ; pHead->frontmost->prev = pNode
    ret

; void
;   __turbo_list_push_back
;       (__list_head*, __list_node*)

; RCX : (__list_head*) pHead
; RDX : (__list_node*) pNode

__turbo_list_push_back:
    mov rbx, qword[rcx + 0x08]      ; pHead->backmost
    
    mov      qword[rdx]       , rbx  ; pNode->prev = pHead->backmost
    mov      qword[rdx + 0x08], 0x00 ; pNode->next = 0
    mov      qword[rcx + 0x08], rdx  ; pHead->backmost = pNode

    test rbx, rbx
    jne  __turbo_list_set_old_backmost ; if(pHead->backmost)
    mov  qword[rcx], rdx               ; if(!pHead->backmost)
                                       ;    pHead->frontmost = pNode;
    ret

__turbo_list_set_old_backmost:
    mov qword[rbx + 0x08], rdx ; pHead->backmost->next = pNode
    ret

; void
;   __turbo_list_push_at
;       (__list_head*, __list_node*, __list_node*)

; RCX : (__list_head*) pHead
; RDX : (__list_node*) pNode
; R8  : (__list_node*) pNodeAt

__turbo_list_push_at:
    mov  rbx, qword[rbx]
    test rbx, rbx
    je   __turbo_list_push_front

    mov  rbx, qword[rbx + 0x08]
    test rbx, rbx
    je   __turbo_list_push_back

    mov  r9, qword[r8  + 0x08]      ; pNodeAt->next
    mov      qword[r8  + 0x08], rdx ; pNodeAt->next       = pNode
    mov      qword[rdx]       , r8  ; pNode  ->prev       = pNodeAt
    mov      qword[rdx + 0x08], r9  ; pNode  ->next       = pNodeAt->next
    mov      qword[r9]        , rdx ; pNodeAt->next->prev = pNode

    ret

; __list_node*
;   __turbo_list_pop_front
;       (__list_head*)

; RCX : (__list_head*) pHead

__turbo_list_pop_front:
    mov  rax, qword[rcx] ; (Return) = pHead->frontmost
    test rax, rax
    
    je   __pop_front_empty
    mov  rbx, qword[rax + 0x08] ; pHead->frontmost->next
    mov       qword[rcx], rbx   ; pHead->frontmost = pHead->frontmost->next
    
    test rbx, rbx
    je   __pop_front_last
    ret
__pop_front_empty:
    ret
__pop_front_last:
    mov qword[rcx + 0x08], 0x00 ; pHead->backmost = nullptr;
    ret

; __list_node*
;   __turbo_list_pop_back
;       (__list_head*)

; RCX : (__list_head*) pHead

__turbo_list_pop_back:
    mov  rax, qword[rcx + 0x08] ; (Return) = pHead->backmost
    test rax, rax               ; if(!pHead->backmost)
    
    je   __pop_back_empty
    mov  rbx, qword[rax]             ; pHead->backmost->prev
    mov       qword[rcx + 0x08], rbx ; pHead->backmost = pHead->backmost->prev
    
    test rbx, rbx
    je   __pop_back_last
    ret
__pop_back_empty:
    ret ; return;
__pop_back_last:
    mov qword[rcx], 0x00 ; pHead->frontmost = nullptr;
    ret

; void
;   __turbo_list_pop_at
;       (__list_head*, __list_node*)

; RCX : (__list_head*) pHead
; RDX : (__list_node*) pNodeAt

__turbo_list_pop_at:
    mov  rax, qword[rdx]
    test rax, rax
    je   __turbo_list_pop_front
    
    mov  rax, qword[rdx + 0x08]
    test rax, rax
    je   __turbo_list_pop_back

    mov  r8, qword[rdx]        ; pNodeAt->prev
    mov  r9, qword[rdx + 0x08] ; pNodeAt->next

    mov  qword[r8 + 0x08], r9
    mov  qword[r9]       , r8

    ret