/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:15:10 by jovertki          #+#    #+#             */
/*   Updated: 2021/04/09 18:44:52 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *hay, const char *ndl, size_t len)
{
	size_t			i;
	size_t			j;
	const char		*savedp;

	i = 0;
	savedp = NULL;
	if (ndl[0] == '\0')
		return ((char *)hay);
	while (hay[i] != '\0' && i < len)
	{
		if (hay[i] == ndl[0])
		{
			savedp = &hay[i];
			j = 0;
			while (hay[i + j] != '\0' && hay[i + j] == ndl[j] && i + j < len)
				j++;
			if (j == ft_strlen(ndl))
				return ((char *)savedp);
			else
				savedp = NULL;
		}
		i++;
	}
	return ((char *)savedp);
}
