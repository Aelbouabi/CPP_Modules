NAME = PmergeMe

C = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g

SRC =  main.cpp PmergeMe.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp PmergeMe.hpp
	$(C) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(C) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean