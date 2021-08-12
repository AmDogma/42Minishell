/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 22:00:47 by jovertki          #+#    #+#             */
/*   Updated: 2021/07/30 22:05:37 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_not_builtin(char *str)
{
	int	out;

	out = 1;
	if (ft_strncmp("echo\0", str, 5) == 0 || \
		ft_strncmp("cd\0", str, 3) == 0 || \
		ft_strncmp("pwd\0", str, 4) == 0 || \
		ft_strncmp("export\0", str, 7) == 0 || \
		ft_strncmp("unset\0", str, 6) == 0 || \
		ft_strncmp("env\0", str, 4) == 0 || \
		ft_strncmp("exit\0", str, 5) == 0)
		out = 0;
	return (out);
}

int	execbuiltin(int *exit, char **argv, int argc, char ***envp)
{
	if (ft_strncmp("echo\0", argv[0], 5) == 0)
		*exit = echo(argv);
	else if (ft_strncmp("cd\0", argv[0], 3) == 0)
		*exit = cd(argv, argc, envp);
	else if (ft_strncmp("pwd\0", argv[0], 4) == 0)
		*exit = pwd();
	else if (ft_strncmp("export\0", argv[0], 7) == 0)
		*exit = ft_export(argc, argv, envp);
	else if (ft_strncmp("unset\0", argv[0], 6) == 0)
		*exit = ft_unset(argc, argv, envp);
	else if (ft_strncmp("env\0", argv[0], 4) == 0)
		*exit = env(*envp);
	else if (ft_strncmp("exit\0", argv[0], 5) == 0)
		*exit = ft_exit(argc, argv);
	return (0);
}

void	redirect_input(t_execute *all, t_commandtable *ct, int i)
{
	if (ct->cmd[i].input)
		dup2(ct->cmd[i].input, 0);
	else
		dup2(all->fdin, 0);
	close(all->fdin);
}

void	pipes_init(t_execute *all, t_commandtable *ct)
{
	ft_bzero(all, sizeof(t_execute));
	all->default_in = dup(0);
	all->default_out = dup(1);
	if (ct->cmd[0].input)
		all->fdin = ct->cmd[0].input;
	else
		all->fdin = dup(all->default_in);
}
