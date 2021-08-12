/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 20:26:58 by jovertki          #+#    #+#             */
/*   Updated: 2021/07/31 17:11:16 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <sys/stat.h>
# include <sys/wait.h>
# include <errno.h>
# include <limits.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_execute
{
	int	default_in;
	int	default_out;
	int	fdin;
	int	ret;
	int	fdout;
	int	fdpipe;
}t_execute;
typedef struct s_ft_export
{
	int		envplen;
	int		i;
	char	*name;
	int		out;
	int		j;
}	t_ft_export;

typedef struct s_command
{
	int		input;
	int		output;
	int		error;
	char	**argv;
	char	*file_name;
	int		argc;
}	t_command;

typedef struct s_commandtable
{
	int			last_exit_status;
	char		**env;
	char		*work_dir;
	char		*red_val;
	t_command	*cmd;
	int			num_of_commands;
	int			curr_cmd;
}	t_commandtable;

/*  exit_pars */
void	exit_full(char *message);
char	*clean_pipe(t_command *some, char *str, int *i);
char	*clean_all(t_commandtable *main, char *str, int *i);

/* key_env.c */
char	*key_find(char **env, char *key);
void	find_dir(t_commandtable *ct);

/* utils.c */
char	*del_one_char(char *str, int i);
char	*join_free(char const *str1, char const *str2, char **tofree);

/* doll_quotes.c */
char	*quote(char *str, int *i, t_commandtable	*main);
char	*d_quote(char *str, t_commandtable	*main, int *i);
char	*dollar(char *str, t_commandtable	*main, int *i);

/* parser */
char	*pars(char *str, t_commandtable	*main);
char	*some_space(char *str, t_commandtable *main, int *i);
int		prepars(char **str, t_commandtable	*main);

/* malloc */
void	malloc_argv(t_command *cmd, char *str);
void	cmd_malloc(t_commandtable *main);
char	**env_mall(const char **env);

/* redir */
char	*redir(char *str, t_commandtable *main, int *i);

/* redir_do */
char	*redir_act(t_command *some, t_commandtable *main, char *str, int *i);
void	create_name(int curr_cmd, char *work_dir, t_command *some);

/* redir_heredoc */
int		redir_heredoc(char *stop_word, t_command *some, t_commandtable *main);

/* jovertki */
int		pwd(void);
int		env(char **envp);
int		echo(char **str);
int		cd(char **argv, int argc, char ***envp);
int		ft_unset(int argc, char **argv, char ***envp);
int		ft_exit(int argc, char **argv);

int		ft_export(int argc, char **argv, char ***envp);
void	print_sorted_env(char **envp);
char	*find_var_name(char *str);

void	execute(t_commandtable *ct, char ***envp);
int		is_not_builtin(char *str);
int		execbuiltin(int *exit, char **argv, int argc, char ***envp);
void	redirect_input(t_execute *all, t_commandtable *ct, int i);
void	pipes_init(t_execute *all, t_commandtable *ct);

char	*find_env(char **envp, char *str, int mode);
void	search_right_bin(char **argv, char **envp, int *exit_st);
void	malloc_err_exit(void);
/* handlers */
void	inthandler(int num);
void	eofhandler(void);
void	inthandler_cd(int num);
void	quithandler_cd(int num);
void	eofhandler_hc(void);
void	inthandler_hc(int num);
void	inthandler_hc_p(int num);
void	quithandler_hc(int num);
void	inthandler_p(int num);
void	quithandler_p(int num);

void	rl_replace_line(const char *text, int clear_undo);
#endif