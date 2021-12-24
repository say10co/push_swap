# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adriouic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 23:09:51 by adriouic          #+#    #+#              #
#    Updated: 2021/12/24 15:16:02 by adriouic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = utils/actions.c utils/basic_.c utils/errors.c utils/pswap_funcs.c \
		utils/push_swap_utils.c utils/sort_utils.c 

CFILES = cheker_src/get_next_line.c cheker_src/get_next_line_utils.c checker.c

objs	=	${FILES:.c=.o}

cobjs	=	${CFILES:.c=.o}

NAME	=	push_swap

FLAGS		=	-Wall -Werror -Wextra

all: PRINT $(NAME)

PRINT:
	@echo  "\n\033[0;33m Compiling Push_swap Utils..." "\n\033[1;32m"

%.o: %.c
	cc $(FLAGS) -c $< -o  ${<:.c=.o}


$(NAME) : $(objs) $(cobjs) push_swap.o LIB
	@echo "\n\033[0;33m Linking push_swap...Done" "\033[1;32m"
	@cc $(objs) push_swap.o -L./libft -lft -o $(NAME)
	@echo  "\n\033[0;33m Linking checker...Done" "\033[1;32m"
	@cc $(cobjs) $(objs) -L./libft -lft -o checker

LIB :
	@echo  "\n\033[0;33m Compiling Libft..."
	@echo  "\033[1;32m"
	make -C ./libft 
	@echo "\n\033[0;33m Compiling Libft Bonus..."
	@echo  "\033[1;32m"
	make bonus -C ./libft 

clean: libclean
	@echo  "\n\033[0;33m Deleting Object Files..."
	@echo  "\033[0;31m"
	#make clean -C ./libft
	rm -f $(objs)
	rm -f $(cobjs)
	rm -f push_swap.o

fclean: clean libclean
	rm -f push_swap
	rm -f checker
	rm -f ./libft/libft.a

libclean:
	make clean -C libft

re: fclean all

.PHONY: fclean clean re all
