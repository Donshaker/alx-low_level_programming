section .data
    hello db 'Hello, Holberton', 0
    format db '%s', 0
    new_line db 10, 0

section .text
    global custom_printf
    extern printf

custom_printf:
    ; Set up the stack frame (not required in this simple example)
    push rbp
    mov rbp, rsp

    ; Print the string using printf
    lea rdi, [hello]
    lea rsi, [format]
    call printf

    ; Print a new line
    lea rdi, [new_line]
    call printf

    ; Clean up the stack and return
    leave
    ret

section .text
    global _start

_start:
    ; Call the custom_printf function
    call custom_printf

    ; Exit the program
    mov rax, 60         ; syscall number for exit
    xor rdi, rdi        ; exit status 0
    syscall

