# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/03 18:07:51 by pshcherb          #+#    #+#              #
#    Updated: 2025/07/03 19:12:01 by pshcherb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=BraiiiiiiinnnzzzZ

SRCS = 	main.cpp \
		newZombie.cpp \
		Zombie.cpp \
		randomChump.cpp \

OBJS = $(SRCS:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS) Makefile Zombie.hpp
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) 

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

re: fclean all

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

.PHONY: re clean fclean all