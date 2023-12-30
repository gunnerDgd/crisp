global __cpu_switch

section .text

%define __cpu_rax 0
%define __cpu_rbx 0x08
%define __cpu_rcx 0x10
%define __cpu_rdx 0x18

%define __cpu_rsi 0x20
%define __cpu_rdi 0x28

%define __cpu_rsp 0x30
%define __cpu_rbp 0x38

%define __cpu_rip 0x40

%define __cpu_r8  0x48
%define __cpu_r9  0x50
%define __cpu_r10 0x58
%define __cpu_r11 0x60
%define __cpu_r12 0x68
%define __cpu_r13 0x70
%define __cpu_r14 0x78
%define __cpu_r15 0x80


__cpu_switch:
	mov qword[rdi + __cpu_rax], rax
	mov qword[rdi + __cpu_rbx], rbx
	mov qword[rdi + __cpu_rcx], rcx
	mov qword[rdi + __cpu_rdx], rdx

	mov qword[rdi + __cpu_rsi], rsi
	mov qword[rdi + __cpu_rdi], rdi

	mov rax					  , qword[rsp]
	mov qword[rdi + __cpu_rip], rax

	mov qword[rdi + __cpu_rbp], rbp
	mov qword[rdi + __cpu_rsp], rsp
	add qword[rdi + __cpu_rsp], 0x08

	mov qword[rdi + __cpu_r8] , r8
	mov qword[rdi + __cpu_r9] , r9
	mov qword[rdi + __cpu_r10], r10
	mov qword[rdi + __cpu_r11], r11
	mov qword[rdi + __cpu_r12], r12
	mov qword[rdi + __cpu_r13], r13
	mov qword[rdi + __cpu_r14], r14
	mov qword[rdi + __cpu_r15], r15

	mov rax, qword[rsi + __cpu_rax]
	mov rbx, qword[rsi + __cpu_rbx]
	mov rcx, qword[rsi + __cpu_rcx]
	mov rdx, qword[rsi + __cpu_rcx]

	mov rdi, qword[rsi + __cpu_rdi]

	mov rsp, qword[rsi + __cpu_rsp]
	mov rbp, qword[rsi + __cpu_rbp]

	mov r8 , qword[rsi + __cpu_r8]
	mov r9 , qword[rsi + __cpu_r9]
	mov r10, qword[rsi + __cpu_r10]
	mov r11, qword[rsi + __cpu_r11]
	mov r12, qword[rsi + __cpu_r12]
	mov r13, qword[rsi + __cpu_r13]
	mov r14, qword[rsi + __cpu_r14]
	mov r15, qword[rsi + __cpu_r15]

	push     qword[rsi + __cpu_rip]
	mov rsi, qword[rsi + __cpu_rsi]
	ret