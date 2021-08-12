/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:14:18 by jovertki          #+#    #+#             */
/*   Updated: 2020/11/10 20:00:38 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char				*dstp;
	unsigned const char			*srcp;
	unsigned const char			*lasts;
	unsigned char				*lastd;

	if (dst == NULL && src == NULL)
		return (NULL);
	dstp = dst;
	srcp = src;
	if (dstp < srcp)
		while (n--)
			*dstp++ = *srcp++;
	else
	{
		lasts = srcp + (n - 1);
		lastd = dstp + (n - 1);
		while (n--)
			*lastd-- = *lasts--;
	}
	return (dst);
}
