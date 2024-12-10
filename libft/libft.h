/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jgoedhar <jgoedhar@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 12:03:34 by jbakker       #+#    #+#                 */
/*   Updated: 2024/12/07 17:17:17 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

# define BUFFER_SIZE 200

typedef struct s_flags
{
	int	hashtag;
	int	space;
	int	plus;
	int	dash;
	int	zero;
	int	dot;
	int	width;
}	t_flags;

typedef struct s_buff
{
	char	*buff;
	int		capacity;
	int		index;
	int		written;
}	t_buff;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_abs(int num);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
int		ft_wordcount(char *ptr);
int		ft_atoi(const char *nptr);
int		ft_split_size(char **array);
int		ft_strcmp(char *s1, char *s2);
int		ft_min_item(int *list, int size);
int		ft_max_item(int *list, int size);
int		ft_min_index(int *list, int size);
int		ft_max_index(int *list, int size);
int		ft_endswith(char *str, char *end);
int		ft_printf(const char *format, ...);
int		ft_putnum(int num, t_flags *flags);
int		ft_putchar(char c, t_flags *flags);
int		ft_putunum(int num, t_flags *flags);
int		ft_putstr(char *str, t_flags *flags);
int		ft_atoi_base(const char *nptr, int base);
int		ft_putvoidptr(void *ptr, t_flags *flags);
int		ft_put_uint(unsigned int numb, int print);
int		ft_safe_atoi(const char *nptr, int *output);
int		ft_write(int force, const char *str, int len);
int		ft_printhex(int num, int hex, t_flags *flags);
int		ft_printf_fd(const char *format, int fd, ...);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		get_flags(const char *format, int index, t_flags *flags);
int		set_flag_value(const char *format, int index, int *flag);

int		*ft_sort_int_list(int *list, int start_index, int end_index);

size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

void	ft_swap(int *a, int *b);
void	ft_bzero(void *s, size_t n);
void	ft_putnbr_fd(int n, int fd);
void	ft_free_split(char **split);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_print_flags(t_flags *flags);
void	ft_putendl_fd(char *s, int fd);
void	ft_print_split(char **split, char *name);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);

char	num_to_hex(int num, char base_case);

char	*ft_itoa(int n);
char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_multijoin(char **strs, char const *sep);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strreplace(char *str, char *old, char *new);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strjoin_duo(char const *s1, char const *sep, char const *s2);

char	**ft_split(char const *s, char c);
char	**ft_split_push(char ***array, char *new);
char	**ft_split_realloc(char **array, int new_size);
char	**ft_split_insert(char ***array, char *new, int index);
char	**ft_split_insert_split(char ***array, char **new, int index);
char	**ft_split_func(char const *s, int (*is_split)(char*), char *hidden);

// Bonus functions

int		ft_lstsize(t_list *lst);

t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	free_array(char **array);

#endif
