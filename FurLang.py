#!/usr/bin/env python3

# Porth <3 you

import subprocess
import sys

iota_counter = 0
def iota(reset=False):
    global iota_counter
    if reset:
        iota_counter = 0
    iota_counter += 1
    return iota_counter

OP_PUSH = iota()
OP_POP = iota()
OP_SET = iota()
OP_ADD = iota()
OP_SUB = iota()
OP_DUMP = iota()
OP_COUNT = iota()

def PUSH(rd):
    return (OP_PUSH, rd)

def POP(rd):
    return (OP_POP, rd)

def SET(rd, rs):
    return (OP_SET, rd, rs)

def ADD():
    return (OP_ADD, )

def SUB():
    return (OP_SUB, )
    
def DUMP():
    return (OP_DUMP, )

def run(program):
    stack = []
    for op in program:
        if op[0] == OP_PUSH:
            stack.append(op[1])
        elif op[0] == OP_POP:
            stack.pop()
        elif op[0] == OP_SET:
            stack[op[1]] = op[2]
        elif op[0] == OP_ADD:
            a = stack.pop()
            b = stack.pop()
            stack.append(a + b)
        elif op[0] == OP_SUB:
            a = stack.pop()
            b = stack.pop()
            stack.append(b - a)
        elif op[0] == OP_DUMP:
            print(stack)

k = ["add", "remove"]

def parseLineToOp(keyword):
    if len(keyword) == 1:
        if keyword[0] == "dump":
            return [DUMP()]
    elif len(keyword) == 4:
        if not keyword[0] in k or (keyword[0] == "add" and keyword[2] != "to") or (keyword[0] == "remove" and keyword[2] != "from"):
            raise SyntaxError("Invalid Syntax")
        
        a = int(keyword[1])
        b = int(keyword[3])
        return [PUSH(a), PUSH(b), keyword[0] == "add" and ADD() or SUB()]
    else:
        raise SyntaxError("Invalid Syntax")
    return []

def loadProgram(path):
    program = open(path, "r")
    instruction = []
    for word in program.read().split('\n'):
        instruction = [*instruction, *parseLineToOp(word.split())]
    return instruction


def compile(program):
    asm = open("output.asm", "w")
    asm.write("BITS 64\n")
    asm.write("segment .text\n")
    asm.write("print:\n")
    asm.write("    mov     r9, -3689348814741910323\n")
    asm.write("    sub     rsp, 40\n")
    asm.write("    mov     BYTE [rsp+31], 10\n")
    asm.write("    lea     rcx, [rsp+30]\n")
    asm.write(".L2:\n")
    asm.write("    mov     rax, rdi\n")
    asm.write("    lea     r8, [rsp+32]\n")
    asm.write("    mul     r9\n")
    asm.write("    mov     rax, rdi\n")
    asm.write("    sub     r8, rcx\n")
    asm.write("    shr     rdx, 3\n")
    asm.write("    lea     rsi, [rdx+rdx*4]\n")
    asm.write("    add     rsi, rsi\n")
    asm.write("    sub     rax, rsi\n")
    asm.write("    add     eax, 48\n")
    asm.write("    mov     BYTE [rcx], al\n")
    asm.write("    mov     rax, rdi\n")
    asm.write("    mov     rdi, rdx\n")
    asm.write("    mov     rdx, rcx\n")
    asm.write("    sub     rcx, 1\n")
    asm.write("    cmp     rax, 9\n")
    asm.write("    ja      .L2\n")
    asm.write("    lea     rax, [rsp+32]\n")
    asm.write("    mov     edi, 1\n")
    asm.write("    sub     rdx, rax\n")
    asm.write("    xor     eax, eax\n")
    asm.write("    lea     rsi, [rsp+32+rdx]\n")
    asm.write("    mov     rdx, r8\n")
    asm.write("    mov     rax, 1\n")
    asm.write("    syscall\n")
    asm.write("    add     rsp, 40\n")
    asm.write("    ret\n")
    asm.write("global _start\n")
    asm.write("_start:\n")
    for op in program:
        if op[0] == OP_PUSH:
            asm.write("    ;; -- push %d --\n" % op[1])
            asm.write("    push %d\n" % op[1])
        elif op[0] == OP_ADD:
            asm.write("    ;; -- plus --\n")
            asm.write("    pop rax\n")
            asm.write("    pop rbx\n")
            asm.write("    add rax, rbx\n")
            asm.write("    push rax\n")
        elif op[0] == OP_SUB:
            asm.write("    ;; -- sub --\n")
            asm.write("    pop rax\n")
            asm.write("    pop rbx\n")
            asm.write("    sub rbx, rax\n")
            asm.write("    push rbx\n")
        elif op[0] == OP_DUMP:
            asm.write("    ;; -- dump --\n")
            asm.write("    pop rdi\n")
            asm.write("    call print\n")
        else:
            assert False, "unreachable"
    asm.write("    ;; -- end --\n")
    asm.write("    mov rax, 60\n")
    asm.write("    mov rdi, 0\n")
    asm.write("    syscall\n")

if __name__ == "__main__":
    compile(loadProgram(sys.argv[1]))
    subprocess.call(["nasm", "-felf64", "output.asm"])
    subprocess.call(["ld", "-o", "output", "output.o"])
    subprocess.call(["./output"])
    