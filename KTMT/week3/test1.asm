#Laboratory Exercise 3, Home Assignment 1 
start: 
addi $s1, $zero, 0 # $s1 = 0 +1
addi $s2, $zero, 5   # $s2 = 0 + 0 
sle  $t0,$s2,$s1  # i>=j
beq $t0,$zero,else # branch to else if i<j
addi $t1,$t1,1  #  then part: x=x+1 
addi $t3,$zero,1  # z=1 
j endif   # skip “else” part 
else: addi $t2,$t2,-1  # begin else part: y=y-1 
add $t3,$t3,$t3  # z=2*z 
endif: 
