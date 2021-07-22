#include "minishell.h"

int prepars(char **str, t_commandtable	*main)
{
	int		i;
	char	c;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == '\'' || (*str)[i] == '\"')
		{
			c = (*str)[i];
			i++;
			while (c != (*str)[i])
			{
				if (!(*str)[i])
				{
					printf("ERROR: Need to close - %c\n", c); // нужно выйти из циклов
					return (-1);
				}
				i++;
			}
		}
		else if ((*str)[i] == '$')
			*str = dollar(*str, main, &i);
		else if ((*str)[i] == '|')
			main->comm_num += 1;
		if (i >= INT_MAX) // нужно ли нам это
		{
			printf("Argument length is out of int");
			return (-1); 
		}
		i++;
	}
	return (0);
}

char	*some_space(char *str, t_commandtable *main, int *i)
{
	t_command	*some;

	if (*i == 0 || (str + *i + 1 && str[*i + 1] == ' '))
		return(del_one_char(str, *i));

	if (main->cmd == NULL)     // сделать отдельно, тк может быть первым редирект
		main->cmd = ft_calloc(sizeof(t_command), main->comm_num + 1);
	if (main->cmd == NULL)
		printf("malloc error\n"); // ошибка выход

	some = main->cmd + main->curr_cmd;
	if (some->curr_arg == 0)
		tab_cmd(some, str);

	some->argv[some->curr_arg] = ft_substr(str, 0, *i);

	printf("comm %d.%d = %s\n", main->curr_cmd, some->curr_arg, some->argv[some->curr_arg]); // для проверки правильности
	some->curr_arg += 1;
	str = join_free(str + *i + 1, NULL, &str);
	*i = 0;
	return(str);
}

char	*redir(char *str, t_commandtable *main, int *i)
{

	return (str);
}

void	pars(char *str, t_commandtable	*main)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			str = quote(str, &i);
		else if (str[i] == '\"')
			str = d_quote(str, main, &i);
		else if (str[i] == '$')
			str = dollar(str, main, &i);
		else if (str[i] == ' ')
			str = some_space(str, main, &i);
		else if (str[i] == '|')
		{
			str = some_space(str, main, &i);
			main->curr_cmd += 1;
		}
		else if (str[i] == '<' || str[i] == '>')
			str = redir(str, main, &i); // пустая функция 
		else
			i++;
	}
	str = some_space(str, main, &i);
	free(str); // выход на исполнение
}
