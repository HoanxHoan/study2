addi $s1,$s1,10
addi $s2,$s2,50
add $t0, $s1, $s2     # Thực hiện phép cộng $s1 và $s2, kết quả lưu vào $t0
# Kiểm tra dấu của $s1 và $s2
slt $t1, $s1, $zero   # Kiểm tra xem $s1 có âm không
slt $t2, $s2, $zero   # Kiểm tra xem $s2 có âm không

xor $t3, $t1, $t2     # Kiểm tra xem $s1 và $s2 có cùng dấu không
bne $t3, $zero, Exit # Nếu không, nhảy đến nhãn Exit

# Kiểm tra dấu của tổng
slt $t4, $t0, $zero   # Kiểm tra xem tổng có âm không
bne $t4, $t1, Overflow # Nếu tổng không cùng dấu với $s1, nhảy đến nhãn Overflow

# Kết thúc chương trình nếu không có tràn số
j Exit

Overflow:
    li $t5, 1          # Gán 1 vào $t5 để đánh dấu tràn số

Exit:
    # Kết thúc chương trình
