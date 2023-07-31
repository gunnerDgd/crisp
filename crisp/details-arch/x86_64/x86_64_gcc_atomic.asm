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
    lock add byte[rdi], sil
    mov  al, byte[rdi]

atomic_add_i16:
    lock add word[rdi], si
    mov  ax, word[rdi]

atomic_add_i32:
    lock add dword[rdi], esi
    mov eax, dword[rdi]

atomic_add_i64:
    lock add qword[rdi], rsi
    mov rax, qword[rdi]

atomic_add_u8:
    lock add byte[rdi], sil
    mov  al, byte[rdi]

atomic_add_u16:
    lock add word[rdi], si
    mov  ax, word[rdi]

atomic_add_u32:
    lock add dword[rdi], esi
    mov eax, dword[rdi]

atomic_add_u64:
    lock add qword[rdi], rax
    mov rax, qword[rdi]

atomic_sub_i8:
    lock sub byte[rdi], sil
    mov  al, byte[rdi]

atomic_sub_i16:
    lock sub word[rdi], si
    mov  ax, word[rdi]

atomic_sub_i32:
    lock sub dword[rdi], esi
    mov eax, dword[rdi]

atomic_sub_i64:
    lock sub qword[rdi], rsi
    mov rax, qword[rdi]

atomic_sub_u8:
    lock sub byte[rdi], sil
    mov  al, byte[rdi]

atomic_sub_u16:
    lock sub word[rdi], si
    mov  ax, word[rdi]

atomic_sub_u32:
    lock sub dword[rdi], esi
    mov eax, dword[rdi]

atomic_sub_u64:
    lock sub qword[rdi], rsi
    mov rax, qword[rdi]


atomic_inc_i8:
    lock inc byte[rdi]
    mov  al, byte[rdi]

atomic_inc_i16:
    lock inc word[rdi]
    mov  ax, word[rdi]

atomic_inc_i32:
    lock inc dword[rdi]
    mov eax, dword[rdi]

atomic_inc_i64:
    lock inc qword[rdi]
    mov rax, qword[rdi]

atomic_inc_u8:
    lock inc byte[rdi],
    mov  al, byte[rdi]

atomic_inc_u16:
    lock inc word[rdi]
    mov  ax, word[rdi]

atomic_inc_u32:
    lock inc dword[rdi]
    mov eax, dword[rdi]

atomic_inc_u64:
    lock inc qword[rdi]
    mov rax, qword[rdi]


atomic_dec_i8:
    lock dec byte[rdi]
    mov  al, byte[rdi]

atomic_dec_i16:
    lock dec word[rdi]
    mov  ax, word[rdi]

atomic_dec_i32:
    lock dec dword[rdi]
    mov eax, dword[rdi]

atomic_dec_i64:
    lock dec qword[rdi]
    mov rax, qword[rdi]

atomic_dec_u8:
    lock dec byte[rdi]
    mov  al, byte[rdi]

atomic_dec_u16:
    lock dec word[rdi]
    mov  ax, word[rdi]

atomic_dec_u32:
    lock dec dword[rdi]
    mov eax, dword[rdi]

atomic_dec_u64:
    lock dec qword[rdi]
    mov rax, qword[rdi]

atomic_cmpxchg_i8:  lock cmpxchg byte [rdi], sil
atomic_cmpxchg_i16: lock cmpxchg word [rdi], si
atomic_cmpxchg_i32: lock cmpxchg dword[rdi], esi
atomic_cmpxchg_i64: lock cmpxchg qword[rdi], rsi

atomic_cmpxchg_u8:  lock cmpxchg byte [rdi], sil
atomic_cmpxchg_u16: lock cmpxchg word [rdi], si
atomic_cmpxchg_u32: lock cmpxchg dword[rdi], esi
atomic_cmpxchg_u64: lock cmpxchg qword[rdi], rsi