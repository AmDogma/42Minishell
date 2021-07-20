#include "minishell.h"

// do    "", '', \, $, |, <>, <<>>,

int prepars(char *str, t_commandtable	*main)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			c = str[i];
			i++;
			while (c != str[i])
			{
				if (!str[i])
				{
					printf("ERROR: Need to close - %c\n", c); // нужно выйти из циклов
					return (-1); 
				}
				i++;
			}
		}
		else if (str[i] == '|')
			main->comm_num += 1;
		if (i >= INT_MAX) // нужно ли нам это
		{
			printf("Argument length is out of int"); // нужно выйти из циклов
			return (-1); 
		}
		i++;
	}
	return (0);
}

void	tab_cmd(t_command	*cmd, char *str)
{
	int	ac;
	int i;

	i = 0;
	ac = 0;
	while (str[i] && str[i + 1] && str[i] != '|') // это нужно посчитать на препарсере
		{
			if ((str[i + 1] == '\0' || str[i + 1] == ' ' || str[i + 1] == '\t') && ft_isprint(str[i]))
				ac++;
		}
	if (cmd->argv == NULL)
		cmd->argv = ft_calloc(sizeof(char *), ac + 1);
	if (!cmd->argv)
		printf("malloc error\n"); // ошибка выход
	
}

char	*some_space(char *str, t_commandtable	*main, int *i)
{
	int p;

	p = 0;
	if (*i == 0 || (str + *i + 1 && (str[*i + 1] == '\t' || str[*i + 1] == ' ')))
		return(del_one_char(str, *i));
	if (main->cmd == NULL)
	{
		main->cmd = ft_calloc(sizeof(t_command), main->comm_num + 1); // не будет ли это сегатся или мешать?
		if (!main->cmd)
			printf("malloc error\n"); // ошибка выход
	}
	if (main->cmd + main->curr_cmd == NULL)
		tab_cmd(main->cmd + main->curr_cmd, str);
	main->cmd[main->curr_cmd].argv[main->cmd[main->curr_cmd].curr_arg] = ft_substr(str, 0, *i);
	main->cmd[main->curr_cmd].curr_arg += 1;
	return(join_free(str + *i + 1, NULL, &str));
}

void	pars(char *str, t_commandtable	*main)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			str = quote(str, &i);
		else if (str[i] == '\\')
			str = del_one_char(str, i);
		else if (str[i] == '\"')
			str = d_quote(str, main, &i);
		else if (str[i] == '$')
			str = dollar(str, main, &i);
		else if (str[i] == '\t' || str[i] == ' ') // отдельная функция
			str = some_space(str, main, &i);
		else
			i++;

	}
	printf("res = %s\n", str); // для проверки правильности
}

void	tab_main(t_commandtable	*main)
{
	main->comm_num = 0;
	main->curr_cmd = 0;
	main->cmd = NULL;
}

int main(int argc, char **argv, char **env)
{
	t_commandtable	main;

	if (argc != 1)
		printf("problem = %s\n", argv[1]); // ошибка
	char *str = strdup("dad dad");
	main.env = env_mall(env);

	if (!prepars(str, &main))
		pars(str, &main);
//	while (1)
//	{
//		// tab(&main);
//		str = readline("mihell>");
//		if (!prepars(str, &main))
//			pars(str, &main);
//
//	}
	return 0;
}
