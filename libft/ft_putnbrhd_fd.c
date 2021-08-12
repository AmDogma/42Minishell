/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhd_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:28:29 by jovertki          #+#    #+#             */
/*   Updated: 2020/12/28 17:46:45 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

void	ft_putnbrhd_fd(unsigned long long n, int fd, char x)
{
	char	i;

	if (n > 15)
	{
		ft_putnbrhd_fd(n / 16, fd, x);
		ft_putnbrhd_fd(n % 16, fd, x);
	}
	else
	{
		if (n <= 9)
			i = (n + 48);
		else if (x == 'x')
			i = (n - 10 + 97);
		else if (x == 'X')
			i = (n - 10 + 65);
		write(fd, &i, 1);
	}
}
