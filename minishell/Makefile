NAME = minishell
CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS =	main.c utils.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -fsanitize=address -lreadline -L /Users/$(USER)/.brew/opt/readline/lib -I/Users/$(USER)/.brew/opt/readline/include

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I .

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
