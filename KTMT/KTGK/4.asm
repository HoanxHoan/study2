.data 
Message1: .asciiz "Nhap so luong phan tu mang:”
Message2: .asciiz "Nhap so nguyen:”
Message3: .asciiz "so lon nhat la: ”
Message4: .asciiz "nhap gia tri m:”
Message5: .asciiz "nhap gia tri M:”
Message6: .asciiz "so luong phan tu trong khoang (m,M) la:”
Xend: .word  
X: .word
.align 2
.text 
main:           
    # Nhập số phần tử của mảng
    li   $v0, 51           
    la   $a0, Message1
    syscall
    addi $s1, $a0 ,0        

    # Nhập các giá trị của mảng từ bàn phím
    la   $a2, X            # Địa chỉ bắt đầu của mảng
    li   $t0, 0             # Khởi tạo biến đếm vòng lặp

input_loop:
    beq  $t0, $s1, end_input   # Nếu đã nhập đủ số phần tử, thoát khỏi vòng lặp
    li   $v0, 51                
    la   $a0, Message2
    syscall
    sw $a0, 0($a2)           # Lưu giá trị nhập vào mảng
    addi $a2, $a2, 4           # Di chuyển con trỏ đến phần tử tiếp theo trong mảng
    addi $t0, $t0, 1           # Tăng biến đếm vòng lặp lên 1
    j    input_loop

end_input:   
             la   $a1, Xend 
             mul $s3,$s1,4
             add $a1,$a1,$s3
             sub $a2,$a2,$s3    
             j    find_max           
after_max:  
             li $v0,56
             la $a0,Message3
             addi $a1,$v1,0
             syscall
             j main2
end_main: 
find_max:       beq   $a2,$a1,after_max
            j   max
max: 
            addi $s0,$a2,0         
            lw   $v1,0($s0)        
            addi $t0,$a2,0         
     loop: 
            beq $t0,$a1,ret      
            addi $t0,$t0,4         
            lw $t1,0($t0)       
            slt $t2,$t1,$v1       
            bne $t2,$zero,loop 
            addi $s0,$t0,0      
            addi $v1,$t1,0      
            j loop             
ret: 
            j     after_max 
main2:
    # Nhập giá trị m và M từ bàn phím
    li $v0, 51 
    la $a0, Message4         
    syscall
    move $s5, $a0      # Lưu giá trị m vào $t0
    
    li $v0, 51
    la $a0, Message5 
    syscall
    move $s6, $a0      # Lưu giá trị M vào $t1
    
    # Khởi tạo số lượng phần tử trong khoảng
    li $s7, 0          # Khởi tạo biến đếm
    
    # Duyệt qua từng phần tử trong mảng
    addi $t3, $a2,0       # Địa chỉ bắt đầu của mảng
    addi $t4, $s1,0 # Số lượng phần tử của mảng
    li $t5, 0           # Khởi tạo chỉ số mảng
    
loop2:
    beq $t5, $t4, end_loop2  # Nếu đã duyệt qua hết mảng thì kết thúc vòng lặp
    
    lw $t6, 0($t3)       # Load giá trị phần tử hiện tại vào $t6
    
    # Kiểm tra xem phần tử có nằm trong khoảng (m, M) không
    ble $t6, $s5, not_in_range
    bge $t6, $s6, not_in_range
    
    # Nếu phần tử nằm trong khoảng, tăng biến đếm lên 1
    addi $s7, $s7, 1
    
not_in_range:
    addi $t5, $t5, 1     # Tăng chỉ số mảng lên 1
    addi $t3, $t3, 4     # Di chuyển địa chỉ lên phần tử tiếp theo
    j loop2

end_loop2:
    # In ra số lượng phần tử nằm trong khoảng
    li $v0, 56
    la $a0,Message6
    addi $a1, $s7,0
    syscall
    li $v0, 10
    syscall
