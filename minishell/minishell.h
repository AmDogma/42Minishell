#ifndef minishell_h
#define minishell_h

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "/Users/mdewayne/Desktop/pool/libc/libft/libft/libft.h" // need to change
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <limits.h>

typedef struct s_command
{
	int		input;
	int		output;
	int		error;
	char	**argv;
	char	**rdr_v;
	char	**rdr_t;
	int		argc;
	int		curr_arg;
} t_command;

typedef struct s_commandtable
{
	char		*str;  // ?
	char		**env;
	int			p_str; // ?
	int			fd_in;
	int			fd_out;
//	char *errfile;
	t_command	*cmd;
	int			comm_num;
	int			curr_cmd;

} t_commandtable;

/* key_env.c */
char	**join_char(char **join, char *add);
char	*key_find(char **env, char *key); // не нужно чистить
char	**env_mall(char **env);

/* utils.c */
char	*del_one_char(char *str, int i);
char	*join_free(char const *str1, char const *str2, char **tofree); // можно убрать третий параметр и всегда освобождать первый/второй...

/* doll_quotes.c */
char	*quote(char *str, int *i);
char	*d_quote(char *str, t_commandtable	*main, int *i);
char	*dollar(char *str, t_commandtable	*main, int *i);

#endif

/*

Редиректы
here doc

$? $вне ковычек
делим команды через пробелы и спецсимволы - какие спецсимволы?


Have a working History.
Not interpret unclosed quotes or unspecified special characters like \
*/
