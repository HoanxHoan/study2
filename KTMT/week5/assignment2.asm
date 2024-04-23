.data
    result_msg: .asciiz "The sum of "
    s0_msg: .asciiz " and "
    is_msg: .asciiz " is "
    newline: .asciiz "\n"
.text
    li $s0,9
    li $s1,20
    li $v0, 4               
    la $a0, result_msg      
    syscall
    
    li $v0, 1               
    move $a0, $s0          
    syscall

    li $v0, 4               
    la $a0, s0_msg          
    syscall
  
    li $v0, 1               
    move $a0, $s1           
    syscall
 
    li $v0, 4               
    la $a0, is_msg          
    syscall
    
    add $t0, $s0, $s1       

    li $v0, 1               
    move $a0, $t0
    syscall

    li $v0, 4
    la $a0, newline       
    syscall

    li $v0, 10              
    syscall
