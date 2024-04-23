.data
 L:.asciiz "largest: "
 S:.asciiz "Smallest: "
 com:.asciiz","
.text
Main:
   li $s0,1
   li $s1,3
   li $s2,5
   li $s3,7
   li $s4,9
   li $s5,11
   li $s6,21
   li $s7,-4
   jal store
   nop
   #in ra số lớn nhất và vị trí của nó
   li $v0,4
   la $a0,L
   syscall
   add $a0,$t0,$zero
   li $v0,1
   syscall
   li $v0,4
   la $a0,com
   syscall
   add $a0,$t5,$zero
   li $v0,1
   syscall
   li $v0, 11
   li $a0, 10          
   syscall 
   #in ra số nhỏ nhất và vị trí của nó
   li $v0,4
   la $a0,S
   syscall
   add $a0,$t1,$zero
   li $v0,1
   syscall
   li $v0,4
   la $a0,com
   syscall
   add $a0,$t6,$zero
   li $v0,1
   syscall
   li $v0,10
   syscall
store:
   add $t9,$sp ,$zero
   addi $sp,$sp,-32
   sw $s1,0($sp)
   sw $s2,4($sp)
   sw $s3,8($sp)
   sw $s4,12($sp)
   sw $s5,16($sp)
   sw $s6,20($sp)
   sw $s7,24($sp)
   sw $ra,28($sp)
   add $t0,$s0,$zero # gán mãx = s0
   add $t1,$s0,$zero #gán min = s0
   li $t5,0 #chỉ số của max = 0
   li $t6,0 #chỉ số của min = 0
   li $t2,0 #i = 0
compare:
   addi $sp,$sp,4
   lw $t3,-4($sp)
   sub $t4,$sp,$t9
   beq $t4,$zero,done#nếu $sp = $fp => done
   nop
   addi $t2,$t2,1 # tăng i thêm 1
   sub $t4,$t0,$t3
   bltzal $t4,swapmax #nếu t3 > max => swapmax
   nop
   sub $t4,$t3,$t1
   bltzal $t4,swapmin #nếu t3 < min => sưapmin
   nop
   j compare  #lặp lại
swapmax:
   add $t0,$t3,$zero
   add $t5,$t2,$zero
   jr $ra
swapmin:
   add $t1,$t3,$zero
   add $t6,$t2,$zero
   jr $ra
done:
   lw $ra,-4($sp)
   jr $ra
   
