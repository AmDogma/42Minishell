/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 19:41:43 by jovertki          #+#    #+#             */
/*   Updated: 2021/04/16 17:22:36 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 5

typedef struct s_gnl_list
{
	int					fd;
	char				*rem;
	struct s_gnl_list	*next;
	char				is_over;
}				t_gnl_list;

int				get_next_line(int fd, char **line);
size_t			ft_strlen_m(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_shift_left(char *begin, const char *src);
char			*ft_strchr_m(const char *s, int c);
char			*ft_strnew(size_t size);
t_gnl_list		*new_list_elem(int fd);
#endif
