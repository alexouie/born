# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almanier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/19 10:00:00 by ton_nom           #+#    #+#              #
#    Updated: 2026/01/15 13:53:36 by almanier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs


SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)


SRC_BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

bonus: $(OBJ_BONUS)
	$(AR) $(NAME) $(OBJ_BONUS)

%.o: %.c get_next_line.h get_next_line_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

