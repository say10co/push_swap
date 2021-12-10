gcc -Wall -Werror -Wextra -c push_swap.c actions.c
gcc  push_swap.o actions.o -L. -lft -o push_swap
rm *.o
