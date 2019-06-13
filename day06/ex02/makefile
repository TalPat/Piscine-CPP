NAME		=	ex02
SRCDIR		=	./
SRC			=	main.cpp\
					Base.cpp\
					A.cpp\
					B.cpp\
					C.cpp
SRCPATH		:=	$(addprefix $(SRCDIR), $(SRC))
OBJDIR		=	obj/
OBJ			=	$(SRC:%.cpp=%.o)
OBJPATH		:=	$(addprefix $(OBJDIR), $(OBJ))

HEADER		=	./
CFLAGS		=	-Wall -Werror -Wextra -std=c++98
CC			=	clang++
INCLUDES	=	-I $(HEADER)

all: $(NAME)

$(NAME): $(OBJPATH)
	$(CC) -o $(NAME) $(SRCPATH) $(INCLUDES) $(CFLAGS)

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

clean:
	rm -rf $(OBJPATH)

fclean:	clean
	rm -rf $(NAME)

re: fclean all