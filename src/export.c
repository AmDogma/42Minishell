/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 19:54:16 by jovertki          #+#    #+#             */
/*   Updated: 2021/07/30 22:18:47 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**ft_add_new(char **envp, char *arg, int envplen)
{
	char	**new_envp;
	int		i;

	new_envp = ft_calloc(sizeof(char *), (envplen + 10));
	if (new_envp == NULL)
		malloc_err_exit();
	i = 0;
	while (envp[i])
	{
		new_envp[i] = ft_strdup(envp[i]);
		i++;
	}
	new_envp[i] = ft_strdup(arg);
	new_envp[i + 1] = NULL;
	i = 0;
	while (envp[i])
	{
		free(envp[i]);
		i++;
	}
	free(envp);
	return (new_envp);
}

static int	name_valid(char *name)
{
	int	i;

	i = 0;
	if (!((name[0] >= 'a' && name[0] <= 'z') || \
		(name[0] >= 'A' && name[0] <= 'Z') || name[0] == '_'))
		return (0);
	while (name[i])
	{
		if (!((name[i] >= 'a' && name[i] <= 'z') || \
		(name[i] >= 'A' && name[i] <= 'Z') || \
		name[i] == '_' || (name[i] >= '0' && name[i] <= '9')))
			return (0);
		i++;
	}
	return (1);
}

static void	update_or_add(t_ft_export *all, char ***envp, char **argv)
{
	while ((*envp)[all->i])
	{
		if (ft_strncmp((*envp)[all->i], all->name, \
		ft_strlen(all->name)) == 0 || (ft_strncmp((*envp)[all->i], \
		all->name, ft_strlen(all->name)) == 0 && \
		(*envp)[all->i][ft_strlen(all->name) + 1] == '='))
		{
			break ;
		}
		all->i++;
	}
	if ((*envp)[all->i] != NULL)
	{
		free((*envp)[all->i]);
		(*envp)[all->i] = ft_strdup(argv[all->j]);
	}
	else
	{
		*envp = ft_add_new(*envp, argv[all->j], all->envplen);
		all->i++;
		all->envplen++;
	}
}

static void	export_value(t_ft_export *all, char ***envp, char **argv, int argc)
{
	while (all->j < argc)
	{
		all->name = find_var_name(argv[all->j]);
		if (!(name_valid(all->name)))
		{
			printf("export: `%s':not a valid identifier\n", all->name);
			all->out = 1;
		}
		else
			update_or_add(all, envp, argv);
		free(all->name);
		all->j++;
		all->out = 0;
	}
}

int	ft_export(int argc, char **argv, char ***envp)
{
	t_ft_export	all;

	ft_bzero(&all, sizeof(t_ft_export));
	all.j = 1;
	while ((*envp)[all.i])
		all.i++;
	all.envplen = all.i;
	all.i = 0;
	if (argc == 1)
		print_sorted_env(*envp);
	else
		export_value(&all, envp, argv, argc);
	return (all.out);
}
