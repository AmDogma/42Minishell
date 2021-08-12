/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 19:22:37 by jovertki          #+#    #+#             */
/*   Updated: 2021/07/30 21:38:11 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_var_name(char *str)
{
	char	*out;
	int		i;

	i = 0;
	while (str[i] != '=' && str[i] != '\0')
		i++;
	out = ft_substr(str, 0, i);
	return (out);
}

//mode = 0 -> ONLY VALUE; mode = 1 -> FULL
char	*find_env(char **envp, char *str, int mode)
{	
	int	i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], str, ft_strlen(str)))
		i++;
	if (envp[i] == NULL)
		return (NULL);
	else if (mode == 0)
		return (&envp[i][ft_strlen(str)]);
	else
		return (envp[i]);
}

static void	print_line(char *minp, int len)
{
	char	*str;
	int		i;
	int		j;

	str = ft_calloc(len + 15, 1);
	if (str == NULL)
		malloc_err_exit();
	ft_strlcpy(str, "export -x ", len + 15);
	i = 10;
	j = 0;
	while (minp[j] != '=' && minp[j] != '\0')
		str[i++] = minp[j++];
	if (minp[j] == '\0')
	{
		ft_putendl_fd(str, 1);
		return ;
	}
	str[i++] = minp[j++];
	str[i++] = '\"';
	while (minp[j])
		str[i++] = minp[j++];
	str[i++] = '\"';
	ft_putendl_fd(str, 1);
	free(str);
}

static void	while_body(char **envp, char **minp, char **maxp, char **prev_min)
{
	int	j;

	j = 0;
	while (envp[j])
	{
		if ((*minp == NULL) || (ft_strncmp(*minp, envp[j], \
			max(ft_strlen(envp[j]), ft_strlen(*minp))) > 0 && \
			(*prev_min == NULL || ft_strncmp(*prev_min, envp[j], \
			max(ft_strlen(envp[j]), ft_strlen(*prev_min))) < 0)))
			*minp = envp[j];
		j++;
	}
	if (*minp != NULL && (*minp)[0] != '\0')
		print_line(*minp, ft_strlen(*minp));
	*prev_min = *minp;
	*minp = *maxp;
}

void	print_sorted_env(char **envp)
{
	char	*maxp;
	char	*minp;
	char	*prev_min;
	int		i;
	int		j;

	j = 0;
	i = 0;
	prev_min = NULL;
	maxp = NULL;
	while (envp[i])
	{
		if (maxp == NULL || (ft_strncmp(maxp, envp[i], \
		max(ft_strlen(envp[i]), ft_strlen(maxp))) < 0))
			maxp = envp[i];
		i++;
	}
	minp = maxp;
	i = 0;
	while (envp[i])
	{
		while_body(envp, &minp, &maxp, &prev_min);
		i++;
	}
}
