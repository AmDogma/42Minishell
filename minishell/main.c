#include "minishell.h"

// do    "", '', \, $, |, <>, <<>>,


int main(int argc, char **argv, char **env)
{
	t_commandtable	main;

	if (argc != 1)
		printf("problem = %s\n", argv[1]); // ошибка
	char *str = strdup("cmd $USER \"$USER some\"\'$USER\'|cmd $USER \"$USER some\"\'$USER\'|cmd $USER \"$USER some\"\'$USER\'");
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
