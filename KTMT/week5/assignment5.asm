.data
i: .space 20      
o: .space 20      
.text
main:
li $s4,19
li $s0,0
la $a1,i
la $a2,o
input_loop:
    li $v0, 12              
    syscall
    beq $v0,10,end_input
    add $t1,$s0,$a1     
    sb $v0,0($t1)
    addi $s0, $s0, 1      
    bgt $s0,$s4,end_input
    j input_loop
end_input:
reverse_loop:
    addi $s0, $s0, -1      
    add $s1,$zero,$zero
    la $s4,-1
    loop:
    beq $s0,$s4,endl
    add $t1,$s0,$a1
    lb $t2,0($t1)
    add $t3,$s1,$a2
    sb $t2,0($t3)
    addi $s0,$s0,-1
    addi $s1,$s1,1
    j loop         
    endl:
    li $v0, 11
    addi $a0,$zero,'\n'
    syscall
    li $v0,4
    la $a0,o
    syscall
