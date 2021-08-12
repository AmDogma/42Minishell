#include "minishell.h"

void	exit_full(char *message)
{
	printf("%s\n", message);
	exit (0);
}

char	*clean_pipe(t_command *some, char *str, int *i)
{
	int	count;

	count = 0;
	if (some->argv)
	{
		while (some->argv + count && some->argv[count])
			free(some->argv[count++]);
		free(some->argv);
		some->argv = NULL;
	}	
	some->argv = NULL;
	while (str + *i && str[*i] != '\0')
	{
		if (str[*i] == '|')
			break ;
		(*i)++;
	}
	str = join_free(str + *i, NULL, &str);
	*i = 0;
	return (str);
}

char	*clean_all(t_commandtable *main, char *str, int *i)
{
	while (main->curr_cmd + 1)
	{
		str = clean_pipe(main->cmd + main->curr_cmd, str, i);
		main->curr_cmd--;
	}
	main->curr_cmd = 0;
	free(main->cmd);
	main->cmd = NULL;
	str = join_free("", NULL, &str);
	*i = 0;
	return (str);
}
