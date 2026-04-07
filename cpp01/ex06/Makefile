NAME = Harl

C = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC =   main.cpp Harl.cpp

OBJ = $(SRC:.cpp=.o)

INCLUDE = Harl.hpp

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