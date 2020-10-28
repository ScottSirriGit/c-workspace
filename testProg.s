	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 10, 15, 6
	.globl	_byte_rep               ## -- Begin function byte_rep
	.p2align	4, 0x90
_byte_rep:                              ## @byte_rep
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%rbx
	pushq	%rax
	.cfi_offset %rbx, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	decl	%esi
	js	LBB0_3
## %bb.1:
	movq	%rdi, %r15
	movslq	%esi, %rbx
	leaq	L_.str(%rip), %r14
	.p2align	4, 0x90
LBB0_2:                                 ## =>This Inner Loop Header: Depth=1
	movzbl	(%r15,%rbx), %esi
	movq	%r14, %rdi
	xorl	%eax, %eax
	callq	_printf
	decq	%rbx
	testl	%ebx, %ebx
	jns	LBB0_2
LBB0_3:
	movl	$10, %edi
	callq	_putchar
	addq	$8, %rsp
	popq	%rbx
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_bit_rep                ## -- Begin function bit_rep
	.p2align	4, 0x90
_bit_rep:                               ## @bit_rep
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset %rbx, -56
	.cfi_offset %r12, -48
	.cfi_offset %r13, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -48(%rbp)
	decl	%esi
	js	LBB1_7
## %bb.1:
	movq	%rdi, %r14
	movslq	%esi, %r13
	leaq	-58(%rbp), %r12
	leaq	L_.str.2(%rip), %r15
	.p2align	4, 0x90
LBB1_2:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB1_3 Depth 2
                                        ##       Child Loop BB1_4 Depth 3
	movb	(%r14,%r13), %bl
	movb	$32, -54(%rbp)
	movl	$1, %ecx
	movq	%r12, %rdx
	.p2align	4, 0x90
LBB1_3:                                 ##   Parent Loop BB1_2 Depth=1
                                        ## =>  This Loop Header: Depth=2
                                        ##       Child Loop BB1_4 Depth 3
	movl	$8, %esi
	.p2align	4, 0x90
LBB1_4:                                 ##   Parent Loop BB1_2 Depth=1
                                        ##     Parent Loop BB1_3 Depth=2
                                        ## =>    This Inner Loop Header: Depth=3
	movl	%ebx, %eax
	andb	$1, %al
	orb	$48, %al
	movb	%al, (%rdx,%rsi)
	shrb	%bl
	decq	%rsi
	cmpq	$4, %rsi
	jne	LBB1_4
## %bb.5:                               ##   in Loop: Header=BB1_3 Depth=2
	addq	$-5, %rdx
	subq	$1, %rcx
	jae	LBB1_3
## %bb.6:                               ##   in Loop: Header=BB1_2 Depth=1
	movq	%r15, %rdi
	movq	%r12, %rsi
	xorl	%eax, %eax
	callq	_printf
	decq	%r13
	testl	%r13d, %r13d
	jns	LBB1_2
LBB1_7:
	movl	$10, %edi
	callq	_putchar
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	cmpq	-48(%rbp), %rax
	jne	LBB1_9
## %bb.8:
	addq	$24, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
LBB1_9:
	callq	___stack_chk_fail
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3               ## -- Begin function main
LCPI2_0:
	.quad	9218868437227405312     ## double +Inf
LCPI2_1:
	.quad	-4503599627370496       ## double -Inf
LCPI2_2:
	.quad	9221120237041090560     ## double NaN
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r12
	pushq	%rbx
	subq	$16, %rsp
	.cfi_offset %rbx, -48
	.cfi_offset %r12, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	movl	$1083179008, -36(%rbp)  ## imm = 0x40900000
	xorl	%ebx, %ebx
	leaq	L___const.main.arr(%rip), %r12
	leaq	L_.str.3(%rip), %r14
	leaq	-36(%rbp), %r15
	.p2align	4, 0x90
LBB2_1:                                 ## =>This Inner Loop Header: Depth=1
	movss	(%rbx,%r12), %xmm0      ## xmm0 = mem[0],zero,zero,zero
	movss	%xmm0, -40(%rbp)        ## 4-byte Spill
	cvtss2sd	%xmm0, %xmm0
	movq	%r14, %rdi
	movb	$1, %al
	callq	_printf
	movss	-40(%rbp), %xmm0        ## 4-byte Reload
                                        ## xmm0 = mem[0],zero,zero,zero
	movss	%xmm0, -36(%rbp)
	movl	$4, %esi
	movq	%r15, %rdi
	callq	_bit_rep
	movl	$10, %edi
	callq	_putchar
	addq	$4, %rbx
	cmpq	$16, %rbx
	jne	LBB2_1
## %bb.2:
	movl	$10, %edi
	callq	_putchar
	leaq	L_.str.4(%rip), %rdi
	movsd	LCPI2_0(%rip), %xmm0    ## xmm0 = mem[0],zero
	movsd	LCPI2_1(%rip), %xmm1    ## xmm1 = mem[0],zero
	movsd	LCPI2_2(%rip), %xmm2    ## xmm2 = mem[0],zero
	movb	$3, %al
	callq	_printf
	leaq	L_.str.5(%rip), %rdi
	xorl	%eax, %eax
	callq	_printf
	leaq	L_.str.6(%rip), %rdi
	xorl	%eax, %eax
	callq	_printf
	xorl	%eax, %eax
	addq	$16, %rsp
	popq	%rbx
	popq	%r12
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%02x "

L_.str.2:                               ## @.str.2
	.asciz	"%s "

	.section	__TEXT,__literal16,16byte_literals
	.p2align	4               ## @__const.main.arr
L___const.main.arr:
	.long	1078523331              ## float 3.1400001
	.long	1343554297              ## float 1.0E+10
	.long	1078523328              ## float 3.13999939
	.long	1078523331              ## float 3.1400001

	.section	__TEXT,__cstring,cstring_literals
L_.str.3:                               ## @.str.3
	.asciz	"%f:\n"

L_.str.4:                               ## @.str.4
	.asciz	"%f + %f = %f\n\n"

L_.str.5:                               ## @.str.5
	.asciz	"%d\n"

L_.str.6:                               ## @.str.6
	.asciz	"%x\n\n"

.subsections_via_symbols
