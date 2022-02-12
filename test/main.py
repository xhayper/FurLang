#!/usr/bin/env python3

# Porth <3 you

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
            
            

run([PUSH(1), PUSH(3), PUSH(5), DUMP(), ADD(), DUMP()])