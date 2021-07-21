#include "minishell.h"

// do    "", '', \, $, |, <>, <<>>,

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

void	tab_cmd(t_command *cmd, char *str)
{
	int	ac;
	int i;

	i = 0;
	ac = 0;
	while (str[i] && str[i + 1] && str[i] != '|') // это можно посчитать на препарсере
		{
			if ((str[i + 1] == '\0' || str[i + 1] == ' ' || str[i + 1] == '\t') && ft_isprint(str[i])) // не будет правильно считать из за пробелов в ковычках, нужно додумать или так оставим, тк кол-во точно будет больше чем нужно
				ac++;
			i++;
		}
	if (cmd->argv == NULL)
		cmd->argv = ft_calloc(sizeof(char *), ac + 1);
	if (!cmd->argv)
		printf("malloc error\n"); // ошибка выход
	
}

char	*some_space(char *str, t_commandtable *main, int *i)
{
	t_command	*some;

	if (*i == 0 || (str + *i + 1 && (str[*i + 1] == '\t' || str[*i + 1] == ' ')))
		return(del_one_char(str, *i));

	if (main->cmd == NULL)
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
//		else if (str[i] == '\\')
//			str = del_one_char(str, i); // не нужно делать похоже
		else if (str[i] == '\"')
			str = d_quote(str, main, &i);
		else if (str[i] == '$')
			str = dollar(str, main, &i);
		else if (str[i] == '\t' || str[i] == ' ')
			str = some_space(str, main, &i);
		else if (str[i] == '|')
		{
			str = some_space(str, main, &i);
			main->curr_cmd += 1;
		}
		else if (str[i] == '<' || str[i] == '>')
			str = redir(str, main, &i);
		else
			i++;
	}
	str = some_space(str, main, &i);
	free(str); // далее выход на работу пайпов
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
	char *str = strdup("Dad $USER \"$USER SUPER\"\'$USER\'   |   ofcourse");
	main.env = env_mall(env);

	tab_main(&main);
	if (!prepars(&str, &main))
		pars(str, &main);

//	while (1)
//	{
//		tab_main(&main);
//		str = readline("mihell>");
//		if (!prepars(str, &main))
//			pars(str, &main);
// 		//далее выход на работу пайпов
//
//	}

	return 0;
}
