.data
    newline: .byte '\n'

.text
.globl main

main:
    li   t0, 0          # row = 0

row_loop:
    li   t1, 5
    bge  t0, t1, end    # if row >= 5, done

    li   t2, 0          # col = 0

col_loop:
    li   t3, 5
    bge  t2, t3, end_col  # if col >= 5, end column loop

    # Compare row and col
    bne  t0, t2, print_dot

print_hash:
    li   a7, 11
    li   a0, '#'
    ecall
    j    col_done

print_dot:
    li   a7, 11
    li   a0, '.'
    ecall

col_done:
    addi t2, t2, 1      # col++
    j    col_loop

end_col:
    # Print newline
    li   a7, 11
    li   a0, '\n'
    ecall

    addi t0, t0, 1      # row++
    j    row_loop

end:
    li   a7, 10         # exit
    ecall
