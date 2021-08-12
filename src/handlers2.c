/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 20:09:23 by jovertki          #+#    #+#             */
/*   Updated: 2021/07/31 16:20:19 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	inthandler_cd(int num)
{
	num = 1;
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	write(1, "\033[11D          \b\b\b\b\b\b\b\b\b\b\n", \
	ft_strlen("\033[11D          \b\b\b\b\b\b\b\b\b\b\n"));
	exit(2);
}

void	inthandler_p(int num)
{
	num = 1;
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	write(1, "\033[11D          \b\b\b\b\b\b\b\b\b\b\n", \
	ft_strlen("\033[11D          \b\b\b\b\b\b\b\b\b\b\n"));
}

void	quithandler_cd(int num)
{
	num = 1;
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	write(1, "\033[11DQuit: 3   \b\b\b\n", ft_strlen("\033[11DQuit: 3   \b\b\b\n"));
	exit(3);
}

void	quithandler_p(int num)
{
	num = 1;
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	write(1, "\033[11DQuit: 3   \b\b\b\n", ft_strlen("\033[11DQuit: 3   \b\b\b\n"));
}
