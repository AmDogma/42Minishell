#include "minishell.h"

int	redir_append(char *file, t_command *some)
{
	if (some->output)
		close(some->output);
	some->output = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (some->output == -1)
		return (printf("%s: No such file or directory\n", file));
	return (0);
}

int	redir_trunc(char *file, t_command *some)
{
	if (some->output)
		close(some->output);
	some->output = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (some->output == -1)
		return (printf("%s: No such file or directory\n", file));
	return (0);
}

int	redir_read(char *file, t_command *some)
{
	if (some->input)
		close(some->input);
	some->input = open(file, O_RDONLY);
	if (some->input == -1)
		return (printf("%s: No such file or directory\n", file));
	return (0);
}

void	create_name(int curr_cmd, char *work_dir, t_command *some)
{
	char	*file;

	file = ft_itoa(curr_cmd);
	if (!file)
		malloc_err_exit();
	some->file_name = join_free(work_dir, "temp_files/temp", NULL);
	some->file_name = join_free(some->file_name, file, &(some->file_name));
	free(file);
}

char	*redir_act(t_command *some, t_commandtable *main, char *str, int *i)
{
	int	res;

	res = 0;
	if (main->red_val[0] == '1')
		res = redir_read(main->red_val + 1, some);
	else if (main->red_val[0] == '2')
		res = redir_heredoc(main->red_val + 1, some, main);
	else if (main->red_val[0] == '3')
		res = redir_trunc(main->red_val + 1, some);
	else if (main->red_val[0] == '4')
		res = redir_append(main->red_val + 1, some);
	if (res == -1)
		str = clean_all(main, str, i);
	else if (res)
		str = clean_pipe(some, str, i);
	return (str);
}
