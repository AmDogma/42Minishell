/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_chars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 18:21:52 by jovertki          #+#    #+#             */
/*   Updated: 2021/03/05 18:30:24 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_skip_chars(char *str, char *skip, int *cur_pos)
{
	int			i;
	char		arr[128];

	i = 0;
	while (i < 128)
	{
		arr[i] = 0;
		i++;
	}
	i = 0;
	while (skip[i])
	{
		arr[(int)skip[i]] = 1;
		i++;
	}
	i = 0;
	while (arr[(int)str[*cur_pos]] == 1)
		*cur_pos = *cur_pos + 1;
	return (&str[*cur_pos]);
}
