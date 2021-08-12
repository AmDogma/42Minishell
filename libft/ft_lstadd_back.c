/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 20:52:08 by jovertki          #+#    #+#             */
/*   Updated: 2021/04/14 18:23:12 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (lst == NULL)
		return ;
	temp = *lst;
	if (temp == NULL)
	{
		temp = new;
		*lst = temp;
		return ;
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}
