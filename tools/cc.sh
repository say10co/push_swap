#!/bin/bash
clear
gcc -Wall -Werror -Wextra -c push_swap.c ./utils/*.c 
#actions.c push_swap_utils.c
#gcc  push_swap.o actions.o push_swap_utils.o -L. -lft -o push_swap
gcc  *.o -L. -lft -o push_swap
rm *.o
echo "Runig /usr/local/bin/python3 random1.py"
var=$(/usr/local/bin/python3 ./tools/random1.py)
echo "Random numbers : "
echo $var
echo "Runing ./push_swap.py"
./push_swap $var
