#ifndef minishell_h
#define minishell_h

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "/Users/mdewayne/Desktop/pool/libc/libft/libft/libft.h" // need to change
# include <readline/readline.h>
# include <readline/history.h>

/* key_path_find.c */
char	**join_char(char **join, char *add);
char	*key_find(char **env, char *key); // не нужно чистить
char	**path_pars(char **env);

/* utils.c */
char	*del_one_char(char *str, int i);
char	*join_free(char const *str1, char const *str2, char **tofree); // можно убрать третий параметр и всегда освобождать первый/второй...

/* doll_quotes.c */
char	*quote(char *str, int *i);
char	*d_quote(char *str, int *i);
char	*dollar(char *str, char **env, int *i);

#endif
