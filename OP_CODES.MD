# OP_CODES

This page will describe the OP_CODE that FurLang will use, It's very simillar to C#'s OP_CODE

## Specification

```
~blep~ ALL NUMBER START AT 0
~blep~ ARGS, VAR, FUNCTION and RESULT have different offset
~blep~ ARGS = ARR[256], VAR = ARR[256], FUNCTION = ARR[256], RESULT = ARR[256], STACK = ARR[256]

LD_ARGS N ~blep~ Load args number N from the function to the STACK
LD_VAR N ~belp~ Load variable at offset N to the STACK
LD_RESULT N ~blep~ Load the result of a function at N offset to the STACK

CALL N ~blep~ Load function from offset N, It will store the value in RESULT stack, Clearing previous RESULT stack
CLEAR N ~blep~ Clear the stack by type, 1 - ARGS, 2 - VAR, 3 - FUNCTION, 4 - RESULT and 5 - STACK

RET ~blep~ Return the value in the STACK
```
