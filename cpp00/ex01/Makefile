NAME = phonebook

C = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = phonebook.cpp contact.cpp main.cpp

INCLUDE = phonebook.hpp
INCLUDE2 = contact.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp $(INCLUDE) $(INCLUDE2)
	$(C) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ) 
	$(C) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean