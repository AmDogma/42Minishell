/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:23:47 by jovertki          #+#    #+#             */
/*   Updated: 2020/11/03 19:41:30 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = (unsigned char *)malloc(size * count);
	while (i < (size * count) && p != NULL)
	{
		p[i] = '\0';
		i++;
	}
	return ((void *)p);
}
