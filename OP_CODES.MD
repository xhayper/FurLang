# OP_CODES

This page will describe the OP_CODE that FurLang will use

| OP    | 1    | 2  | 3  | Comment                                                                                                                                 |
|-------|------|----|----|-----------------------------------------------------------------------------------------------------------------------------------------|
| COPY  | r1/d | r2 |    | Copy data from register 1 to register 2                                                                                                 |
| JUMP  | r/d  |    |    | Jumps to a value in register or data                                                                                                    |
| JUMPR | r/d  |    |    | jumps relative to the value in register or data (basically takes the current line, adds the value in register or data, and jumps there) |
| ADD   | r1   | r2 | r3 | Add register 1 and register 2 and save it to register 3                                                                                 |
| ADDI  | r1   | d  |    | Same as ADD, but instead of register 2, you provide the data                                                                            |
| SUB   | r1   | r2 |    | Same as ADD, but instead of adding, it's subtracting                                                                                    |
| SUBI  | r1   | d  |    | Same as ADDI, but instead of adding, it's subtracting                                                                                   |
| MUL   | r1   | r2 |    | Same as ADD, but instead of adding, it's multipying                                                                                     |
| MULI  | r1   | d  |    | Same as ADDI, but instead of adding, it's multipying                                                                                    |
| DIV   | r1   | r2 |    | Same as ADD, but instead of adding, it's dividing                                                                                       |
| DIVI  | r1   | d  |    | Same as ADDI, but instead of adding it's dividing                                                                                       |
| MOD   | r1   | r2 |    | Same as ADD, but instead of adding, it's modulo                                                                                         |
| MODI  | r1   | d  |    | Same as ADDI, but instead of adding, it's modulo                                                                                        |
