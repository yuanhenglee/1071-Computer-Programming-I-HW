	.file	"ex7.c"
	.text
	.globl	swap
	.type	swap, @function
swap:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -4(%ebp)
	movl	12(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, (%eax)
	movl	12(%ebp), %eax
	movl	-4(%ebp), %edx
	movl	%edx, (%eax)
	nop
	leave
	ret
	.size	swap, .-swap
	.section	.rodata
.LC0:
	.string	"%d,%d,%d"
.LC1:
	.string	"%d,%d,%d\n"
	.text
	.globl	main
	.type	main, @function
main:
	leal	4(%esp), %ecx
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%ebx
	pushl	%ecx
	subl	$108, %esp
	leal	-80(%ebp), %edx
	movl	$0, %eax
	movl	$9, %ecx
	movl	%edx, %edi
	rep stosl
	leal	-116(%ebp), %edx
	movl	$0, %eax
	movl	$9, %ecx
	movl	%edx, %edi
	rep stosl
	movl	$0, -28(%ebp)
	jmp	.L3
.L4:
	movl	-28(%ebp), %eax
	leal	2(%eax), %edx
	leal	-80(%ebp), %eax
	sall	$2, %edx
	leal	(%eax,%edx), %ecx
	movl	-28(%ebp), %eax
	leal	1(%eax), %edx
	leal	-80(%ebp), %eax
	sall	$2, %edx
	addl	%eax, %edx
	leal	-80(%ebp), %eax
	movl	-28(%ebp), %ebx
	sall	$2, %ebx
	addl	%ebx, %eax
	pushl	%ecx
	pushl	%edx
	pushl	%eax
	pushl	$.LC0
	call	scanf
	addl	$16, %esp
	movl	-28(%ebp), %eax
	movl	-80(%ebp,%eax,4), %edx
	movl	-28(%ebp), %eax
	addl	$1, %eax
	movl	-80(%ebp,%eax,4), %eax
	imull	%eax, %edx
	movl	-28(%ebp), %eax
	addl	$2, %eax
	movl	-80(%ebp,%eax,4), %eax
	imull	%eax, %edx
	movl	-28(%ebp), %eax
	movl	%edx, -116(%ebp,%eax,4)
	addl	$3, -28(%ebp)
.L3:
	cmpl	$8, -28(%ebp)
	jle	.L4
	movl	$0, -32(%ebp)
	jmp	.L5
.L11:
	movl	$0, -36(%ebp)
	jmp	.L6
.L10:
	movl	-36(%ebp), %eax
	movl	-116(%ebp,%eax,4), %edx
	movl	-36(%ebp), %eax
	addl	$3, %eax
	movl	-116(%ebp,%eax,4), %eax
	cmpl	%eax, %edx
	jle	.L7
	movl	-36(%ebp), %eax
	movl	%eax, -40(%ebp)
	jmp	.L8
.L9:
	movl	-40(%ebp), %eax
	leal	3(%eax), %edx
	leal	-80(%ebp), %eax
	sall	$2, %edx
	addl	%eax, %edx
	leal	-80(%ebp), %eax
	movl	-40(%ebp), %ecx
	sall	$2, %ecx
	addl	%ecx, %eax
	subl	$8, %esp
	pushl	%edx
	pushl	%eax
	call	swap
	addl	$16, %esp
	addl	$1, -40(%ebp)
.L8:
	movl	-36(%ebp), %eax
	addl	$3, %eax
	cmpl	-40(%ebp), %eax
	jg	.L9
	movl	-36(%ebp), %eax
	leal	3(%eax), %edx
	leal	-116(%ebp), %eax
	sall	$2, %edx
	addl	%eax, %edx
	leal	-116(%ebp), %eax
	movl	-36(%ebp), %ecx
	sall	$2, %ecx
	addl	%ecx, %eax
	subl	$8, %esp
	pushl	%edx
	pushl	%eax
	call	swap
	addl	$16, %esp
.L7:
	addl	$3, -36(%ebp)
.L6:
	cmpl	$3, -36(%ebp)
	jle	.L10
	addl	$1, -32(%ebp)
.L5:
	cmpl	$2, -32(%ebp)
	jle	.L11
	movl	$0, -44(%ebp)
	jmp	.L12
.L13:
	movl	-44(%ebp), %eax
	addl	$2, %eax
	movl	-80(%ebp,%eax,4), %ecx
	movl	-44(%ebp), %eax
	addl	$1, %eax
	movl	-80(%ebp,%eax,4), %edx
	movl	-44(%ebp), %eax
	movl	-80(%ebp,%eax,4), %eax
	pushl	%ecx
	pushl	%edx
	pushl	%eax
	pushl	$.LC1
	call	printf
	addl	$16, %esp
	addl	$3, -44(%ebp)
.L12:
	cmpl	$8, -44(%ebp)
	jle	.L13
	movl	$0, %eax
	leal	-12(%ebp), %esp
	popl	%ecx
	popl	%ebx
	popl	%edi
	popl	%ebp
	leal	-4(%ecx), %esp
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 5.2.0"
