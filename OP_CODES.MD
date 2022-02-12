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

LD_ARGS N ~blep~ Load args number N from the function to the STACK and push everything else by 1
LD_VAR N ~belp~ Load variable at offset N to the STACK and push everything else by 1
LD_RESULT N ~blep~ Load the result of a function at N offset to the STACK and push everything else by 1

SET_POINTER_TYPE N ~blep~ Set the pointer to specific array where 0 - ARGS, 1 - VAR, 2 - FUNCTION, 3 - RESULT and 4 - STACK
SET_POINTER_OFFSET N ~blep~ Set the pointer's offset to N

CALL N ~blep~ Load function from offset N, It will store the value in RESULT stack, Clearing previous RESULT stack
CLEAR N ~blep~ Clear the data by type, 0 - ARGS, 1 - VAR, 2 - FUNCTION, 3 - RESULT and 4 - STACK
MOVE_TO N ~blep~ Move the STACK[0] to VAR[N]
MOVE_ALL_TO N ~blep~ Move the entire stack to VAR[N]

ADD ~blep~ Add STACK[0] and STACK[1], clear RESULT and set RESULT[0] to the result, and pop the first two element of the STACK
REMOVE ~blep~ Same as ADD but this time it's remove
MULTIPY ~blep~ Same as ADD but this time it's multipy
DIVIDE ~blep~ Same as ADD but this time it's divide
MODULO ~blep~ Same as ADD but this time it's modulo

SET ~blep~ Set the POINTER_TYPE[POINTER_OFFSET] to STACK[0]
SETALL ~blep~ Set the POINTER_TYPE[POINTER_OFFSET] to STACK

SET_RAW S ~blep~ Same as SET but instead of STACK[0], it's S where S can be anything

IF_FALSE N ~blep~ if STACK[0] is false, jump to offset N
IF_TRUE N ~blep~ Same as IF_FALSE but instead of FALSE, it's TRUE

EQU ~blep~ If STACK[0] is equal to STACK[1] then set RESULT[0] to 1, else set RESULT[0] to 0

RET ~blep~ Return the value in the STACK[0]
RET_ALL ~blep~ Reutrn all of the stack as the value
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
0001 SET_POINTER_TYPE 2
0002 SET_POINTER_OFFSET 0
0003 SET_RAW "Cutie"
0004 SET_POINTER_TYPE 4
0005 SET_RAW "Cutie"
0006 LD_VAR 0
0007 EQU
0008 CLEAR 4
0009 LD_RESULT 0
0010 IF_FALSE 0013
0011 SET_RAW 1
0012 RET
0013 SET_RAW 0
0014 RET
```
