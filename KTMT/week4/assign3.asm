.text
addi $s1,$s1,-30
addi $s2,$s2,10

slt $t0, $s2, $s1       # Nếu $s1 > $s2, gán $t0 = 1
beq $t0, $zero, L       # Nếu không, nhảy đến L
addi $s2,$s2,-1  
L:

