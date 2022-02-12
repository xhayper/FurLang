# OP_CODES

This page will describe the OP_CODE that FurLang will use, It's very simillar to C#'s OP_CODE

## Specification

```
~blep~ ALL NUMBER START AT 0
~blep~ ARGS, VAR, FUNCTION have different offset

LD_ARGS N ~blep~ Load args number N from the function
LD_VAR N ~belp~ Load variable at offset N, This mean you can have duplicate variable name if you use raw OP_CODE
LD_RESULT N ~blep~ Load the result of a function at N offset (if function return more than 1 value)

CALL N ~blep~ Load function from offset N, It will store the value in RESULT stack, Clearing previous RESULT stack
```
