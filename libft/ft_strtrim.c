/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:07:00 by jovertki          #+#    #+#             */
/*   Updated: 2021/04/09 20:13:56 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static char	*trim_body(char const *s1, char *str, char *flags)
{
	size_t	end;
	size_t	i;
	size_t	starti;

	i = 0;
	while (s1[i] && flags[(unsigned char)s1[i]])
		i++;
	starti = i;
	end = i;
	while (s1[i])
	{
		if (!flags[(unsigned char)s1[i]])
			end = i;
		i++;
	}
	str = ft_calloc(sizeof(char), (end - starti + 2));
	if (str == NULL)
		return (NULL);
	i = starti;
	while (i <= end)
	{
		str[i - starti] = s1[i];
		i++;
	}
	return (str);
}

static void	flags_init(char *flags, const char *set)
{
	size_t	i;

	i = 0;
	while (i < 256)
	{
		flags[i] = 0;
		i++;
	}
	i = 0;
	while (i < ft_strlen(set))
	{
		flags[(unsigned char)set[i]] = 1;
		i++;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	flags[256];

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
	{
		str = malloc(sizeof(const char) * ft_strlen(s1) + 1);
		if (str == NULL)
			return (NULL);
		ft_memcpy(str, s1, ft_strlen(s1) + 1);
		return (str);
	}
	flags_init(flags, set);
	str = NULL;
	return (trim_body(s1, str, flags));
}
