.data
Message3: .asciiz "true”
Message4: .asciiz "false”
Message1: .asciiz "Nhap so luong phan tu mang:”
Message2: .asciiz "Nhap so nguyen:”
X: .word 
.align 2
.text
main:
    li   $v0, 51           
    la   $a0, Message1
    syscall
    addi $t2, $a0 ,0  
    la   $a2, X            # Địa chỉ bắt đầu của mảng
    li   $t0, 0  
input_loop:
    beq  $t0, $t2, end_input   # Nếu đã nhập đủ số phần tử, thoát khỏi vòng lặp
    li   $v0, 51                
    la   $a0, Message2
    syscall
    sw $a0, 0($a2)           # Lưu giá trị nhập vào mảng
    addi $a2, $a2, 4           # Di chuyển con trỏ đến phần tử tiếp theo trong mảng
    addi $t0, $t0, 1           # Tăng biến đếm vòng lặp lên 1
    j    input_loop
end_input:  
    mul $s3,$t2,4 
    sub $a2,$a2,$s3
    addi $s0,$t2,-1  
    j check

check:
    li $t3,0
    ble $t2,2,return_true
  loop:
    addi $t3,$t3,1
    lw $t0, 0($a2)            # Phần tử hiện tại
    lw $t1, 4($a2)            # Phần tử tiếp theo
    bge $t0, $t1, check_remove  # Nếu phần tử hiện tại >= phần tử tiếp theo, kiểm tra vi phạm
    addi $a2,$a2,4
    bne $t3,$t2,loop
    j return_true
check_remove:
    #loai phan tu hien tai
    la $a3,($a2)
    lw $t0,-4($a3)
    lw $t1,4($a3)
    bge $t0, $t1, check_remove2
    addi $t4,$t3,0
    addi $a3,$a3,4
    beq $t4,$s0,return_true
    loop1:  
    lw $t0, 0($a3)            
    lw $t1, 4($a3) 
    bge $t0, $t1, check_remove2
    addi $a3,$a3,4
    addi $t4,$t4,1
    bne $t4,$s0,loop1
    j return_true
check_remove2:
    #loai phan tu tiep sau phan tu hien tai
    la $s1,($a2)
    lw $t0,0($s1)
    lw $t1,8($s1)
    bge $t0, $t1, return_false
    addi $t4,$t3,0
    addi $s1,$s1,8
    beq $t3,$s0,return_true
    loop2:
    lw $t0, 0($s1)            
    lw $t1, 4($s1) 
    bge $t0, $t1, return_false
    addi $s1,$s1,4
    addi $t4,$t4,1
    bne $t3,$s0,loop2
    j return_true
return_false:
  li $v0, 55                  
  la $a0, Message4
  syscall                     
  li $v0, 10                  
  syscall                    
return_true:
  li $v0, 55                 
  la $a0, Message3          
  syscall                     
  li $v0, 10                  
  syscall                     
