/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 20:30:52 by jovertki          #+#    #+#             */
/*   Updated: 2021/07/30 22:17:31 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**make_command(char *s1, char *s2)
{
	char	**out;

	out = malloc(sizeof(char *) * 3);
	if (out == NULL)
		malloc_err_exit();
	out[0] = ft_strdup(s1);
	out[1] = ft_strdup(s2);
	out[2] = NULL;
	return (out);
}

static void	free_temps(char	*strtemp, char **temp)
{
	int	i;

	free(strtemp);
	i = 0;
	while (temp[i])
	{
		free(temp[i]);
		i++;
	}
	free(temp);
}

static void	set_pwds(char ***envp)
{
	char	**temp;
	char	*strtemp;
	char	buf[PATH_MAX];

	strtemp = ft_strjoin("OLDPWD=", find_env(*envp, "PWD=", 0));
	temp = make_command("export", strtemp);
	ft_export(2, temp, envp);
	free_temps(strtemp, temp);
	strtemp = ft_strjoin("PWD=", getcwd(buf, PATH_MAX));
	temp = make_command("export", strtemp);
	ft_export(2, temp, envp);
	free_temps(strtemp, temp);
}

static void	print_error(void)
{
	char	*strtemp;

	strtemp = ft_strjoin("cd: ", strerror(errno));
	ft_putendl_fd(strtemp, 2);
	free(strtemp);
}

int	cd(char **argv, int argc, char ***envp)
{
	char	*str;

	if (argc > 2)
	{
		ft_putstr_fd("cd: too many arguments\n", 2);
		return (1);
	}
	if (argv[1] == NULL || argv[1][0] == '\0')
		str = find_env(*envp, "HOME=", 0);
	else
		str = argv[1];
	if (chdir(str) == -1)
	{
		print_error();
		return (1);
	}
	set_pwds(envp);
	return (0);
}
