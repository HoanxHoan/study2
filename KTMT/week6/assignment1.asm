.data 
A: .word -2, 6, -1, 3, -2, 4
.text 
main:       la $a0,A    
            li $a1,6 
            j     mspfx 
mspfx:  addi $v0,$zero,0 # Khởi tạo độ dài (length) trong $v0 là 0 
        addi $v1,$zero,0 # Khởi tạo max sum trong $v1 là 0 
        addi $t0,$zero,0 # Khởi tạo chỉ mục i trong $t0 là 0 
        addi $t1,$zero,0 # Khởi tạo running sum trong $t1 là 0 
loop: sll $t2,$t0,2         # Tính 4i và lưu vào $t2 
      add $t3,$t2,$a0       # Tính địa chỉ của A[i] và lưu vào $t3 
      lw $t4,0($t3)  # Load giá trị A[i] vào $t4 
      add $t1,$t1,$t4       # Cộng giá trị A[i] vào running sum trong $t1 
      slt $t5,$v1,$t1       # So sánh max sum với running sum mới 
      bne $t5,$zero,mdfy  # Nếu max sum < running sum, điều chỉnh kết quả 
      j test        # Kiểm tra kết thúc vòng lặp 
mdfy: addi $v0,$t0,1  # Cập nhật độ dài prefix mới là i+1 
      add $v1,$t1,$zero  # Cập nhật max sum mới 
test: addi $t0,$t0,1  # Tăng chỉ mục i 
      slt $t5,$t0,$a1      # Kiểm tra xem i < n 
      bne $t5,$zero,loop # Lặp lại nếu i < n 
 
move $t0, $v0 
li $v0, 1          
move $a0, $t0      
syscall        # in ra độ dài prefix
          
li $v0, 11         
li $a0, 32         
syscall  
    
li $v0,1
add $a0,$0,$v1
syscall        #in ra giá trị tổng lớn nhất
