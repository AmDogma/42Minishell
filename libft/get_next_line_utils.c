/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 17:07:35 by jovertki          #+#    #+#             */
/*   Updated: 2021/04/09 19:42:11 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl_list	*new_list_elem(int fd)
{
	t_gnl_list	*new;

	new = (t_gnl_list *)malloc(sizeof(t_gnl_list));
	new->fd = fd;
	new->rem = ft_strnew(BUFFER_SIZE);
	new->next = NULL;
	new->is_over = 0;
	return (new);
}

size_t	ft_strlen_m(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_shift_left(char *begin, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		begin[i] = src[i];
		i++;
	}
	while (begin[i])
	{
		begin[i] = '\0';
		i++;
	}
	return (begin);
}

char	*ft_strchr_m(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return ((char *)&s[i]);
}
