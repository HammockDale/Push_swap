/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 11:46:25 by hdale             #+#    #+#             */
/*   Updated: 2021/10/03 11:46:26 by hdale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_sort_to_a_next(t_data *data, int *min_f, int i)
{
	while (*min_f > 0 && *min_f > i)
	{
		ft_ra(&data->a_tab), i++;
		if (data->b > 0)
			ft_ra(&data->b_tab), write(1, "rr\n", 3), data->b--;
		else
			write(1, "ra\n", 3);
	}
	while (*min_f < 0 && *min_f < -i)
	{
		ft_rra(&data->a_tab), i++;
		if (data->b < 0)
			ft_rra(&data->b_tab), write(1, "rrr\n", 4), data->b++;
		else
			write(1, "rra\n", 4);
	}
}

static void	ft_if_func(t_data *data, int min_f)
{
	while (data->b > 0)
	{
		while (data->b_tab && data->b_tab != data->b_tab->next
			&& (data->b_tab->flag_p != min_f
				&& data->b_tab->flag_m != min_f))
			ft_ra(&data->b_tab), write(1, "rb\n", 3);
		data->b--;
	}
	while (data->b < 0)
	{
		while (data->b_tab && data->b_tab != data->b_tab->last
			&& (data->b_tab->flag_p != min_f
				&& data->b_tab->flag_m != min_f))
			ft_rra(&data->b_tab), write(1, "rrb\n", 4);
		data->b++;
	}
}

void	ft_sort_to_a(t_data *data)
{
	int		min_f;

	while (data->b_tab)
	{
		data->b = 0;
		min_f = 0;
		if (min_f == 0 && data->b_tab)
			min_f = ft_try(data, 10000, 0, 0);
		ft_sort_to_a_next(data, &min_f, 0);
		while (data->b > 0)
		{
			while (data->b_tab && data->b_tab != data->b_tab->next
				&& (data->b_tab->flag_p != min_f
					&& data->b_tab->flag_m != min_f))
				ft_ra(&data->b_tab), write(1, "rb\n", 3);
			data->b--;
		}
		while (data->b < 0)
		{
			while (data->b_tab->flag_p != min_f && data->b_tab->flag_m != min_f)
				ft_rra(&data->b_tab), write(1, "rrb\n", 4);
			data->b++;
		}
		ft_if_func(data, min_f);
	}
}
