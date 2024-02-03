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
	mov qword[rdi + cpu_rax], rax
	mov qword[rdi + cpu_rbx], rbx
	mov qword[rdi + cpu_rcx], rcx
	mov qword[rdi + cpu_rdx], rdx

	mov qword[rdi + cpu_rsi], rsi
	mov qword[rdi + cpu_rdi], rdi

	mov rax				    , qword[rsp]
	mov qword[rdi + cpu_rip], rax

	mov qword[rdi + cpu_rbp], rbp
	mov qword[rdi + cpu_rsp], rsp
	add qword[rdi + cpu_rsp], 0x08

	mov qword[rdi + cpu_r8] , r8
	mov qword[rdi + cpu_r9] , r9
	mov qword[rdi + cpu_r10], r10
	mov qword[rdi + cpu_r11], r11
	mov qword[rdi + cpu_r12], r12
	mov qword[rdi + cpu_r13], r13
	mov qword[rdi + cpu_r14], r14
	mov qword[rdi + cpu_r15], r15
	ret

cpu_do_set:
	mov rax, qword[rdi + cpu_rax]
	mov rbx, qword[rdi + cpu_rbx]
	mov rcx, qword[rdi + cpu_rbx]
	mov rdx, qword[rdi + cpu_rdx]

	mov rsi, qword[rdi + cpu_rsi]

	mov rsp, qword[rdi + cpu_rsp]
	mov rbp, qword[rdi + cpu_rbp]

	mov r8 , qword[rdi + cpu_r8]
	mov r9 , qword[rdi + cpu_r9]
	mov r10, qword[rdi + cpu_r10]
	mov r11, qword[rdi + cpu_r11]
	mov r12, qword[rdi + cpu_r12]
	mov r13, qword[rdi + cpu_r13]
	mov r14, qword[rdi + cpu_r14]
	mov r15, qword[rdi + cpu_r15]

	push     qword[rdi + cpu_rip]
	mov rdi, qword[rdi + cpu_rdi]
	ret


cpu_do_switch:
	mov qword[rdi + cpu_rax], rax
	mov qword[rdi + cpu_rbx], rbx
	mov qword[rdi + cpu_rcx], rcx
	mov qword[rdi + cpu_rdx], rdx

	mov qword[rdi + cpu_rsi], rsi
	mov qword[rdi + cpu_rdi], rdi

	mov rax					  , qword[rsp]
	mov qword[rdi + cpu_rip], rax

	mov qword[rdi + cpu_rbp], rbp
	mov qword[rdi + cpu_rsp], rsp
	add qword[rdi + cpu_rsp], 0x08

	mov qword[rdi + cpu_r8] , r8
	mov qword[rdi + cpu_r9] , r9
	mov qword[rdi + cpu_r10], r10
	mov qword[rdi + cpu_r11], r11
	mov qword[rdi + cpu_r12], r12
	mov qword[rdi + cpu_r13], r13
	mov qword[rdi + cpu_r14], r14
	mov qword[rdi + cpu_r15], r15

	mov rax, qword[rsi + cpu_rax]
	mov rbx, qword[rsi + cpu_rbx]
	mov rcx, qword[rsi + cpu_rcx]
	mov rdx, qword[rsi + cpu_rcx]

	mov rdi, qword[rsi + cpu_rdi]

	mov rsp, qword[rsi + cpu_rsp]
	mov rbp, qword[rsi + cpu_rbp]

	mov r8 , qword[rsi + cpu_r8]
	mov r9 , qword[rsi + cpu_r9]
	mov r10, qword[rsi + cpu_r10]
	mov r11, qword[rsi + cpu_r11]
	mov r12, qword[rsi + cpu_r12]
	mov r13, qword[rsi + cpu_r13]
	mov r14, qword[rsi + cpu_r14]
	mov r15, qword[rsi + cpu_r15]

	push     qword[rsi + cpu_rip]
	mov rsi, qword[rsi + cpu_rsi]
	ret