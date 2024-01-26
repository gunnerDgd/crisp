global cpu_do_switch
global cpu_do_get
global cpu_do_set

section .text

%define cpu_rax 0
%define cpu_rbx 0x08
%define cpu_rcx 0x10
%define cpu_rdx 0x18

%define cpu_rsi 0x20
%define cpu_rdi 0x28

%define cpu_rsp 0x30
%define cpu_rbp 0x38

%define cpu_rip 0x40

%define cpu_r8  0x48
%define cpu_r9  0x50
%define cpu_r10 0x58
%define cpu_r11 0x60
%define cpu_r12 0x68
%define cpu_r13 0x70
%define cpu_r14 0x78
%define cpu_r15 0x80

cpu_do_get:
	mov qword[rcx + cpu_rax], rax
	mov qword[rcx + cpu_rbx], rbx
	mov qword[rcx + cpu_rcx], rcx
	mov qword[rcx + cpu_rdx], rdx

	mov qword[rcx + cpu_rsi], rsi
	mov qword[rcx + cpu_rdi], rdi

	mov rax				    , qword[rsp]
	mov qword[rcx + cpu_rip], rax

	mov qword[rcx + cpu_rbp], rbp
	mov qword[rcx + cpu_rsp], rsp
	add qword[rcx + cpu_rsp], 0x08

	mov qword[rcx + cpu_r8] , r8
	mov qword[rcx + cpu_r9] , r9
	mov qword[rcx + cpu_r10], r10
	mov qword[rcx + cpu_r11], r11
	mov qword[rcx + cpu_r12], r12
	mov qword[rcx + cpu_r13], r13
	mov qword[rcx + cpu_r14], r14
	mov qword[rcx + cpu_r15], r15
	ret

cpu_do_set:
	mov rax, qword[rcx + cpu_rax]
	mov rbx, qword[rcx + cpu_rbx]
	mov rdx, qword[rcx + cpu_rdx]

	mov rsi, qword[rcx + cpu_rsi]
	mov rdi, qword[rcx + cpu_rdi]

	mov rsp, qword[rcx + cpu_rsp]
	mov rbp, qword[rcx + cpu_rbp]

	mov r8 , qword[rcx + cpu_r8]
	mov r9 , qword[rcx + cpu_r9]
	mov r10, qword[rcx + cpu_r10]
	mov r11, qword[rcx + cpu_r11]
	mov r12, qword[rcx + cpu_r12]
	mov r13, qword[rcx + cpu_r13]
	mov r14, qword[rcx + cpu_r14]
	mov r15, qword[rcx + cpu_r15]

	push     qword[rcx + cpu_rip]
	mov rcx, qword[rcx + cpu_rcx]
	ret

cpu_do_switch:
	mov qword[rcx + cpu_rax], rax
	mov qword[rcx + cpu_rbx], rbx
	mov qword[rcx + cpu_rcx], rcx
	mov qword[rcx + cpu_rdx], rdx

	mov qword[rcx + cpu_rsi], rsi
	mov qword[rcx + cpu_rdi], rdi

	mov rax				    , qword[rsp]
	mov qword[rcx + cpu_rip], rax

	mov qword[rcx + cpu_rbp], rbp
	mov qword[rcx + cpu_rsp], rsp
	add qword[rcx + cpu_rsp], 0x08

	mov qword[rcx + cpu_r8] , r8
	mov qword[rcx + cpu_r9] , r9
	mov qword[rcx + cpu_r10], r10
	mov qword[rcx + cpu_r11], r11
	mov qword[rcx + cpu_r12], r12
	mov qword[rcx + cpu_r13], r13
	mov qword[rcx + cpu_r14], r14
	mov qword[rcx + cpu_r15], r15

	mov rax, qword[rdx + cpu_rax]
	mov rbx, qword[rdx + cpu_rbx]
	mov rcx, qword[rdx + cpu_rcx]

	mov rsi, qword[rdx + cpu_rsi]
	mov rdi, qword[rdx + cpu_rdi]

	mov rsp, qword[rdx + cpu_rsp]
	mov rbp, qword[rdx + cpu_rbp]

	mov r8 , qword[rdx + cpu_r8]
	mov r9 , qword[rdx + cpu_r9]
	mov r10, qword[rdx + cpu_r10]
	mov r11, qword[rdx + cpu_r11]
	mov r12, qword[rdx + cpu_r12]
	mov r13, qword[rdx + cpu_r13]
	mov r14, qword[rdx + cpu_r14]
	mov r15, qword[rdx + cpu_r15]

	push     qword[rdx + cpu_rip]
	mov rdx, qword[rdx + cpu_rdx]
	ret