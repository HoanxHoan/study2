.data 
A: .word  1,5,3,9,7,15
Aend: .word 
.text
main:       
    la   $a2, A           # $a0 = Address(A[0]) 
    la   $a1, Aend 
    addi $a1, $a1, -4     # $a1 = Address(A[n-1])    
    la   $a3, Aend
    addi $a3, $a3, 4
    jal    BubbleSort       
    jal   print_sorted_array

    li   $v0, 10          # Kết thúc chương trình
    syscall

print_sorted_array:
    j    print_loop        # Nhảy đến vòng lặp in mảng

print_loop:
    lw   $a0, 0($a2)       # Load giá trị của phần tử mảng
    li   $v0, 1            # Đặt syscall để in ra số nguyên
    syscall                # In ra giá trị của phần tử
    li   $v0, 11           # Đặt syscall để in ra dấu cách
    li   $a0, 32           # ASCII code của dấu cách
    syscall                # In ra dấu cách
    addi $a2, $a2, 4       # Tiếp tục với phần tử tiếp theo của mảng
    bne  $a2, $a3, print_loop # Lặp lại cho đến khi hết mảng
    jr   $ra               # Trở về nơi gọi hàm

BubbleSort:
outer_loop:
    li   $t1, 0           # Đặt cờ cho biết đã hoán đổi
    la   $t2, A           # $t2 = Address(A[0])
    la   $t3, Aend        # $t3 = Address(A[n-1])
    sub  $t3, $t3, $t0    # Bỏ qua phần tử đã sắp xếp ở cuối mảng
inner_loop:
    lw   $t4, 0($t2)      # Load giá trị của phần tử hiện tại
    lw   $t5, 4($t2)      # Load giá trị của phần tử kế tiếp
    ble  $t4, $t5, no_swap   # Nếu phần tử hiện tại nhỏ hơn phần tử kế tiếp, không cần hoán đổi
    sw   $t5, 0($t2)      # Swap giá trị của phần tử hiện tại và phần tử kế tiếp
    sw   $t4, 4($t2)
    li   $t1, 1           # Đặt cờ đã hoán đổi
no_swap:
    addi $t2, $t2, 4      # Tiếp tục với phần tử tiếp theo của mảng
    bne  $t2, $t3, inner_loop # Lặp lại cho đến khi hết mảng
    bne  $t1, $zero, outer_loop # Nếu đã hoán đổi, lặp lại vòng lặp ngoài
    jr   $ra              # Kết thúc hàm và trở về main

           
