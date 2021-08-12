/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 19:08:57 by jovertki          #+#    #+#             */
/*   Updated: 2020/12/26 19:09:03 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	min(long long num1, long long num2)
{
	if (num1 >= num2)
		return (num2);
	else
		return (num1);
}

long long	max(long long num1, long long num2)
{
	if (num1 <= num2)
		return (num2);
	else
		return (num1);
}
