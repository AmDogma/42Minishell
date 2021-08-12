/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:53:29 by jovertki          #+#    #+#             */
/*   Updated: 2021/07/30 22:31:47 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static char	*init(size_t *len1, size_t *len2, const char *s1, const char *s2)
{
	char	*str;

	*len1 = ft_strlen(s1);
	*len2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (*len1 + *len2 + 1));
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	len1;
	size_t	len2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	str = init(&len1, &len2, s1, s2);
	if (str == NULL)
		return (str);
	while (i < len1)
	{
		str[i] = s1[i];
		i++;
	}
	while (i - len1 < len2)
	{
		str[i] = s2[i - len1];
		i++;
	}
	str[i] = '\0';
	return (str);
}

//free first
char	*ft_strjoin_ff(char *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	len1;
	size_t	len2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	str = init(&len1, &len2, s1, s2);
	if (str == NULL)
		return (str);
	while (i < len1)
	{
		str[i] = s1[i];
		i++;
	}
	while (i - len1 < len2)
	{
		str[i] = s2[i - len1];
		i++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

//free second
char	*ft_strjoin_fs(char const *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	len1;
	size_t	len2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	str = init(&len1, &len2, s1, s2);
	if (str == NULL)
		return (str);
	while (i < len1)
	{
		str[i] = s1[i];
		i++;
	}
	while (i - len1 < len2)
	{
		str[i] = s2[i - len1];
		i++;
	}
	str[i] = '\0';
	free(s2);
	return (str);
}

//free both
char	*ft_strjoin_fb(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	len1;
	size_t	len2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	str = init(&len1, &len2, s1, s2);
	if (str == NULL)
		return (str);
	while (i < len1)
	{
		str[i] = s1[i];
		i++;
	}
	while (i - len1 < len2)
	{
		str[i] = s2[i - len1];
		i++;
	}
	str[i] = '\0';
	free(s2);
	free(s1);
	return (str);
}
