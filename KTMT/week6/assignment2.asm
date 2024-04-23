.data 
A: .word  1,5,3,9,7,15
Aend: .word  
.text 
main:       la   $a2,A           #$a0 = Address(A[0]) 
            la   $a1,Aend 
            addi $a1,$a1,-4      #$a1 = Address(A[n-1]) 
            j    sort            #sort 
after_sort: li $v0,1
            lw $a0,0($a1)
            syscall
            li   $v0, 10         #exit 
            syscall 
end_main: 
sort:       beq   $a2,$a1,done #single element list is sorted 
            j   max        #call the max procedure 
after_max:  
            lw   $t0,0($a1) #load last element into $t0 
            sw   $t0,0($s0) #copy last element to max location 
            sw   $v1,0($a1) #copy max value to last element 
            addi $a1,$a1,-4      #decrement pointer to last element 
            li $v0,1
            addi $a0,$v1,0
            syscall
            li $v0, 11         
            li $a0, 32         
            syscall  
            j   sort  #repeat sort for smaller list 
done:       j       after_sort 
max: 
 addi $s0,$a2,0         #init max pointer to first element 
 lw   $v1,0($s0)        #init max value to first value 
 addi $t0,$a2,0         #init next pointer to first 
loop: 
 beq $t0,$a1,ret       #if next=last, return 
 addi $t0,$t0,4         #advance to next element 
 lw $t1,0($t0)        #load next element into $t1 
 slt $t2,$t1,$v1       #(next)<(max) ? 
 bne $t2,$zero,loop #if (next)<(max), repeat 
 addi $s0,$t0,0       #next element is new max element 
 addi $v1,$t1,0       #next value is new max value 
 j loop             #change completed; now repeat 
ret: 
 j     after_max 