NAME = Serializer

C = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC =   main.cpp Serializer.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp Serializer.hpp
	$(C) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(C) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean