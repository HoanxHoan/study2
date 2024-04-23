.data
    array: .word 1, 5, 7, 9, 11, 15, 18, 20, 25, 30
    array_size: .word 10
Message4: .asciiz "nhap gia tri m:”
Message5: .asciiz "nhap gia tri M:”
Message6: .asciiz "so luong phan tu trong khoang (m,M) la: ”
.text


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
    la $t3, array       # Địa chỉ bắt đầu của mảng
    lw $t4, array_size # Số lượng phần tử của mảng
    li $t5, 0           # Khởi tạo chỉ số mảng
    
loop:
    beq $t5, $t4, end_loop  # Nếu đã duyệt qua hết mảng thì kết thúc vòng lặp
    
    lw $t6, 0($t3)       # Load giá trị phần tử hiện tại vào $t6
    
    # Kiểm tra xem phần tử có nằm trong khoảng (m, M) không
    ble $t6, $s5, not_in_range
    bge $t6, $s6, not_in_range
    
    # Nếu phần tử nằm trong khoảng, tăng biến đếm lên 1
    addi $s7, $s7, 1
    
not_in_range:
    addi $t5, $t5, 1     # Tăng chỉ số mảng lên 1
    addi $t3, $t3, 4     # Di chuyển địa chỉ lên phần tử tiếp theo
    j loop

end_loop:
    # In ra số lượng phần tử nằm trong khoảng
    li $v0, 56
    la $a0,Message6
    addi $a1, $s7,0
    syscall
    li $v0, 10
    syscall
