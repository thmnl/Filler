# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 17:13:20 by tmanuel           #+#    #+#              #
#    Updated: 2018/03/26 21:05:19 by tmanuel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tmanuel.filler

SRC =	srcs/main.c \
		srcs/ft_parsing.c \
		srcs/ft_algo.c \
		srcs/scoring.c \
		srcs/ft_cut_piece.c \
		srcs/ft_random.c \
		srcs/start_scoring.c \

OBJ = $(patsubst srcs/%.c, %.o, $(SRC))

FLAGS = -Wall -Wextra -Werror

INC = -I includes

LIB = -L libft/ -lft

ifndef ECHO
T := $(shell $(MAKE) $(MAKECMDGOALS) --no-print-directory \
	-nrRf $(firstword $(MAKEFILE_LIST)) \
	ECHO="COUNTTHIS" | grep -c "COUNTTHIS")
N := x
C = $(words $N)$(eval N := x $N)
ECHO = echo -ne "\r [`expr $C '*' 100 / $T`%]"
endif

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@make -C visu
	@tput setaf 10
	@$(ECHO) $@
	@gcc -g $(FLAGS) $(INC) -o $(NAME) $(OBJ) $(LIB)

%.o: srcs/%.c
	@gcc -c $(FLAGS) $(INC) $<
	@tput setaf 166
	@$(ECHO) $@

clean:
	@make -C libft clean
	@make -C visu clean
	@/bin/rm -f $(OBJ)
	@tput setaf 9
	@$(ECHO) clean done.

fclean: clean
	@make -C visu fclean
	@/bin/rm -f $(NAME)
	@tput setaf 9
	@$(ECHO) fclean done.

re:
	@make fclean && make

.PHONY: all clean fclean re
