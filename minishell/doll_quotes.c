#include "minishell.h"

char	*quote(char *str, int *i)
{
	str = del_one_char(str, *i);
	while (str[*i] && str[*i] != '\'')
		(*i)++;
	str = del_one_char(str, *i);
	return(str);
}

char	*d_quote(char *str, int *i)
{
	str = del_one_char(str, *i);
	while (str[*i] && str[*i] != '\"')
		(*i)++;
	str = del_one_char(str, *i);
	return(str);
}

void exit_stat(void)
{
	//разобраться с записью статуса последней исполненной программы
}

char	*dollar(char *str, char **env, int *i)
{
	int		beg;
	char	*key;
	char	*temp;

	beg = ++(*i);
	if (str[beg] == '?')
		exit_stat(); // продумать
	while (ft_isalnum(str[*i]) || str[*i] == '_')
		(*i)++;
	if (beg == *i)
		return (str);
	key = ft_substr(str, beg, *i - beg); // обрабоатать все ошибки маллока
	key = join_free(key, "=", &key);

	key = join_free(key_find(env, key), NULL, &key);
	str[beg - 1] = '\0';
	temp = strdup(str + *i);
	str = join_free(str, key, &str);
	str = join_free(str, temp, &str);
	if (temp)
		free(temp);
	if (key)
		free(key);

//	if (!key || !str)
//		printf("malloc error\n"); // ошибка выход
//
//
//	printf("key %s\n", key);

	return (str);
}
