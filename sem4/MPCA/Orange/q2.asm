.data
    msg_change:  .string "Change: "
    msg_50:      .string "  50s: "
    msg_20:      .string "  20s: "
    msg_10:      .string "  10s: "
    msg_5:       .string "   5s: "
    msg_1:       .string "   1s: "
    newline:     .string "\n"

.text
.globl main

main:
    li   t0, 65         # price
    li   t1, 100        # amount paid
    sub  t2, t1, t0     # change = paid - price  => t2 = 35

    # Print "Change: "
    li   a7, 4
    la   a0, msg_change
    ecall

    # Print change value
    li   a7, 1
    mv   a0, t2
    ecall

    # Print newline
    li   a7, 4
    la   a0, newline
    ecall

    # --- 50s ---
    li   t3, 50
    div  t4, t2, t3     # count of 50s
    rem  t2, t2, t3     # remaining change

    li   a7, 4
    la   a0, msg_50
    ecall
    li   a7, 1
    mv   a0, t4
    ecall
    li   a7, 4
    la   a0, newline
    ecall

    # --- 20s ---
    li   t3, 20
    div  t4, t2, t3
    rem  t2, t2, t3

    li   a7, 4
    la   a0, msg_20
    ecall
    li   a7, 1
    mv   a0, t4
    ecall
    li   a7, 4
    la   a0, newline
    ecall

    # --- 10s ---
    li   t3, 10
    div  t4, t2, t3
    rem  t2, t2, t3

    li   a7, 4
    la   a0, msg_10
    ecall
    li   a7, 1
    mv   a0, t4
    ecall
    li   a7, 4
    la   a0, newline
    ecall

    # --- 5s ---
    li   t3, 5
    div  t4, t2, t3
    rem  t2, t2, t3

    li   a7, 4
    la   a0, msg_5
    ecall
    li   a7, 1
    mv   a0, t4
    ecall
    li   a7, 4
    la   a0, newline
    ecall

    # --- 1s ---
    li   a7, 4
    la   a0, msg_1
    ecall
    li   a7, 1
    mv   a0, t2          # remainder is the 1s
    ecall
    li   a7, 4
    la   a0, newline
    ecall

    # Exit
    li   a7, 10
    ecall
