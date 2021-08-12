/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:50:50 by jovertki          #+#    #+#             */
/*   Updated: 2021/04/09 18:41:15 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_int(long long n, int fd)
{
	if (!n)
		write(1, "0", fd);
	else
		ft_putnbr_fd(n, fd);
}

void	ft_putfnbr_fd(double n, int prec, int fd)
{
	double	num;

	num = n;
	num = 10 * (num * power_d(10, prec - 1) - \
		((long long)(num * power_d(10, prec - 1))));
	if (num > 5)
		n += power_d(10, -1 * (prec + 1));
	print_int((long long)n, fd);
	n -= (long long)n;
	if (!n && !prec)
		return ;
	if (prec != 0)
		write(1, ".", fd);
	while ((!n && prec) || prec)
	{
		print_int((long long)(n * 10), fd);
		n = n * 10 - ((long long)(n * 10));
		prec--;
	}
}
