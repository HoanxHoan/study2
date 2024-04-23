addi $s1,$s1,5
addi $t0,$t0,10
Loop:
    # Kiểm tra điều kiện kết thúc vòng lặp
    beq $s1, $zero, End

    # Nhân kết quả hiện tại với 2 (dịch bit sang trái)
    sll $t0, $t0, 1

    # Giảm số mũ của 2 đi 1
    addi $s1, $s1, -1

    # Lặp lại vòng lặp
    j Loop

# Lưu kết quả vào $s0
add $s0, $zero, $t0

End:

