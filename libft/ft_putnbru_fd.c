/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 18:24:07 by jovertki          #+#    #+#             */
/*   Updated: 2021/01/01 18:26:56 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

void	ft_putnbru_fd(unsigned long long n, int fd)
{
	char	i;

	if (n > 9)
	{
		ft_putnbru_fd(n / 10, fd);
		ft_putnbru_fd(n % 10, fd);
	}
	else
	{
		i = (n + 48);
		write(fd, &i, 1);
	}
}
