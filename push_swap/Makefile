# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/27 20:09:36 by pshcherb          #+#    #+#              #
#    Updated: 2025/01/30 18:46:09 by pshcherb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc 
RM = rm -f
FLAGS = -Wall -Wextra -Werror -g
LIBFTDIR = libft/
FT_PRINTFDIR = printf/
OBJ_DIR = obj/
SRC_DIR = src/

SRC_1 = srcs/push_swap/push_swap.c \
		srcs/push_swap/init_stack.c \
		srcs/push_swap/ft_checksorted.c \
		srcs/push_swap/ft_sort.c \
		srcs/push_swap/ft_sort_small.c \

SRC_2 = srcs/utils/operations.c \
		srcs/utils/max_bits.c \
		srcs/utils/ft_free_stack.c \
		srcs/utils/find_last_node.c \
		srcs/utils/error_syntax.c \
		srcs/utils/ft_atoi2.c \
		srcs/utils/sort_utils.c \
		srcs/utils/pos_max_min.c \

OBJ_1 = ${SRC_1:.c=.o}
OBJ_2 = ${SRC_2:.c=.o}

INCLUDE = -L ./libft -lft -L ./printf -lftprintf

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ_1} ${OBJ_2}
	make -C ./libft
	make -C ./printf
	${CC} ${FLAGS} ${OBJ_1} ${OBJ_2} -o ${NAME} ${INCLUDE} 
all: ${NAME}

clean:	
	${RM} ${OBJ_1} ${OBJ_2} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) clean
	@cd $(FT_PRINTFDIR) && $(MAKE) clean

fclean:	clean
	${RM} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) clean
	@cd $(FT_PRINTFDIR) && $(MAKE) clean

re: clean all

.PHONY: all clean fclean re 
