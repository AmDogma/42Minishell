/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 20:40:33 by jovertki          #+#    #+#             */
/*   Updated: 2020/11/17 21:36:35 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*buff;

	buff = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			buff = (char *)&s[i];
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (buff);
}
