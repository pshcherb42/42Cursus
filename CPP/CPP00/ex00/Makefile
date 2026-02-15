# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/26 12:51:51 by pshcherb          #+#    #+#              #
#    Updated: 2025/06/26 14:35:27 by pshcherb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Megaphone

all: $(NAME)

Megaphone: ex00.o
	c++ -Wall -Wextra -Werror ex00.o -o $(NAME) -std=c++98

ex00.o: ex00.cpp Makefile
	c++ -Wall -Wextra -Werror -c ex00.cpp -std=c++98

clean:
	rm -f ex00.o
	
fclean:
	rm -f ex00.o $(NAME)

re: fclean all

.PHONY: all clean fclean re