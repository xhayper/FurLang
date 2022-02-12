# OP_CODES

This page will describe the OP_CODE that FurLang will use, It's very simillar to C#'s OP_CODE

## Specification

```
~blep~ ALL NUMBER START AT 0
~blep~ ARGS, VAR, FUNCTION and RESULT have different offset
~blep~ ARGS = ARR[4096], VAR = ARR[4096], FUNCTION = ARR[4096], RESULT = ARR[4096], STACK = ARR[4096]

LD_ARGS N ~blep~ Load args number N from the function to the STACK
LD_VAR N ~belp~ Load variable at offset N to the STACK
LD_RESULT N ~blep~ Load the result of a function at N offset to the STACK

SET_POINTER_TYPE N ~blep~ Set the pointer to specific array where 1 - ARGS, 2 - VAR, 3 - FUNCTION and 4 - RESULT
SET_POINTER_OFFSET N ~blep~ Set the pointer's offset to N

CALL N ~blep~ Load function from offset N, It will store the value in RESULT stack, Clearing previous RESULT stack
CLEAR N ~blep~ Clear the stack by type, 1 - ARGS, 2 - VAR, 3 - FUNCTION, 4 - RESULT and 5 - STACK
MOVE_TO N ~blep~ Move the STACK[0] to VAR[N]
MOVE_ALL_TO N ~blep~ Move the entire stack to VAR[N]

ADD ~blep~ Add STACK[0] and STACK[1] and set STACK [0] to the result, and move all of the STACK element location after STACK[1] to POS-1 (Where POS is the STACK element position)
REMOVE ~blep~ Same as ADD but this time it's remove
MULTIPY ~blep~ Same as ADD but this time it's multipy
DIVIDE ~blep~ Same as ADD but this time it's divide
MODULO ~blep~ Same as ADD but this time it's modulo

SET ~blep~ Set the POINTER_TYPE[POINTER_OFFSET] to STACK[0]
SETALL ~blep~ Set the POINTER_TYPE[POINTER_OFFSET] to STACK

IF_FALSE N ~blep~ if STACK[0] is false, jump to offset N
IF_TRUE N ~blep~ Same as IF_FALSE but instead of FALSE, it's TRUE

IF_FALSE_RET ~blep~ Same as IF_FALSE but instead of jumping to offset N, It return instead
IF_TRUE_RET ~blep~ Same as IF_TRUE_RET but instead of FALSE, it's TRUE

RET ~blep~ Return the value in the STACK
```

## Sample

### FurLang

```

```

### FL

```

```
