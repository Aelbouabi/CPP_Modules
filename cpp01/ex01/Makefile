NAME = horde

C = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC =  Zombie.cpp zombieHorde.cpp main.cpp

INCLUDE = Zombie.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp $(INCLUDE)
	$(C) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(C) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean