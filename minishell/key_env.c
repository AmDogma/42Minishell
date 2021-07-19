#include "minishell.h"

char	**join_char(char **join, char *add)
{
	int		i;
	char	*forfree;

	i = -1;
	while (join && join[++i])
	{
		forfree = join[i];
		join[i] = ft_strjoin(join[i], add);
		free (forfree);
		if (!join[i])
			printf("Error: strjoin malloc PATH."); // ошибка выход
	}
	return (join);
}

char	*key_find(char **env, char *key)
{
	char *temp;

	while (*env && ft_strncmp(*env, key, ft_strlen(key)))
		env++;
	if (!*env)
		return (NULL); // не найден путь
	temp = key;
	key = ft_strdup(ft_strlen(key) + *env);
	free (temp);
	return (key);
}

char	**env_mall(char **env)
{
	int		i;
	char	**res;

	i = 0;
	while (env + i && env[i])
		i++;
	res = (char **)malloc(sizeof(char *) * (i + 1));
	if (!res)
		printf("Error: malloc"); // ошибка выход
	res[i] = NULL;
	i = 0;
	while (env[i])
	{
		res[i] = strdup(env[i]);
		if (!res[i])
			printf("Error: malloc"); // ошибка выход
		i++;
	}
	return (res);
}
