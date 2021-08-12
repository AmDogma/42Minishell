/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selectsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:44:46 by jovertki          #+#    #+#             */
/*   Updated: 2021/05/04 20:23:40 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

/*
**mod = 0 upward
**mod = 1 downward
*/

void	ft_selectsort(int *arr, unsigned int len, char mod)
{
	unsigned int	i;
	unsigned int	j;
	int				extr;

	i = 0;
	j = 0;
	if (arr == NULL || len == 0)
		return ;
	while (i < len - 1)
	{
		j = i;
		extr = j + 1;
		while (j < len)
		{
			if (arr[j] < arr[extr] && mod == 0)
				extr = j;
			else if (arr[j] > arr[extr] && mod == 1)
				extr = j;
			j++;
		}
		swap(&arr[i], &arr[extr]);
		i++;
	}
}
