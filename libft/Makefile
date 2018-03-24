# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 17:13:20 by tmanuel           #+#    #+#              #
#    Updated: 2018/03/21 10:41:30 by tmanuel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	srcs/ft_atoi.c \
		srcs/ft_itoa.c \
		srcs/ft_bzero.c \
		srcs/ft_strequ.c \
		srcs/ft_lstmap.c \
		srcs/ft_lstnew.c \
		srcs/ft_putnbr.c \
		srcs/ft_strstr.c \
		srcs/ft_putstr.c \
		srcs/ft_strsub.c \
		srcs/ft_memchr.c \
		srcs/ft_strlen.c \
		srcs/ft_memcmp.c \
		srcs/ft_strcat.c \
		srcs/ft_strmap.c \
		srcs/ft_memcpy.c \
		srcs/ft_strchr.c \
		srcs/ft_strcmp.c \
		srcs/ft_memdel.c \
		srcs/ft_strclr.c \
		srcs/ft_lstadd.c \
		srcs/ft_memset.c \
		srcs/ft_strcpy.c \
		srcs/ft_lstdel.c \
		srcs/ft_strdel.c \
		srcs/ft_strdup.c \
		srcs/ft_strnew.c \
		srcs/ft_strrev.c \
		srcs/ft_puttab.c \
		srcs/ft_strnequ.c \
		srcs/ft_lstiter.c \
		srcs/ft_len_tab.c \
		srcs/ft_toupper.c \
		srcs/ft_striter.c \
		srcs/ft_strmapi.c \
		srcs/ft_putendl.c \
		srcs/ft_strrchr.c \
		srcs/ft_memmove.c \
		srcs/ft_strlcat.c \
		srcs/ft_isprint.c \
		srcs/ft_isalpha.c \
		srcs/ft_memccpy.c \
		srcs/ft_isascii.c \
		srcs/ft_strnstr.c \
		srcs/ft_isdigit.c \
		srcs/ft_strtrim.c \
		srcs/ft_tolower.c \
		srcs/ft_isalnum.c \
		srcs/ft_strjoin.c \
		srcs/ft_strncat.c \
		srcs/ft_strncmp.c \
		srcs/ft_strncpy.c \
		srcs/ft_putchar.c \
		srcs/ft_isblank.c \
		srcs/ft_strndup.c \
		srcs/ft_memalcpy.c \
		srcs/ft_memalloc.c \
		srcs/ft_strsplit.c \
		srcs/ft_striteri.c \
		srcs/ft_putnbr_fd.c \
		srcs/ft_puttab_fd.c \
		srcs/ft_putstr_fd.c \
		srcs/ft_swap_char.c \
		srcs/ft_lstdelone.c \
		srcs/ft_concattab.c \
		srcs/ft_putchar_fd.c \
		srcs/get_next_line.c \
		srcs/ft_putendl_fd.c \
		srcs/ft_strjoin_free.c \
		srcs/ft_split_whitespaces.c \
		srcs/ft_strlen_until_char.c \
		srcs/ft_printf.c \
		srcs/ft_check_fmt.c \
		srcs/buffer.c \
		srcs/ft_find_flag.c \
		srcs/ft_print_error.c \
		srcs/ft_printf_putchar.c \
		srcs/ft_type.c \
		srcs/ft_putchar_uni.c \
		srcs/ft_putchar_uni2.c \
		srcs/ft_printf_string.c \
		srcs/ft_printf_stringuni.c \
		srcs/ft_printf_stringuni2.c \
		srcs/ft_printf_nbr.c \
		srcs/ft_printf_nbr_tools.c \
		srcs/ft_printf_base.c \
		srcs/ft_printf_base_tools.c \

OBJ = $(patsubst srcs/%.c, %.o, $(SRC))

FLAGS = -Wall -Wextra -Werror

INC = -I includes

define ISOK
@echo -n $1
@echo '           [OK]'
@tput sgr0
endef

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
	@tput setaf 10
	@$(ECHO) $@
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: srcs/%.c
	@gcc -c $(FLAGS) $(INC) $<
	@tput setaf 10
	@$(ECHO) $@

clean:
	@/bin/rm -f $(OBJ)
	@tput setaf 9
	@$(ECHO) clean done.

fclean: clean
	@/bin/rm -f $(NAME)
	@tput setaf 9
	@$(ECHO) fclean done.

re:
	@make fclean && make

.PHONY: all clean fclean re
