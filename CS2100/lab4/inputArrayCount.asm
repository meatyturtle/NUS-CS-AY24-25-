# arrayCount.asm
  .data 
arrayA: .word 2, 2, 2, 2, 2, 2, 2, 2  # arrayA has 8 values
count:  .word 0                        # dummy value

  .text
main:
    # code to setup the variable mappings
    la $t0, arrayA
    la $t8, count
    lw $t9, 0($t8)

    # code for reading array values
    add $s3, $t0, $zero  
    addi $s4, $t0, 32   

    arrayloop: slt $t1, $s3, $s4            
    	beq $t1, $zero, out  
        li $v0, 5  # system call code for read_int 
        syscall
        la $t7, 0($v0)  
        sw $t7, 0($s3)            
	addi $s3, $s3, 4  
        j arrayloop
    out: 

    # code for reading in the user value X
    li $v0, 5       
    syscall

    # code for counting multiples of X in arrayA
    la $t4, 0($v0)
    addi $t5, $t4, -1
    add $s2, $t0, $zero
    addi $s0, $t0, 32
  
    loop: slt $t2, $s2, $s0
	  beq $t2, $zero, exit
          lw $t3, 0($s2)
          and $t4, $t3, $t5
          bne $t4, $zero, skip
          addi $t9, $t9, 1
    skip: addi $s2, $s2, 4
          j loop 
    exit: 

    # code for printing result
    li $v0, 1
    la $a0, 0($t9)
    syscall

    la $t6, count
    sw $t9, 0($t6) 

    # code for terminating program
    li  $v0, 10
    syscall
