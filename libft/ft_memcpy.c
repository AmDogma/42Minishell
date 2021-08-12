/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:17:26 by jovertki          #+#    #+#             */
/*   Updated: 2021/03/23 18:49:51 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dstp;
	const unsigned char	*srcp;

	if (dst == NULL && src == NULL)
		return (dst);
	dstp = dst;
	srcp = src;
	i = 0;
	while (i < n)
	{
		dstp[i] = srcp[i];
		i++;
	}
	return (dstp);
}
