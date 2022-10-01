/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_full_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 11:45:39 by hdale             #+#    #+#             */
/*   Updated: 2021/10/03 11:45:41 by hdale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_init(t_data *data, size_t argc)
{
	data->a_tab = NULL;
	data->b_tab = NULL;
	data->diario = NULL;
	data->a_size = argc;
	data->b_size = 0;
	data->argc = argc;
	data->jornal = NULL;
	data->mas = NULL;
	data->j = 2;
	data->b = 0;
	data->check = 0;
	data->str = 0;
	data->mas = (int *)malloc((argc + 1) * sizeof(int));
	if (!data->mas)
	{
		write(1, "Error\n", 6);
		exit (1);
	}
	data->mas[argc + 1] = 0;
}

static void	ft_full_a_next(t_data *data, char **argv, t_list **tmp, int r)
{
	int	i;
	int	c;

	i = 0;
	c = 1;
	while (++i < data->argc)
	{
		 (*tmp)->next = (t_list *)malloc(sizeof(t_list));
		if (!(*tmp)->next)
			write(1, "Error\n", 6), exit (1);
		(*tmp)->next->last = *tmp;
		(*tmp) = (*tmp)->next;
		(*tmp)->num = ft_atoi(argv[i]);
		data->mas[i] = (*tmp)->num;
		if (r >= (*tmp)->num && c == 1)
			c = 0;
		else
			r = (*tmp)->num;
		(*tmp)->flag_p = 0;
		(*tmp)->flag_m = 0;
	}
	if (c == 1 && data->check != 1)
		exit (0);
}

void	ft_full_a(t_data *data, char **argv)
{
	t_list	*tmp;
	int		r;

	data->a_size = data->argc;
	tmp = NULL;
	tmp = (t_list *)malloc(sizeof(t_list));
	if (!tmp)
		write(1, "Error\n", 6), exit (1);
	tmp->num = ft_atoi(argv[0]);
	data->mas[0] = tmp->num;
	r = tmp->num;
	tmp->flag_p = 0;
	tmp->flag_m = 0;
	data->a_tab = tmp;
	ft_full_a_next(data, argv, &tmp, r);
	tmp->next = data->a_tab;
	data->a_tab->last = tmp;
	data->a_tab->next->last = data->a_tab;
}
