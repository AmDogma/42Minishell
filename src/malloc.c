#include "minishell.h"

void	malloc_argv(t_command *cmd, char *str)
{
	int	ac;
	int	i;

	i = 0;
	ac = 1;
	while (str[i] && str[i + 1] && str[i] != '|')
	{
		if (str[i + 1] == ' ' && ft_isprint(str[i]))
			ac++;
		i++;
	}
	cmd->argv = ft_calloc(sizeof(char *), ac + 1);
	if (cmd->argv == NULL)
		malloc_err_exit();
}

void	cmd_malloc(t_commandtable *main)
{
	if (main->cmd == NULL)
		main->cmd = ft_calloc(sizeof(t_command), main->num_of_commands + 1);
	if (main->cmd == NULL)
		malloc_err_exit();
}

char	**env_mall(const char **env)
{
	int		i;
	char	**res;

	i = 0;
	while (env + i && env[i])
		i++;
	res = (char **)malloc(sizeof(char *) * (i + 1));
	if (!res)
		malloc_err_exit();
	res[i] = NULL;
	i = 0;
	while (env[i])
	{
		res[i] = strdup(env[i]);
		if (!res[i])
			malloc_err_exit();
		i++;
	}
	return (res);
}
