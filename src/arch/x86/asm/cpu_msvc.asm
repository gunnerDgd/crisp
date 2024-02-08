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
	mov dword[ecx + cpu_rax], eax
	mov dword[ecx + cpu_rbx], ebx
	mov dword[ecx + cpu_rcx], ecx
	mov dword[ecx + cpu_rdx], edx

	mov dword[ecx + cpu_rsi], esi
	mov dword[ecx + cpu_rdi], edi

	mov eax				    , dword[esp]
	mov dword[ecx + cpu_rip], eax

	mov dword[ecx + cpu_rbp], ebp
	mov dword[ecx + cpu_rsp], esp
	add dword[ecx + cpu_rsp], 0x04
	ret

cpu_do_set:
	mov eax, dword[ecx + cpu_rax]
	mov ebx, dword[ecx + cpu_rbx]
	mov edx, dword[ecx + cpu_rdx]

	mov esi, dword[ecx + cpu_rsi]
	mov edi, dword[ecx + cpu_rdi]

	mov esp, dword[ecx + cpu_rsp]
	mov ebp, dword[ecx + cpu_rbp]

	push     dword[ecx + cpu_rip]
	mov ecx, dword[ecx + cpu_rcx]
	ret

cpu_do_switch:
	mov dword[ecx + cpu_rax], eax
	mov dword[ecx + cpu_rbx], ebx
	mov dword[ecx + cpu_rcx], ecx
	mov dword[ecx + cpu_rdx], edx

	mov dword[ecx + cpu_rsi], esi
	mov dword[ecx + cpu_rdi], edi

	mov eax				    , dword[esp]
	mov dword[ecx + cpu_rip], eax

	mov dword[ecx + cpu_rbp], ebp
	mov dword[ecx + cpu_rsp], esp
	add dword[ecx + cpu_rsp], 0x04

	mov eax, dword[edx + cpu_rax]
	mov ebx, dword[edx + cpu_rbx]
	mov ecx, dword[edx + cpu_rcx]

	mov esi, dword[edx + cpu_rsi]
	mov edi, dword[edx + cpu_rdi]

	mov esp, dword[edx + cpu_rsp]
	mov ebp, dword[edx + cpu_rbp]

	push     dword[edx + cpu_rip]
	mov edx, dword[edx + cpu_rdx]
	ret