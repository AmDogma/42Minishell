/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 20:40:23 by jovertki          #+#    #+#             */
/*   Updated: 2021/04/29 18:53:29 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

void	ft_putstr_fd(char *s, int fd)
{
	long long	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i])
		i++;
	write(fd, s, i);
}
