#Laboratory 3, Home Assigment 2 
.data
A: .word 1, 2, 3, 4, 5  # Khai báo mảng A với 5 phần tử và gán giá trị
.text 
addi $s4,$s4,0x00000001 
addi $s1,$s1,0x00000000
addi $s3,$s3,0x00000005
la $s2, A     # $s2 chứa địa chỉ của mảng A
loop: add  $s1,$s1,$s4  #i=i+step 
add  $t1,$s1,$s1  #t1=2*s1 
add $t1,$t1,$t1  #t1=4*s1  
add $t1,$t1,$s2  #t1 store the address of A[i] 
lw $t0,0($t1)  #load value of A[i] in $t0 
add $s5,$s5,$t0  #sum=sum+A[i] 
sle $s0, $s1,$s3 # i<=n
beq $t0,1,loop #if i<=n, goto loop 