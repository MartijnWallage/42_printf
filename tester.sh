#!/bin/bash
make
cc -o tester src/test.c -L. -lftprintf
echo
echo -------------begin ft_printf tester-------------------------------
echo
./tester
echo
echo -------------end ft_printf tester---------------------------------
echo
make fclean
rm -f tester
