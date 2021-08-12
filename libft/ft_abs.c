/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 17:53:50 by jovertki          #+#    #+#             */
/*   Updated: 2021/04/09 18:31:51 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long	ft_abs(long long num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

double	ft_abs_f(double num)
{
	if (num < 0)
		num *= -1;
	return (num);
}
