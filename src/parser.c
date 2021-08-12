#include "minishell.h"

int	prepars(char **str, t_commandtable	*main)
{
	int		i;
	char	c;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == '\'' || (*str)[i] == '\"')
		{
			c = (*str)[i];
			while (c != (*str)[++i])
				if (!(*str)[i])
					return (printf("ERROR: Need to close - %c\n", c));
		}
		else if ((*str)[i] == '$')
			*str = dollar(*str, main, &i);
		else if ((*str)[i] == '|')
			main->num_of_commands += 1;
		if (i >= INT_MAX)
			return (printf("Argument length is out of int\n"));
		i++;
	}
	return (0);
}

char	*some_space(char *str, t_commandtable *main, int *i)
{
	t_command	*some;

	if (*i == 0)
		return (del_one_char(str, *i));
	cmd_malloc(main);
	some = main->cmd + main->curr_cmd;
	if (some->argc == 0)
		malloc_argv(some, str);
	some->argv[some->argc] = ft_substr(str, 0, *i);
	if (some->argv[some->argc] == NULL)
		malloc_err_exit();
	some->argc += 1;
	str = join_free(str + *i, NULL, &str);
	*i = 0;
	return (str);
}

char	*pars(char *str, t_commandtable *main)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			str = quote(str, &i, main);
		else if (str[i] == '\"')
			str = d_quote(str, main, &i);
		else if (str[i] == ' ' || (i && (str[i] == '|'
					|| str[i] == '<' || str[i] == '>')))
			str = some_space(str, main, &i);
		else if (str[i] == '|')
		{
			str = del_one_char(str, i);
			main->curr_cmd += 1;
		}
		else if (str[i] == '<' || str[i] == '>')
			str = redir(str, main, &i);
		else
			i++;
	}
	if (i)
		str = some_space(str, main, &i);
	return (str);
}
