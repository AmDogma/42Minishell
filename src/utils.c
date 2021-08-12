#include "minishell.h"

char	*join_free(char const *str1, char const *str2, char **tofree)
{
	char	*dest;
	size_t	num;
	size_t	i;

	i = 0;
	num = ft_strlen(str1) + ft_strlen(str2) + 1;
	dest = calloc(sizeof(char), num);
	if (dest)
	{
		if (str1)
			ft_strlcat(dest, str1, num);
		if (str2)
			ft_strlcat(dest, str2, num);
	}
	if (tofree && *tofree)
	{
		free(*tofree);
		*tofree = NULL;
	}
	if (dest == NULL)
		malloc_err_exit();
	return (dest);
}

char	*del_one_char(char *str, int i)
{
	str[i] = '\0';
	str = join_free(str, str + i + 1, &str);
	return (str);
}
