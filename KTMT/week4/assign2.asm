.text 
addi $s0,$s0,100
# Trích xuất MSB của $s0
srl $t0, $s0, 31      # Dịch phải 31 bit để lấy MSB của $s0

# Xóa LSB của $s0
srl $s0, $s0, 1       # Dịch phải 1 bit để xóa LSB

# Đặt LSB là $s0 (bit 7 đến 0 được đặt thành 1)
li $t1, 1             # Gán giá trị 1 vào thanh ghi $t1
or $s0, $s0, $t1     # Lấy OR giữa $s0 và $t1 để đặt LSB là 1

# Xóa $s0 (s0=0, phải sử dụng lệnh logic)
xor $s0, $s0, $s0     # XOR giữa $s0 và chính nó sẽ cho kết quả là 0

