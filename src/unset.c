/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 20:19:24 by jovertki          #+#    #+#             */
/*   Updated: 2021/07/30 22:19:34 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**create_new_envp(char ***envp, char *temp)
{
	int		i;
	int		j;
	char	**new_envp;

	i = 0;
	while ((*envp)[i])
		i++;
	new_envp = ft_calloc(sizeof(char *), i + 2);
	if (new_envp == NULL)
		malloc_err_exit();
	i = 0;
	j = 0;
	while ((*envp)[i])
	{
		if (ft_strncmp((*envp)[i], temp, ft_strlen(temp)))
			new_envp[j++] = ft_strdup((*envp)[i]);
		i++;
	}
	i = 0;
	while ((*envp)[i])
		free((*envp)[i++]);
	free((*envp));
	return (new_envp);
}

int	ft_unset(int argc, char **argv, char ***envp)
{
	char	*temp;
	char	*temp_name;
	int		i;

	i = 1;
	temp = NULL;
	while (i < argc)
	{
		temp = find_env(*envp, argv[i], 1);
		if (temp == NULL)
		{
			temp_name = ft_strjoin(argv[i], "=");
			temp = find_env(*envp, argv[i], 1);
			free(temp_name);
			if (temp == NULL)
				return (0);
			else
				*envp = create_new_envp(envp, temp);
		}
		else
			*envp = create_new_envp(envp, temp);
		i++;
	}
	return (0);
}
