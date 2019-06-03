CC = clang++
CFLAGS  = -Wall -Werror -Wextra

SRC = phonebook.cpp\
			Contacts.cpp
OBJ_DIR = obj
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

INC = Contacts.hpp

NAME = phonebook

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(OBJ): $(SRC)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(SRC) -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm $(NAME)

all: fclean $(NAME)