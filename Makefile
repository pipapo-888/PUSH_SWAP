# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/07 18:53:42 by knomura           #+#    #+#              #
#    Updated: 2025/09/15 16:01:39 by knomura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_push_swap.c sort_2_to_5.c instructions/push.c instructions/rotate.c instructions/reverse_rotate.c instructions/swap.c utils.c
OBJ = $(SRC:.c=.o)

LIBFT = LIBFT/libft.a
PRINTF = PRINTF/printf.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(OBJ) $(LIBFT) $(PRINTF) -o $@

$(LIBFT):
	make -C LIBFT

$(PRINTF):
	make -C PRINTF

clean:
	rm -f $(OBJ)
	make -C LIBFT clean
	make -C PRINTF clean

fclean: clean
	rm -f $(NAME)
	make -C LIBFT fclean
	make -C PRINTF fclean

re: fclean all

.PHONY: all clean fclean re bonus
