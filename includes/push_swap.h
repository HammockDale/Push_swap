/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:40:24 by hdale             #+#    #+#             */
/*   Updated: 2021/10/04 14:40:26 by hdale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif
typedef struct s_list
{
	int				num;
	int				flag_p;
	int				flag_m;
	struct s_list	*next;
	struct s_list	*last;
}					t_list;

typedef struct s_data
{
	char	**diario;
	t_list	*jornal;
	t_list	*a_tab;
	t_list	*b_tab;
	int		*mas;
	int		argc;
	int		a_size;
	int		b_size;
	int		j;
	int		b;
	int		check;
	int		str;
}			t_data;

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	*ft_memset(void *str, int c, size_t n);
char	*ft_strdup(const char *src);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);
void	ft_free_all(t_data *data);
void	ft_full_a(t_data *data, char **argv);
void	ft_init(t_data *data, size_t argc);
int		ft_arg2(t_data *data, char ***argv, int *argc);
void	ft_qwic_sort(t_data *data, int **mas);
void	ft_sa(t_list **p);
void	ft_pb(t_list **one, t_list **two);
void	ft_pb_next(t_list **two, t_list **one, t_list *b);
void	ft_ra(t_list **x);
void	ft_rra(t_list **x);
int		ft_ar_men6(t_data *data, int argc);
void	ft_us_sort_5(t_data *data);
void	ft_us_sort_5_next(t_data *data);
void	ft_us_sort_3(t_list **p, t_data *data);
void	ft_sort_b(t_data *data);
void	ft_sort_to_a(t_data *data);
int		ft_try(t_data *data, int min_f, int f, int rf);
int		ft_mod(int flag);
int		ft_re_mod(int flag, int znac);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
void	ft_clean(char **mass, size_t k);
int		get_next_line(int fd, char **line);
char	*ft_strjoin(char const *s1, char const *s2);
int		get_next_line(int fd, char **line);
int		ft_new_strjoin(char **line, char **ost);

#endif
