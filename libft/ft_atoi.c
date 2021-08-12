/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:04:39 by jovertki          #+#    #+#             */
/*   Updated: 2021/05/05 20:02:23 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_atoi(const char *str)
{
	long int	i;
	char		sign;
	long long	out;

	i = 0;
	out = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		out = out * 10 + (str[i] - '0');
		if (out * sign > INT_MAX)
			return (-1);
		if (out * sign < INT_MIN)
			return (-1);
		i++;
	}
	return ((int)out * sign);
}
