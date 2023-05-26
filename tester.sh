#!/bin/bash
make
cc -o tester src/test.c -lm -L. -lftprintf
echo
echo -------------begin ft_printf tester-------------------------------
echo
./tester $1
echo
echo -------------end ft_printf tester---------------------------------
echo
rm -f tester
