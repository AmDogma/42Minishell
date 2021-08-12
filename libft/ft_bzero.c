/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:56:09 by jovertki          #+#    #+#             */
/*   Updated: 2020/11/17 18:45:03 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_bzero(void *b, size_t len)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = b;
	i = 0;
	while (i < len)
	{
		ptr[i] = '\0';
		i++;
	}
	return ((void *)ptr);
}
