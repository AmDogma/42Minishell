/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:56:32 by jovertki          #+#    #+#             */
/*   Updated: 2021/07/30 22:25:34 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	stuff(char **out, int *size, int *counter, long int *nbr)
{	
	*out = (char *)malloc((*size + 1) * sizeof(char));
	if (*out == NULL)
		return (-1);
	(*out)[*size] = '\0';
	if (*nbr < 0)
		(*out)[*counter] = '-';
	else
		(*out)[*counter] = '\0';
	if (*nbr < 0)
		*counter = *counter + 1;
	if (*nbr < 0)
		*nbr = *nbr * -1;
	return (0);
}

static void	while_body(char *out, long int *nbr, int *size)
{
	out[*size - 1] = *nbr % 10 + '0';
	*nbr = *nbr / 10;
	*size = *size - 1;
}

char	*ft_itoa(int n)
{
	char		*out;
	int			size;
	int			counter;
	long int	nbr;

	size = 1;
	counter = n;
	nbr = n;
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
		size++;
	while (counter)
	{
		counter /= 10;
		size++;
	}
	size--;
	if (stuff(&out, &size, &counter, &nbr) == -1)
		return (NULL);
	while (counter < size)
		while_body(out, &nbr, &size);
	return (out);
}
