global atomic_add_i8
global atomic_add_i16
global atomic_add_i32
global atomic_add_i64

global atomic_add_u8
global atomic_add_u16
global atomic_add_u32
global atomic_add_u64

global atomic_sub_i8
global atomic_sub_i16
global atomic_sub_i32
global atomic_sub_i64

global atomic_sub_u8
global atomic_sub_u16
global atomic_sub_u32
global atomic_sub_u64

global atomic_mul_i8
global atomic_mul_i16
global atomic_mul_i32
global atomic_mul_i64

global atomic_mul_u8
global atomic_mul_u16
global atomic_mul_u32
global atomic_mul_u64

global atomic_cmpxchg_i8
global atomic_cmpxchg_i16
global atomic_cmpxchg_i32
global atomic_cmpxchg_i64

global atomic_cmpxchg_u8
global atomic_cmpxchg_u16
global atomic_cmpxchg_u32
global atomic_cmpxchg_u64

global atomic_inc_i8
global atomic_inc_i16
global atomic_inc_i32
global atomic_inc_i64

global atomic_inc_u8
global atomic_inc_u16
global atomic_inc_u32
global atomic_inc_u64

global atomic_dec_i8
global atomic_dec_i16
global atomic_dec_i32
global atomic_dec_i64

global atomic_dec_u8
global atomic_dec_u16
global atomic_dec_u32
global atomic_dec_u64

section .text

atomic_add_i8:
    lock add byte[rcx], dl
    mov  al, byte[rcx]

atomic_add_i16:
    lock add word[rcx], dx
    mov  ax, word[rcx]

atomic_add_i32:
    lock add dword[rcx], edx
    mov eax, dword[rcx]

atomic_add_i64:
    lock add qword[rcx], rdx
    mov rax, qword[rcx]

atomic_add_u8:
    lock add byte[rcx], dl
    mov  al, byte[rcx]

atomic_add_u16:
    lock add word[rcx], dx
    mov  ax, word[rcx]

atomic_add_u32:
    lock add dword[rcx], edx
    mov eax, dword[rcx]

atomic_add_u64:
    lock add qword[rcx], rdx
    mov rax, qword[rcx]

atomic_sub_i8:
    lock sub byte[rcx], dl
    mov  al, byte[rcx]

atomic_sub_i16:
    lock sub word[rcx], dx
    mov  ax, word[rcx]

atomic_sub_i32:
    lock sub dword[rcx], edx
    mov eax, dword[rcx]

atomic_sub_i64:
    lock sub qword[rcx], rdx
    mov rax, qword[rcx]

atomic_sub_u8:
    lock sub byte[rcx], dl
    mov  al, byte[rcx]

atomic_sub_u16:
    lock sub word[rcx], dx
    mov  ax, word[rcx]

atomic_sub_u32:
    lock sub dword[rcx], edx
    mov eax, dword[rcx]

atomic_sub_u64:
    lock sub qword[rcx], rdx
    mov rax, qword[rcx]


atomic_inc_i8:
    lock inc byte[rcx]
    mov  al, byte[rcx]

atomic_inc_i16:
    lock inc word[rcx]
    mov  ax, word[rcx]

atomic_inc_i32:
    lock inc dword[rcx]
    mov eax, dword[rcx]

atomic_inc_i64:
    lock inc qword[rcx]
    mov rax, qword[rcx]

atomic_inc_u8:
    lock inc byte[rcx],
    mov  al, byte[rcx]

atomic_inc_u16:
    lock inc word[rcx]
    mov  ax, word[rcx]

atomic_inc_u32:
    lock inc dword[rcx]
    mov eax, dword[rcx]

atomic_inc_u64:
    lock inc qword[rcx]
    mov rax, qword[rcx]


atomic_dec_i8:
    lock dec byte[rcx]
    mov  al, byte[rcx]

atomic_dec_i16:
    lock dec word[rcx]
    mov  ax, word[rcx]

atomic_dec_i32:
    lock dec dword[rcx]
    mov eax, dword[rcx]

atomic_dec_i64:
    lock dec qword[rcx]
    mov rax, qword[rcx]

atomic_dec_u8:
    lock dec byte[rcx]
    mov  al, byte[rcx]

atomic_dec_u16:
    lock dec word[rcx]
    mov  ax, word[rcx]

atomic_dec_u32:
    lock dec dword[rcx]
    mov eax, dword[rcx]

atomic_dec_u64:
    lock dec qword[rcx]
    mov rax, qword[rcx]

atomic_cmpxchg_i8:  lock cmpxchg byte [rcx], dl
atomic_cmpxchg_i16: lock cmpxchg word [rcx], dx
atomic_cmpxchg_i32: lock cmpxchg dword[rcx], edx
atomic_cmpxchg_i64: lock cmpxchg qword[rcx], rdx

atomic_cmpxchg_u8:  lock cmpxchg byte [rcx], dl
atomic_cmpxchg_u16: lock cmpxchg word [rcx], dx
atomic_cmpxchg_u32: lock cmpxchg dword[rcx], edx
atomic_cmpxchg_u64: lock cmpxchg qword[rcx], rdx