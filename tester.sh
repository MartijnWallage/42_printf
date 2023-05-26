#!/bin/bash
make
cc -o tester src/test.c -lm -L. -lftprintf
GREEN='\033[0;32m'
NO_COLOR='\033[0m'
echo
echo -e "${GREEN}------------begin ft_printf tester-------------------------------${NO_COLOR}"
echo
./tester $1
echo
echo -e "${GREEN}------------end ft_printf tester---------------------------------${NO_COLOR}"
echo
rm -f tester
