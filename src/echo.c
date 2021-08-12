/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 15:09:55 by jovertki          #+#    #+#             */
/*   Updated: 2021/07/30 19:06:28 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid(char *str)
{
	int	i;

	if (str[0] == '-' && str[1] == 'n')
	{
		i = 2;
		while (str[i] == 'n')
			i++;
		if (str[i] == '\0')
			return (1);
	}
	return (0);
}

static int	check_for_n(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (!(is_valid(str[i])))
			break ;
		i++;
	}
	return (i);
}

int	echo(char **str)
{
	int	i;

	i = 0;
	if (str[1] == NULL)
		ft_putchar_fd('\n', 1);
	else
	{
		i = check_for_n(str);
		while (str[i])
		{
			ft_putstr_fd(str[i], 1);
			if (str[i + 1] != NULL)
				ft_putchar_fd(' ', 1);
			i++;
		}
		if (check_for_n(str) == 1)
			ft_putchar_fd('\n', 1);
	}
	return (0);
}
