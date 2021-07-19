#include "minishell.h"

// do    "", '', \, $, |, <>, <<>>,

void	pars(char *str, t_commandtable	*main)
{
	int			i;
	int			n;
	i = 0;
	n = -1;

	while (str[i] == '\t' || str[i] == ' ')
		i++;
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
		{
			main->cmd[main->comm_num - 1].argv[++n] = ft_substr(str, 0, i); // нужно назначить необходимое кол-во структур
			printf("comm = %s\n", main->cmd[main->comm_num - 1].argv[n]);
//			while (str[i] == '\t' || str[i] == ' ')
////				i++; // последний раз лишний шаг, тут можно обнулять строку или другой прием для пропуска пробела
		}
		i++;

	}
	printf("res = %s\n", str); // для проверки правильности
}

int main(int argc, char **argv, char **env)
{
	t_commandtable	main;

	char *str = strdup("\"\\\\ $USER d_quote\"!\'quote\'!$USER $");
	main.env = env_mall(env);
	main.comm_num = 0;
	main.cmd = (t_command *)malloc(sizeof(t_command) * 2);
	if (!main.cmd)
		printf("Error: strjoin malloc PATH."); // ошибка выход
	if (argc != 1)
		printf("problem = %s\n", argv[1]); // ошибка

	int i = 0;
//	while (envir[i])
//		printf("%s\n", envir[i++]);
//
	while (1 + i--)
	{
		main.comm_num += 1;
//		main.str = readline("minihell>");
		pars(str, &main);
	}

//	int i = -1;
//	char **path = path_pars(env, "PATH=");
//	while (path[++i])
//		printf("%s\n", path[i]);
	return 0;
}
