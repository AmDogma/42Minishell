#include "minishell.h"

void	tab_cmd(t_command *cmd, char *str)
{
	int	ac;
	int i;

	i = 0;
	ac = 0;
	while (str[i] && str[i + 1] && str[i] != '|') // это можно посчитать на препарсере
		{
			if ((str[i + 1] == '\0' || str[i + 1] == ' ') && ft_isprint(str[i])) // не будет правильно считать из за пробелов в ковычках, нужно додумать или так оставим, тк кол-во точно будет больше чем нужно
				ac++;
			i++;
		}
	if (cmd->argv == NULL)
		cmd->argv = ft_calloc(sizeof(char *), ac + 1);
	if (!cmd->argv)
		printf("malloc error\n"); // ошибка выход
	
}

void	tab_main(t_commandtable	*main)
{
	main->comm_num = 0;
	main->curr_cmd = 0;
	main->cmd = NULL;
}
