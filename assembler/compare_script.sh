#!/bin/bash
cat $1 > test1.s | cat $1 > test2.s
./asm test1.s
./asm_orig test2.s