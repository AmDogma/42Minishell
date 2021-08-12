/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 21:24:57 by jovertki          #+#    #+#             */
/*   Updated: 2021/04/09 18:36:36 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*out;
	t_list	*temp;

	if (lst == NULL)
		return (NULL);
	out = NULL;
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (temp == NULL)
		{
			ft_lstclear(&lst, del);
			return (NULL);
		}
		ft_lstadd_back(&out, temp);
		lst = lst->next;
	}
	return (out);
}
