# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inunez-g <inunez-g@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 09:45:23 by inunez-g          #+#    #+#              #
#    Updated: 2021/12/20 10:12:31 by inunez-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC =   push_swap.c\
		push_swap_moves1.c\
		push_swap_moves2.c\
		push_swap_moves3.c\
		push_swap_utils.c\
		push_swap_push.c\
		push_swap_miniutils.c\

CC =	gcc

CFLAGS =	-Werror -Wextra -Wall -g -fsanitize=address

LIB2 =	libft/libft.a

INCLUDES = push_swap.h

all: $(NAME)

$(NAME):    $(SRC) $(LIB2)
	$(CC) $(CFLAGS) -I$(LIB2) $^ -o $(NAME)

$(LIB2): libft/*.c
	$(MAKE) -C libft/
	$(MAKE) -C libft/ bonus

all: $(NAME)

clean:
	$(MAKE) -C Libft/ clean

fclean: clean
	rm -rf $(LIB2)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
