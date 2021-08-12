/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:23:40 by jovertki          #+#    #+#             */
/*   Updated: 2021/07/30 21:33:34 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	malloc_err_exit(void)
{
	ft_putendl_fd("minishell: insufficient memory\n", 2);
	exit(errno);
}

static int	arg_is_valid(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!((arg[i] >= '0' && arg[i] <= '9') \
			|| arg[i] == '-' || arg[i] == '+'))
			return (0);
		i++;
	}
	return (1);
}

int	ft_exit(int argc, char **argv)
{
	char	*temp;
	int		num;

	if (argc == 1)
	{
		printf("exit\n");
		exit(0);
	}
	if (argc > 2)
	{
		ft_putendl_fd("minishell: exit: too many arguments", 2);
		return (1);
	}
	if (!(arg_is_valid(argv[1])))
	{
		temp = ft_strjoin("minishell: exit: ", argv[1]);
		printf("exit\n");
		temp = ft_strjoin_ff(temp, ": numeric argument required");
		ft_putendl_fd(temp, 2);
		free(temp);
		exit(255);
	}
	num = ft_atoi(argv[1]);
	printf("exit\n");
	exit(num);
}
