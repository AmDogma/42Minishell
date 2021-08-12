/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 21:23:57 by jovertki          #+#    #+#             */
/*   Updated: 2021/04/09 20:13:18 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		real_len;

	str = NULL;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		str = malloc(sizeof(char));
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	real_len = ft_strlen(&s[start]);
	if (real_len < len)
		len = real_len;
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, &s[start], len + 1);
	return (str);
}
