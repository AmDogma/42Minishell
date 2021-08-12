/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:41:14 by jovertki          #+#    #+#             */
/*   Updated: 2021/04/09 18:41:53 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	**free_all(char **out, size_t curr_ind)
{
	size_t	i;

	i = curr_ind;
	while (i > 0)
	{
		free(out[curr_ind - i]);
		i--;
	}
	return (NULL);
}

static char	**split_body(char const *s, char c, char **out, size_t ol)
{
	size_t	ind_b;
	size_t	ind_e;
	size_t	i;
	size_t	line_len;

	i = 0;
	ind_e = 0;
	while (i < ol)
	{
		ind_b = ind_e;
		while (s[ind_b] == c)
			ind_b++;
		ind_e = ind_b;
		while (s[ind_e] != c && s[ind_e] != '\0')
			ind_e++;
		out[i] = malloc(sizeof(char) * (ind_e - ind_b + 1));
		if (out[i] == NULL)
			return (free_all(out, i));
		line_len = ind_e - ind_b - 1;
		while (++ind_b <= ind_e)
			out[i][line_len - (ind_e - ind_b)] = s[ind_b - 1];
		out[i][line_len + 1] = '\0';
		i++;
	}
	return (out);
}

static char	**split_init_arr(char const *s, char c, char **out, size_t *ol)
{
	size_t	i;
	size_t	cur_ind;

	cur_ind = 0;
	i = 0;
	if (s[0] != '\0' && s[0] != c)
		cur_ind++;
	while (i < ft_strlen(s) + 1)
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		if (i > 0 && s[i - 1] == c && s[i] != '\0')
			cur_ind++;
		i++;
	}
	out = malloc(sizeof(char *) * (cur_ind + 1));
	if (out == NULL)
		return (NULL);
	out[cur_ind] = NULL;
	*ol = cur_ind;
	return (out);
}

char	**ft_split(char const *s, char c)
{
	char	**out;
	size_t	ol;

	if (s == NULL)
		return (NULL);
	out = NULL;
	out = split_init_arr(s, c, out, &ol);
	if (out == NULL)
		return (NULL);
	out = split_body(s, c, out, ol);
	if (out == NULL)
		return (NULL);
	return (out);
}
