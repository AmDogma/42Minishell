#include "minishell.h"

// do    "", '', \, $, ;, |, <>, <<>>,

char	*quote(char *str, int *i)
{
	str = del_one(str, i);
	while (str[*i] && str[*i] != '\'')
		(*i)++;
	str = del_one(str, i);
	return(str);
}

char	*d_quote(char *str, int *i)
{
	str = del_one(str, i);
	while (str[*i] && str[*i] != '\"')
		(*i)++;
	str = del_one(str, i);
	return(str);
}

char	*del_one(char *str, int *i)
{
	str[*i] = '\0';
	str = join_free(str, str + *i + 1, &str);
	return (str);
}

void exit_stat(void)
{
	//разобраться с записью статуса последней исполненной программы
}

char	*dollar(char *str, int *i)
{
	int beg;

	beg = *i + 1;
	if (str[beg] == '?')
		exit_stat(); // продумать
	while (ft_isalnum(str[*i]) || str[*i] == '_')
		(*i)++;
	if (beg == *i + 1)
		return (del_one(str, i));


	return (str);
}

void	pars(char *str, char **env)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'')
			str = quote(str, &i);
		else if (str[i] == '\\')
			str = del_one(str, &i);
		else if (str[i] == '\"')
			str = d_quote(str, &i);
		else if (str[i] == '$')
			str = dollar(str, &i);
		
	}
	printf("res = %s\n", str); // для проверки правильности
}

int main(int argc, char **argv, char **env)
{
	char *comm = strdup("\"d_quote\"!\'quote\'!\\\\!$");
	pars(comm, env);
	return 0;
}
