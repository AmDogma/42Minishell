/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 17:07:25 by jovertki          #+#    #+#             */
/*   Updated: 2021/04/09 19:42:31 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	free_cur(t_gnl_list **head, t_gnl_list *cur,
						int out, char **line)
{
	t_gnl_list	*temp;

	temp = *head;
	if (cur == *head)
	{
		*head = cur->next;
		free(cur->rem);
		free(cur);
	}
	else
	{
		while (temp->next != cur)
			temp = temp->next;
		temp->next = cur->next;
		free(cur->rem);
		free(cur);
	}
	if (out == -1)
	{
		free(*line);
		*line = NULL;
	}
	return (out);
}

static int	n_found(char **line, char **rem, char *p_n)
{
	char	*tmp;

	*p_n = '\0';
	tmp = *line;
	*line = ft_strjoin(*line, *rem);
	if (*line == NULL)
		return (-1);
	free(tmp);
	*p_n = '\n';
	*rem = ft_shift_left(*rem, p_n + 1);
	return (1);
}

void	n_not_found(char **l, char **rem)
{
	char	*tmp;

	tmp = *l;
	*l = ft_strjoin(*l, *rem);
	free(tmp);
	*rem = ft_shift_left(*rem, (*rem) + BUFFER_SIZE);
}

static int	gnl_body(int fd, char **l, char **rem, char *ov)
{
	int		bytes_read;
	char	*p_n;

	while (!(*ov && *rem[0] == '\0'))
	{
		if (*rem[0] == '\0')
		{
			bytes_read = read(fd, *rem, BUFFER_SIZE);
			if (bytes_read == 0)
				*ov = 1;
			if (bytes_read == -1)
				return (-1);
		}
		while (*rem[0] != '\0')
		{
			p_n = ft_strchr_m(*rem, '\n');
			if (*p_n == '\n')
				return (n_found(l, rem, p_n));
			else
				n_not_found(l, rem);
		}
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static t_gnl_list	*head;
	t_gnl_list			*tmp;
	int					out;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	if (head == NULL)
		head = new_list_elem(fd);
	if (head == NULL)
		return (-1);
	tmp = head;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = new_list_elem(fd);
		if (tmp->next == NULL)
			return (-1);
		tmp = tmp->next;
	}
	*line = ft_strnew(1);
	out = gnl_body(tmp->fd, line, &tmp->rem, &tmp->is_over);
	if (out == 0 || out == -1)
		return (free_cur(&head, tmp, out, line));
	else
		return (out);
}
