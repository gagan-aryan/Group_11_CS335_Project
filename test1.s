.data
a:	.word	0
test:	.word	0
t_str0:	.asciiz	"hello world"
.text
main:
l1:
j	main_prog
ast:
	addi	$sp,$sp,-4
sw	$ra,0($sp)
li	$a1, 5
addi	$a1, $a1, 1
sub	$a1, $a1, 1
add 	$v0, $0, $a1
sw	$a1, test
lw	$ra,0($sp)
addi 	$sp,$sp,4
addi 	$sp,$sp,0
jr 	$ra
main_prog:
	li	$a2, 5
lw	$a3, t_str0
li	$v0, 1
move	$a0, $a3
syscall
sw	$a2, a
sw	$a3, t_str0
li 	$v0, 10
syscall
