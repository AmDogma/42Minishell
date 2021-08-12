/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 17:29:27 by jovertki          #+#    #+#             */
/*   Updated: 2021/04/09 18:42:17 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;

	dest = (char *)malloc(ft_strlen(s1) + 1);
	if (dest == 0)
		return (NULL);
	ft_strcpy(dest, s1);
	return (dest);
}
