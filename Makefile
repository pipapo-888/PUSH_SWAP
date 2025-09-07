# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/07 18:53:42 by knomura           #+#    #+#              #
#    Updated: 2025/09/07 19:05:21 by knomura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
# CFLAGS = -Wall -Wextra -Werror

SRC = ft_push_swap.c push.c reverse_rotate.c rotate.c sort_2_to_5.c swap.c utils.c
OBJ = $(SRC:.c=.o)
ARC = libft.a printf.a

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -L $(ARC) -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ) .bonus

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
