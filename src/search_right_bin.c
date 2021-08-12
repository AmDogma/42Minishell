/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_right_bin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 21:00:18 by jovertki          #+#    #+#             */
/*   Updated: 2021/07/30 22:19:28 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	add_program_name(char **variants, char **argv)
{
	int		i;

	i = 0;
	while (variants[i])
	{
		variants[i] = ft_strjoin_fb(variants[i], ft_strjoin("/", argv[0]));
		i++;
	}
}

static void	execute_path(char **argv, char **envp, int *exit_st)
{
	char	*temp;
	int		err_cpy;

	if (execve(argv[0], argv, envp) == -1)
	{
		err_cpy = errno;
		temp = ft_strjoin_fs("minishell: ", \
			ft_strjoin_ff(ft_strjoin(argv[0], ": "), strerror(errno)));
		ft_putendl_fd(temp, 2);
		free(temp);
		if (err_cpy == ENOENT)
			*exit_st = 127;
		else
			*exit_st = 126;
	}
}

static void	execute_command(char **variants, char **argv, char **envp)
{
	int	i;

	i = 0;
	add_program_name(variants, argv);
	while (variants[i])
	{
		execve(variants[i], argv, envp);
		i++;
	}
	i = 0;
	while (variants[i])
	{
		free(variants[i]);
		i++;
	}
	free(variants);
}

void	search_right_bin(char **argv, char **envp, int *exit_st)
{
	char	**variants;
	char	*temp;

	variants = ft_split(find_env(envp, "PATH=", 0), ':');
	if (ft_strchr(argv[0], '/') != NULL && *(ft_strchr(argv[0], '/')) != '\0')
	{
		if (execve(argv[0], argv, envp) == -1)
		{
			execute_path(argv, envp, exit_st);
			return ;
		}
	}
	else if (variants)
		execute_command(variants, argv, envp);
	temp = ft_strjoin_fs("minishell: ", ft_strjoin(argv[0], \
		": command not found"));
	*exit_st = 127;
	ft_putendl_fd(temp, 2);
	free(temp);
}
