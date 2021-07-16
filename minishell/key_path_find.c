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

	while (*env && ft_strncmp(*env, key, ft_strlen(key)))
		env++;
	if (!*env)
		return (NULL); // не найден путь
	*env += ft_strlen(key);
	return (*env);
}

char	**path_pars(char **env)
{
	char	**temp;


	temp = ft_split(key_find(env, "PATH="), ':');
	if (!temp)
		printf("Error: split malloc PATH."); // ошибка выход

	temp = join_char(temp, "/");
	return (temp);
}
