# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/26 21:11:50 by tmanuel           #+#    #+#              #
#    Updated: 2018/03/26 20:10:42 by tmanuel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler_visu

SRC =	srcs/main.c \
		srcs/parsing.c \
		srcs/ft_print.c \
		srcs/ft_pixel_put.c \
		srcs/ft_music.c \

OBJ = $(patsubst srcs/%.c, %.o, $(SRC))

FLAGS = -Wall -Wextra -Werror

INC = -I includes

LIB =  -L libft/ -lft

LIBX = -L minilibx_macos -lmlx -framework OpenGL -framework AppKit

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
	@make -C libft/
	@gcc -c -g $(FLAGS) $(INC) $(SRC)
	@gcc -g $(FLAGS) $(INC) -o $(NAME) $(OBJ) $(LIB) $(LIBX)

%.o: srcs/%.c
	@gcc -c $(FLAGS) $(INC) $<
	@tput setaf 142
	@$(ECHO) $@

clean:
	@/bin/rm -f $(OBJ)
	@tput setaf 9
	@make -C libft/ clean
	@$(ECHO) clean done.

fclean: clean
	@/bin/rm -f $(NAME)
	@tput setaf 9
	@$(ECHO) fclean done.
	@make -C libft/ fclean

re:
	@make fclean && make

.PHONY: all clean fclean re
