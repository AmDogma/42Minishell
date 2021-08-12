/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:45:29 by jovertki          #+#    #+#             */
/*   Updated: 2021/04/09 18:38:33 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t					i;
	unsigned char			*dstp;
	const unsigned char		*srcp;

	dstp = dst;
	srcp = src;
	i = 0;
	while (i < n)
	{
		dstp[i] = srcp[i];
		if (dstp[i] == (unsigned char)c)
			return ((void *)(dst + i + 1));
		i++;
	}
	return (NULL);
}
