NAME=animal

SRCS = 	main.cpp \
		Animal.cpp \
		Cat.cpp \
		Dog.cpp \
		WrongCat.cpp \
		WrongAnimal.cpp \

OBJS = $(SRCS:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 

all: $(NAME)

$(NAME): $(OBJS) Makefile Animal.hpp Dog.hpp Cat.hpp WrongCat.hpp WrongAnimal.hpp
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) 

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

re: fclean all

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

.PHONY: re clean fclean all