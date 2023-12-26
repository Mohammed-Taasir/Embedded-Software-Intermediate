	.file	"main.c"
	.text
	.globl	buffer
	.bss
	.align 8
	.type	buffer, @object
	.size	buffer, 10
buffer:
	.zero	10
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$10, %esi
	leaq	buffer(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	clear_all@PLT
	leaq	8+buffer(%rip), %rax
	movl	$2, %edx
	movl	$43, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	set_all@PLT
	movl	$97, %edx
	movl	$0, %esi
	leaq	buffer(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	set_value@PLT
	movl	$9, %esi
	leaq	buffer(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	get_value@PLT
	movb	%al, -5(%rbp)
	movsbl	-5(%rbp), %eax
	addl	$39, %eax
	movl	%eax, %edx
	movl	$9, %esi
	leaq	buffer(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	set_value@PLT
	movl	$55, %edx
	movl	$3, %esi
	leaq	buffer(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	set_value@PLT
	movl	$88, %edx
	movl	$1, %esi
	leaq	buffer(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	set_value@PLT
	movl	$50, %edx
	movl	$4, %esi
	leaq	buffer(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	set_value@PLT
	movl	$1, %esi
	leaq	buffer(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	get_value@PLT
	movb	%al, -5(%rbp)
	movl	$121, %edx
	movl	$2, %esi
	leaq	buffer(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	set_value@PLT
	movsbl	-5(%rbp), %eax
	subl	$12, %eax
	movl	%eax, %edx
	movl	$7, %esi
	leaq	buffer(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	set_value@PLT
	movl	$95, %edx
	movl	$5, %esi
	leaq	buffer(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	set_value@PLT
	movl	$0, -4(%rbp)
	jmp	.L2
.L3:
	movl	-4(%rbp), %eax
	leaq	buffer(%rip), %rdx
	movzbl	(%rax,%rdx), %eax
	movsbl	%al, %eax
	movl	%eax, %edi
	call	putchar@PLT
	addl	$1, -4(%rbp)
.L2:
	cmpl	$9, -4(%rbp)
	jbe	.L3
	movl	$10, %edi
	call	putchar@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
