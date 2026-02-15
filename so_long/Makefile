# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/18 18:00:47 by pshcherb          #+#    #+#              #
#    Updated: 2025/02/16 15:06:46 by pshcherb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast
LIBMLX = MLX42

LIBFT_DIR = libft
PRINTF_DIR = ft_printf

HEADERS = -I ./inc -I $(LIBMLX)/include/MLX42/MLX42.h -I $(LIBFT_DIR) $(PRINTF_DIR)

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a


LIBS = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm $(LIBFT) $(PRINTF)

SRCS :=	$(shell find ./src -iname "*.c")
OBJS := ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF) $(LIBMLX)/build/libmlx42.a Makefile
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -MMD -c $< -o $@ $(HEADERS)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

$(LIBMLX)/build/libmlx42.a:
	cmake -B $(LIBMLX)/build -S $(LIBMLX) > /dev/null
	cmake --build $(LIBMLX)/build --target mlx42 > /dev/null

clean:
	rm -rf $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean
	rm -rf $(LIBMLX)/build

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus
