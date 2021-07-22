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

	char	**argv;
	int		curr_arg;
	char	**rdr_v;
	char	**rdr_t;
} t_command;

typedef struct s_commandtable
{
	char		**env;
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

/* parser */
void	pars(char *str, t_commandtable	*main);
char	*redir(char *str, t_commandtable *main, int *i);
char	*some_space(char *str, t_commandtable *main, int *i);
int		prepars(char **str, t_commandtable	*main);

/* tabs */
void	tab_cmd(t_command *cmd, char *str);
void	tab_main(t_commandtable	*main);

#endif

/*

Редиректы
here doc

Have a working History?

$? $вне ковычек




делим команды через пробелы и спецсимволы - какие спецсимволы?
*/


