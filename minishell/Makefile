NAME	= minishell
SRC		= $(wildcard src/*.c)
HDR		= $(wildcard src/*.h)
OBJ		= $(patsubst src/%.c, obj/%.o,$(SRC))
LIB		= libft/libft.a
LIBHDR	= libft/libft.h
CFLAGS	= -g
CC		= gcc
RDLN	= -lreadline -L /Users/$(USER)/.brew/opt/readline/lib -I/Users/$(USER)/.brew/opt/readline/include

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) $(RDLN) -o $(NAME)

obj/%.o: src/%.c $(HDR) $(LIB)
	mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB):
	$(MAKE) -C libft

clean:
	$(RM) $(OBJ)
	rmdir obj
	$(MAKE) clean -C libft

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C libft

re: fclean all

.PHONY: all clean fclean re
