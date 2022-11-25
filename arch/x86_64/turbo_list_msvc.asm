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
    mov r10, qword[rcx]        ; pHead->frontmost
    mov r11, qword[r10 + 0x08] ; pHead->frontmost->next

    mov qword[rdx]       , r10 ; pNode->prev = pHead->frontmost;
    mov qword[rdx + 0x08], r11 ; pNode->next = pHead->frontmost->next;
    
    mov qword[rdx + 0x18], rdx
    add qword[rdx + 0x18], 0x20 ; pNode->entity = (crisp_u8*)pNode + sizeof(__list_node);

    mov qword[r10 + 0x08], rdx  ; pHead->frontmost->next = pNode;
    mov qword[r11]       , rdx  ; pNode->next->prev	     = pNode;

    ret

; void
;   __turbo_list_push_back
;       (__list_head*, __list_node*)

; RCX : (__list_head*) pHead
; RDX : (__list_node*) pNode

__turbo_list_push_back:
    mov r10, qword[rcx + 0x08] ; pHead->backmost
    mov r11, qword[r10]        ; pHead->backmost->prev

    mov qword[rdx + 0x08], r10 ; pNode->next = pHead->backmost;
    mov qword[rdx]       , r11 ; pNode->prev = pHead->backmost->prev;
    
    mov qword[rdx + 0x18], rdx
    add qword[rdx + 0x18], 0x20 ; pNode->entity = (crisp_u8*)pNode + sizeof(__list_node);

    mov qword[r10]       , rdx  ; pHead->backmost->prev = pNode;
    mov qword[r11 + 0x08], rdx  ; pNode->prev->next	    = pNode;

    ret

; void
;   __turbo_list_push_at
;       (__list_head*, __list_node*, __list_node*)

; RCX : (__list_head*) pHead
; RDX : (__list_node*) pNode
; R8  : (__list_node*) pNodeAt

__turbo_list_push_at:
    mov r11, qword[r8 + 0x08]       ; pNodeAt->next
    mov      qword[rdx]       , r8  ; pNode  ->prev = pNodeAt;
    mov      qword[rdx + 0x08], r11 ; pNode  ->next = pNodeAt->next;
    mov      qword[r11]       , rdx ; pNodeAt->next->prev = pNode;

    mov qword[rdx + 0x18], rdx
    add qword[rdx + 0x18], 0x20 ; pNode->entity = (crisp_u8*)pNode + sizeof(__list_node);

    ret

; __list_node*
;   __turbo_list_pop_front
;       (__list_head*)

; RCX : (__list_head*) pHead

__turbo_list_pop_front:
    mov r11, qword[rcx]        ; pHead->frontmost
    mov r10, qword[r11 + 0x08] ; __list_node* node_popped = pHead->frontmost->next

    cmp r10, qword[rcx + 0x08]
    je  __pop_front_failed

    mov rdx, qword[r10 + 0x08]      ; node_popped->next
    mov      qword[r11 + 0x08], rdx ; pHead->frontmost->next = node_popped->next

    ret

__pop_front_failed:
    mov r10, 0
    ret

; __list_node*
;   __turbo_list_pop_back
;       (__list_head*)

; RCX : (__list_head*) pHead

__turbo_list_pop_back:
    mov r11, qword[rcx + 0x08] ; pHead->backmost
    mov r10, qword[r11]        ; __list_node* node_popped = pHead->backmost->prev

    cmp r10, qword[rcx]
    je  __pop_back_failed

    mov rdx, qword[r10]         ; node_popped->prev
    mov      qword[r11], rdx    ; pHead->backmost->prev = node_popped->prev;

    ret

__pop_back_failed:
    mov r10, 0
    ret


; void
;   __turbo_list_pop_at
;       (__list_head*, __list_node*)

; RCX : (__list_head*) pHead
; RDX : (__list_node*) pNode

__turbo_list_pop_at:
    mov r10, qword[rdx]        ; pNode->prev
    mov r11, qword[rdx + 0x08] ; pNode->next

    mov qword[r10 + 0x08], r11
    mov qword[r11]       , r10

    ret