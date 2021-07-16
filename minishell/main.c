#include "minishell.h"

// do    "", '', \, $, ;, |, <>, <<>>,

void	pars(char *str, char **env)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'')
			str = quote(str, &i);
		else if (str[i] == '\\')
			str = del_one_char(str, i);
		else if (str[i] == '\"')
			str = d_quote(str, &i);
		else if (str[i] == '$')
			str = dollar(str, env, &i);
		
	}
	printf("res = %s\n", str); // для проверки правильности
}

int main(int argc, char **argv, char **env)
{
	char *comm = strdup("\"d_quote\"!\'quote\'!\\\\!$PATH $"); // сразу маллочим
	pars(comm, env);

//	int i = -1;
//	char **path = path_pars(env, "PATH=");
//	while (path[++i])
//		printf("%s\n", path[i]);
	return 0;
}
