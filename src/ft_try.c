/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_try.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 11:46:44 by hdale             #+#    #+#             */
/*   Updated: 2021/10/03 11:46:46 by hdale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_try_sort_to_a(t_data data, t_list *a_tab, int *flag)
{
	if (data.b_tab->num < a_tab->num && data.b_tab->num > a_tab->last->num)
		return ;
	(*flag)++;
	ft_ra (&a_tab);
	return (ft_try_sort_to_a(data, a_tab, flag));
}

static void	ft_try_sort_to_ar(t_data data, t_list *a_tab, int *flag)
{
	if (data.b_tab->num < a_tab->num && data.b_tab->num > a_tab->last->num)
		return ;
	(*flag)--;
	ft_rra (&a_tab);
	return (ft_try_sort_to_ar(data, a_tab, flag));
}

static void	ft_try_next(t_data *data, int *min_f, int *f, int *rf)
{
	if (ft_mod(data->b_tab->flag_p) + *f < (ft_mod(*min_f) + ft_mod(data->b)))
	{
		*min_f = data->b_tab->flag_p;
		data->b = ft_re_mod(*f, *rf);
	}
	ft_try_sort_to_ar(*data, data->a_tab, &data->b_tab->flag_m);
	if (ft_mod(data->b_tab->flag_m) + *f < (ft_mod(*min_f) + ft_mod(data->b)))
	{
		*min_f = data->b_tab->flag_m;
		data->b = ft_re_mod(*f, *rf);
	}
	data->b_tab = data->b_tab->next;
}

static void	ft_try_f(t_data *data, int *f, int *rf)
{
	if (*f > data->b_size || *rf < 0)
	{
		(*f)--;
		(*rf)--;
	}
	else
		(*f)++;
}

int	ft_try(t_data *data, int min_f, int f, int rf)
{
	t_list	*tmp;

	tmp = data->b_tab;
	while (1)
	{
		data->b_size = (data->argc - data->a_size - 1) / 2;
		if (!data->b_tab)
			return (0);
		data->b_tab->flag_p = 0;
		data->b_tab->flag_m = 0;
		ft_try_sort_to_a(*data, data->a_tab, &data->b_tab->flag_p);
		if ((data->b_tab->flag_p + f) == 0)
		{
			ft_pb(&data->b_tab, &data->a_tab), write(1, "pa\n", 3);
			data->a_size++;
			return (ft_try(data, 10000, 0, 0));
		}
		ft_try_next(data, &min_f, &f, &rf);
		if (data->b_tab == tmp)
			return (min_f);
		ft_try_f(data, &f, &rf);
	}
}
