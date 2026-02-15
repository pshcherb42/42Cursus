# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/04 17:57:51 by pshcherb          #+#    #+#              #
#    Updated: 2025/07/04 18:11:12 by pshcherb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Moar_brainz!

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = 	main.cpp \
		Zombie.cpp \
		zombieHorde.cpp \

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) Makefile Zombie.hpp
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re all clean fclean 