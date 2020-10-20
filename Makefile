NAME_push = push_swap
NAME_checker = checker

ifndef VERBOSE
MAKEFLAGS += --no-print-directory
endif

SRCS_PATH = src/
OBJ_PATH  = obj/
LIBFT_PATH = libft/

FLAGS = -Wall -Werror -Wextra
INC = -I ./includes/ -I ./$(LIBFT_PATH)includes/

SRCS_NAME = sort_little2.c\
		operations1.c\
		operations2.c\
		pars_check_args.c\
		stack_op.c\
		sort_big.c\
		sort_big2.c\
		sort_little.c\
		init_and_free.c\
		find_num.c\
		get_rule_check.c\
		check_args.c\
		print.c

SRCS_CHECKER = checker.c $(SRCS_NAME)

SRCS_PUSH = push_swap.c $(SRCS_NAME)

SRCS_CHECKER_FULL = $(addprefix $(SRCS_PATH), $(SRCS_CHECKER))
SRCS_PUSH_FULL = $(addprefix $(SRCS_PATH), $(SRCS_PUSH))
OBJ_CHECKER = $(addprefix $(OBJ_PATH), $(SRCS_CHECKER:.c=.o))
OBJ_PUSH = $(addprefix $(OBJ_PATH), $(SRCS_PUSH:.c=.o))

all: $(NAME_checker) $(NAME_push)

$(NAME_push) : $(OBJ_PUSH)
	@make -w -C $(LIBFT_PATH)
	@echo "\033[33m$(LIBFT_PATH)\033[0m compiled."
	@gcc $(FLAGS) $(OBJ_PUSH) $(INC) -L $(LIBFT_PATH) -lftprintf -o $(NAME_push)
	@echo "\033[32m$(NAME_push)\033[0m created."

$(NAME_checker): $(OBJ_CHECKER)
	@make -w -C $(LIBFT_PATH)
	@echo "\033[33m$(LIBFT_PATH)\033[0m compiled."
	@gcc $(FLAGS) $(OBJ_CHECKER) $(INC) -L $(LIBFT_PATH) -lftprintf -o $(NAME_checker)
	@echo "\033[32m$(NAME_checker)\033[0m created."

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p obj
	@gcc -c $(FLAGS) $(INC) $< -o $@

clean:
	@make -w -C $(LIBFT_PATH)/ clean
	@/bin/rm -rf $(OBJ_PATH)

fclean: clean
	@make -w -C $(LIBFT_PATH)/ fclean
	@/bin/rm -rf $(NAME_checker)

re: fclean all

.PHONY: all, clean, fclean, re