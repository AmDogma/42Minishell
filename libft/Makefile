NAME	= libft.a
SRC		= $(wildcard ./*.c)
HDR		= libft.h
OBJ		= $(SRC:.c=.o)
CFLAGS	= -Wall -Werror -Wextra
CC		= gcc

all: $(NAME)

$(NAME): $(OBJ) 
	ar -rc $@ $?

$(OBJ):	$(HDR)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re