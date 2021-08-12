#include "minishell.h"

void	free_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		free(envp[i]);
		i++;
	}
	free(envp);
}

void	free_cmd(t_commandtable *ct)
{
	int	i;
	int	j;

	i = 0;
	while (i < ct->num_of_commands)
	{
		j = 0;
		while (j < ct->cmd[i].argc)
		{
			free(ct->cmd[i].argv[j]);
			j++;
		}
		free(ct->cmd[i].argv);
		i++;
	}
	free(ct->cmd);
}

void	free_ct(t_commandtable *ct)
{
	free_cmd(ct);
	ct->num_of_commands = 1;
	ct->curr_cmd = 0;
	ct->red_val = NULL;
	ct->cmd = NULL;
}

static void	execute_all(char **str, t_commandtable	*ct)
{
	if ((*str)[0] != '\0')
		add_history(*str);
	if (!prepars(str, ct))
		*str = pars(*str, ct);
	if (ct->cmd != NULL)
		execute(ct, &ct->env);
	else
		ct->num_of_commands = 0;
}

int	main(int argc, char **argv, const char **envp)
{
	char			*str;
	t_commandtable	ct;

	ft_bzero(&ct, sizeof(t_commandtable));
	ct.env = env_mall(envp);
	find_dir(&ct);
	argv = (char **)argv;
	if (argc != 1)
		exit_full("Error: ./minishell with arguments.\n");
	ct.num_of_commands = 1;
	signal(SIGINT, inthandler);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		str = readline("minishell$ ");
		if (str == NULL)
			eofhandler();
		execute_all(&str, &ct);
		free_ct(&ct);
		free(str);
	}
	free_env(ct.env);
}

/* system("leaks minishell"); */