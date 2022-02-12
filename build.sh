#!/bin/sh

nasm -felf64 test/test.asm
ld -o test/test test/test.o