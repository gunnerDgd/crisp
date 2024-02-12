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
	mov dword[edi + cpu_rax], eax
	mov dword[edi + cpu_rbx], ebx
	mov dword[edi + cpu_rcx], ecx
	mov dword[edi + cpu_rdx], edx

	mov dword[edi + cpu_rsi], esi
	mov dword[edi + cpu_rdi], edi

	mov eax				    , dword[esp]
	mov dword[edi + cpu_rip], eax

	mov dword[edi + cpu_rbp], ebp
	mov dword[edi + cpu_rsp], esp
	add dword[edi + cpu_rsp], 0x04
	ret

cpu_do_set:
	mov eax, dword[edi + cpu_rax]
	mov ebx, dword[edi + cpu_rbx]
	mov ecx, dword[edi + cpu_rbx]
	mov edx, dword[edi + cpu_rdx]

	mov esi, dword[edi + cpu_esi]

	mov esp, dword[edi + cpu_rsp]
	mov ebp, dword[edi + cpu_rbp]

	push     dword[edi + cpu_rip]
	mov edi, dword[edi + cpu_rdi]
	ret


cpu_do_switch:
	mov dword[edi + cpu_rax], eax
	mov dword[edi + cpu_rbx], ebx
	mov dword[edi + cpu_rcx], ecx
	mov dword[edi + cpu_rdx], edx

	mov dword[edi + cpu_rsi], esi
	mov dword[edi + cpu_rdi], edi

	mov eax					, dword[rsp]
	mov dword[edi + cpu_rip], eax

	mov dword[edi + cpu_rbp], ebp
	mov dword[edi + cpu_rsp], esp
	add dword[edi + cpu_rsp], 0x04

	mov eax, dword[esi + cpu_rax]
	mov ebx, dword[esi + cpu_rbx]
	mov ecx, dword[esi + cpu_rcx]
	mov edx, dword[esi + cpu_rcx]

	mov edi, dword[esi + cpu_rdi]

	mov esp, dword[esi + cpu_rsp]
	mov ebp, dword[esi + cpu_rbp]

	push     dword[esi + cpu_rip]
	mov esi, dword[esi + cpu_rsi]
	ret