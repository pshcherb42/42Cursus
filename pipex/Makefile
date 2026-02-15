# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 18:45:27 by pshcherb          #+#    #+#              #
#    Updated: 2025/03/14 11:38:10 by pshcherb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
SRCS = src/main.c\
		src/parsing.c\
		src/utils.c\
		src/here_doc_utils.c\

LIBFT = libft/libft.a

OBJS = $(SRCS:.c=.o)

DEPS = $(SRCS:.c=.d)

all: $(NAME)

$(NAME): Makefile $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

-include $(DEPS)

%.o: %.c
	$(CC) $(CFLAGS) -MMD -c $< -o $@

$(LIBFT):
	make -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

clean:
	rm -f $(OBJS) $(DEPS)
	make clean -C libft

re: fclean all

.PHONY: all clean fclean re
