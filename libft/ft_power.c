/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:38:15 by jovertki          #+#    #+#             */
/*   Updated: 2021/04/23 19:20:42 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	power_i(long long num, int power)
{
	int			i;
	long long	buf;

	i = 0;
	buf = num;
	num = 1;
	if (power > 0)
	{
		while (i < power)
		{
			num *= buf;
			i++;
		}
	}
	else if (power < 0)
	{
		while (i > power)
		{
			num /= buf;
			i--;
		}
	}
	else
		return (1);
	return (num);
}

double	power_d(double num, int power)
{
	int		i;
	double	buf;

	i = 0;
	buf = num;
	if (power > 0)
	{
		while (i < power)
		{
			num *= buf;
			i++;
		}
	}
	else if (power < 0)
	{
		while (i > power)
		{
			num /= buf;
			i--;
		}
	}
	else
		return (1);
	return (num);
}
