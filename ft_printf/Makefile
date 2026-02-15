# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pshcherb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 15:24:15 by pshcherb          #+#    #+#              #
#    Updated: 2024/10/01 15:51:11 by pshcherb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_printf_utils.c

OBJS = $(SRCS:.c=.o)

DEPS = $(SRCS:.c=.d)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	
%.o: %.c Makefile
	$(CC) $(CFLAGS) -MMD -c $< -o $@

clean:
	rm -f $(OBJS) $(DEPS)
	
fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)
