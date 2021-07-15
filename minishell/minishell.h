#ifndef minishell_h
#define minishell_h

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "/Users/mdewayne/Desktop/pool/libc/libft/libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

char	*join_free(char const *str1, char const *str2, char **tofree); // можно убрать третий параметр и всегда освобождать первый...
char	*del_one(char *str, int *i);
#endif
