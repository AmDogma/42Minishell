#include "minishell.h"

int	parent_process(t_commandtable *main, t_command *some, int ret)
{
	int	status;

	close(some->input);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, inthandler_hc_p);
	waitpid(ret, &status, 0);
	main->last_exit_status = WEXITSTATUS(status);
	if (WIFEXITED(status) && main->last_exit_status == 0)
		some->input = open(some->file_name, O_RDONLY);
	else
		return (-1);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, inthandler);
	free(some->file_name);
	return (0);
}

void	child_process(char **str, char **stop_word, t_command *some)
{
	signal(SIGINT, inthandler_hc);
	while (1)
	{
		*str = readline("> ");
		if (*str == NULL)
		{
			eofhandler_hc();
			break ;
		}
		if (ft_strncmp(*str, *stop_word, ft_strlen(*stop_word)) == 0 \
			&& ft_strlen(*stop_word) == ft_strlen(*str))
			break ;
		*str = join_free(*str, "\n", str);
		write(some->input, *str, ft_strlen(*str));
		free(*str);
	}
	exit(0);
}

int	redir_heredoc(char *stop_word, t_command *some, t_commandtable *main)
{
	char	*str;
	int		ret;
	int		res;

	res = 0;
	if (some->input)
		close(some->input);
	create_name(main->curr_cmd, main->work_dir, some);
	some->input = open(some->file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (some->input == -1)
		return (printf("%s: Can't open file or directory\n", some->file_name));
	ret = fork();
	if (ret == 0)
		child_process(&str, &stop_word, some);
	else
		res = parent_process(main, some, ret);
	return (res);
}
