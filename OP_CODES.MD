# OP_CODES

This page will describe the OP_CODE that FurLang will use, It's very simillar to C#'s OP_CODE

## TODO

* Add ARRAY
* Add more OP_CODE

## Specification

```
~blep~ ALL NUMBER START AT 0
~blep~ ARGS, VAR, FUNCTION and RESULT have different offset
~blep~ ARGS = ARR[4096], VAR = ARR[4096], FUNCTION = ARR[4096], RESULT = ARR[4096], STACK = ARR[4096]

LD_ARGS N ~blep~ Push ARGS[N] to STACK
LD_VAR N ~belp~ Push VAR[N] to STACK
LD_RESULT N ~blep~ Push RESULT[N] to STACK

SET_VAR N ~blep~ Set the VAR[N] to STACK[0]

CALL N ~blep~ Call FUNCTION[N], clear RESULT and set the result of the function to RESULT
CLEAR N ~blep~ Clear the data by type, 0 - ARGS, 1 - VAR, 2 - FUNCTION, 3 - RESULT and 4 - STACK
MOVE_TO N ~blep~ Move the STACK[0] to VAR[N]
MOVE_ALL_TO N ~blep~ Move the entire stack to VAR[N]

ADD ~blep~ Add STACK[0] and STACK[1], clear RESULT and set RESULT[0] to the result, and pop the first two element of the STACK
REMOVE ~blep~ Same as ADD but this time it's remove
MULTIPY ~blep~ Same as ADD but this time it's multipy
DIVIDE ~blep~ Same as ADD but this time it's divide
MODULO ~blep~ Same as ADD but this time it's modulo

SET S ~blep~ Set STACK[0] to S
SET_PUSH S ~blep~ Push S to STACK

IF_FALSE N ~blep~ if STACK[0] is false, jump to offset N
IF_TRUE N ~blep~ Same as IF_FALSE but instead of FALSE, it's TRUE

EQU ~blep~ If STACK[0] is equal to STACK[1] then set RESULT[0] to 1, else set RESULT[0] to 0

RET ~blep~ Return the value in the STACK[0]
RET_ALL ~blep~ Return all of the stack as the value
```

## Sample

* BOTH OF THIS ARE PSEUDOCODE AND MAY/MAY NOT WORK

### FurLang

```
~blep~ Entry point
int hewwo[] {
  You = "Cutie"
  if [ You != "Cutie" ] bark 1
  bark 0
}
```

### FL

```
0001 SET "Cutie"
0002 SET_VAR 0
0003 SET_RAW "Cutie"
0004 LD_VAR 0
0005 EQU
0006 CLEAR 4
0007 LD_RESULT 0
0008 IF_FALSE 0011
0009 SET 1
0010 RET
0011 SET 0
0012 RET
```
