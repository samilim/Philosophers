/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 18:25:14 by salimon           #+#    #+#             */
/*   Updated: 2022/06/27 09:59:26 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

#define BUFFER_SIZE 50

typedef struct s_node
{
	void			*content;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

long long int		ft_atoll(const char *nb);
long long int		*ft_llintabdup(long long int *tab, int size);
void				*ft_memset(void *mem, int ch, size_t n);
void				ft_bzero(void *mem, size_t n);
void				free_matrice(char **tab);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int ch, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *mem, int ch, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isfloat(char *str);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *str, int ch);
char				*ft_strrchr(const char *str, int ch);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strnstr(const char *str, const char *to_find, size_t n);
int					ft_atoi(const char *nb);
void				*ft_calloc(size_t nmb, size_t size);
char				*ft_strdup(const char *src);
char				*ft_substr(char const *str, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *str, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int nb, int fd);
t_node				*ft_lstnew(void *content);
void				ft_lstadd_front(t_node **alst, t_node *new);
int					ft_lstsize(t_node *lst);
t_node				*ft_lstlast(t_node *lst);
void				ft_lstadd_back(t_node **alst, t_node *new);
void				ft_lstdelone(t_node *lst, void (*del)(void*));
void				ft_lstclear(t_node **lst, void (*del)(void*));
void				ft_lstiter(t_node *lst, void (*f)(void *));
t_node				*ft_lstmap(t_node *lst, void *(*f)(void *),
						void (*del)(void *));
int					get_next_line(int fd, char **line);

#endif
