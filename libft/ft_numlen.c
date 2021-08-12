/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 21:47:24 by jovertki          #+#    #+#             */
/*   Updated: 2021/04/09 20:51:28 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_snumlen(long long num)
{
	int		i;

	i = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num = num / 10;
		i++;
	}
	if (num < 0)
		i++;
	return (i);
}

int	ft_unumlen(unsigned long long num)
{
	int		i;

	i = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

int	ft_unumlen_hd(unsigned long long num)
{
	int		i;

	i = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num = num / 16;
		i++;
	}
	return (i);
}
