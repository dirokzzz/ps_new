#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcolossu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/11 20:49:09 by bcolossu          #+#    #+#              #
#    Updated: 2019/11/21 19:42:55 by rczarfun         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = push_swap
CC = gcc
FLAGS = -g -Wall -Wextra -Werror
INC = checker.h
SRC =	main.c\
		sort_little2.c\
		operations1.c\
		operations2.c\
		pars_check_args.c\
		stack_op.c\
		sort_big.c\
		sort_big2.c\
		sort_little.c\
		free.c\
		find_num.c\

OBJ = $(SRC:c=o)


all: $(NAME)

$(NAME): $(OBJ)
	@make -C .././libft
	$(CC) $(FLAGS) -I$(INC) ../libft/libftprintf.a $(OBJ) -o ../$(NAME)
	

%.o : %.c $(INC)
	$(CC) $(FLAGS) -I$(INC) -o $@ -c $<

clean:
	@$(MAKE) -C ../libft/ clean
	@/bin/rm -f *.o

fclean: clean
	@$(MAKE) -C ../libft/ fclean
	@/bin/rm -f $(NAME)

re: fclean all
