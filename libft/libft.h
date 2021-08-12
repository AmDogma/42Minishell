/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:55:32 by jovertki          #+#    #+#             */
/*   Updated: 2021/07/20 20:11:26 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 1000

typedef struct s_gnl_list
{
	int					fd;
	char				*rem;
	struct s_gnl_list	*next;
	char				is_over;
}					t_gnl_list;

int					get_next_line(int fd, char **line);
size_t				ft_strlen_m(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_shift_left(char *begin, const char *src);
char				*ft_strchr_m(const char *s, int c);
char				*ft_strnew(size_t size);
char				*ft_skip_chars(char *str, char *skip, int *cur_pos);
char				ft_isspace(char c);
char				*ft_strcpy(char *dest, const char *src);
size_t				ft_strlen(const char *s);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strdup(const char *s1);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_bzero(void *b, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *hay, const char *ndl, size_t len);
void				*ft_calloc(size_t count, size_t size);
void				ft_putnbr_fd(long long int n, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *set);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_snumlen(long long num);
int					ft_unumlen(unsigned long long num);
long long			min(long long num1, long long num2);
long long			max(long long num1, long long num2);
unsigned long long	ft_abs(long long num);
double				ft_abs_f(double num);
void				ft_putnbrhd_fd(unsigned long long n, int fd, char x);
int					ft_unumlen_hd(unsigned long long num);
void				ft_putnbru_fd(unsigned long long n, int fd);
long long			power_i(long long num, int power);
double				power_d(double num, int power);
void				ft_putfnbr_fd(double n, int prec, int fd);
char				*ft_strjoin_ff(char *s1, char const *s2);
char				*ft_strjoin_fs(char const *s1, char *s2);
char				*ft_strjoin_fb(char *s1, char *s2);
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
int					ft_getsign(int num);
void				ft_selectsort(int *arr, unsigned int len, char mod);
void				ft_free(void **pointer);
void				*ft_crealloc(void **ptr, size_t old_size, size_t size);
#endif
