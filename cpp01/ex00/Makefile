NAME = zombie

C = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC =  Zombie.cpp randomChump.cpp newZombie.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp Zombie.hpp
	$(C) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(C) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean