/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 20:37:22 by jovertki          #+#    #+#             */
/*   Updated: 2021/07/30 20:09:32 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	inthandler(int num)
{
	num = 1;
	rl_on_new_line();
	rl_redisplay();
	ft_putstr_fd("  \n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	eofhandler(void)
{
	write(1, "\033[Aminishell$ exit\n", ft_strlen("\033[Aminishell$ exit\n"));
	rl_redisplay();
	exit(0);
}

void	inthandler_hc(int num)
{
	num = 1;
	rl_replace_line(" ", 0);
	rl_on_new_line();
	rl_redisplay();
	write(1, "  \n", 3);
	signal(SIGINT, inthandler);
	exit(1);
}

void	inthandler_hc_p(int num)
{
	num = 1;
	signal(SIGINT, inthandler);
}

void	eofhandler_hc(void)
{
	write(1, "\033[A> ", ft_strlen("\033[A> "));
	exit(0);
}
