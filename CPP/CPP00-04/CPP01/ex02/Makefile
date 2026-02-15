# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/04 20:02:27 by pshcherb          #+#    #+#              #
#    Updated: 2025/07/04 20:10:22 by pshcherb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = HI_THIS_IS_BRAIN

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): main.o
	$(CXX) $(CXXFLAGS) main.o -o $(NAME)

main.o: main.cpp Makefile
	$(CXX) $(CXXFLAGS) -c main.cpp

clean: 
	rm -f main.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re all fclean clean