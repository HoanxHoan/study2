.data
array: .word 5, -3, 9, -2, 7  # Mảng các số nguyên
array_size: .word 5  # Số lượng phần tử trong mảng

.text
main:
    la $s0, array         # Load địa chỉ của mảng vào $s0
    lw $s1, array_size    # Load số lượng phần tử của mảng vào $s1

    li $t0, 0             # Khởi tạo giá trị tạm thời (tạm thời) là 0 (max_abs)
    li $t1, 0             # Khởi tạo biến đếm (i) là 0

find_max_abs:
    bge $t1, $s1, end_find# Nếu đã so sánh hết tất cả các phần tử, thoát khỏi vòng lặp
    lw $t2, 0($s0)        # Load giá trị của phần tử thứ i vào $t2
    blt $t2, $zero, check_negative  # Nếu giá trị là số âm, nhảy đến check_negative
    j compare_max_abs

check_negative:
    sub  $t2,$0,$t2         # Đổi dấu giá trị số âm
    j compare_max_abs
compare_max_abs:
    bge  $t0, $t2, next_element  # Nếu giá trị tuyệt đối nho hơn hoặc bằng giá trị tạm thời, qua phần tử tiếp theo
    move   $t0, $t2         # Cập nhật giá trị tạm thời

next_element:
    addi $s0, $s0, 4      # Di chuyển đến phần tử tiếp theo trong mảng
    addi $t1, $t1, 1      # Tăng biến đếm

    j find_max_abs        # Quay lại vòng lặp

end_find:

