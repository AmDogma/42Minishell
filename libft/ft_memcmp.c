/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:28:24 by jovertki          #+#    #+#             */
/*   Updated: 2021/04/09 18:39:09 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*sp1;
	const unsigned char	*sp2;

	sp1 = s1;
	sp2 = s2;
	i = 0;
	while ((i < n) && (sp1[i] == sp2[i]))
		i++;
	if (i == n)
		return (0);
	else
		return (sp1[i] - sp2[i]);
}
