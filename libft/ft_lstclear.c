/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 21:07:53 by jovertki          #+#    #+#             */
/*   Updated: 2020/11/16 22:28:37 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*temp_old;

	if (del == NULL || lst == NULL)
		return ;
	temp = *lst;
	while (temp != NULL)
	{
		del((temp)->content);
		temp_old = temp;
		temp = temp_old->next;
		free(temp_old);
	}
	*lst = NULL;
}
