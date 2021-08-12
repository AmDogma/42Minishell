#include "minishell.h"

char	*key_find(char **env, char *key)
{
	while (*env && ft_strncmp(*env, key, ft_strlen(key)))
		env++;
	if (!*env)
		return (NULL);
	key = join_free(ft_strlen(key) + *env, NULL, NULL);
	return (key);
}

void	find_dir(t_commandtable *ct)
{
	char	*key;

	key = key_find(ct->env, "_=");
	if (!key)
		printf("here doc can't find work directory");
	if (ft_strlen(key) >= 9)
		key[ft_strlen(key) - 9] = '\0';
	ct->work_dir = join_free(key, NULL, &key);
}
