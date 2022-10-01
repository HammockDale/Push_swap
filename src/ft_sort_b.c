/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 11:46:33 by hdale             #+#    #+#             */
/*   Updated: 2021/10/03 11:46:35 by hdale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_sort_b_first(t_data *data, int max, int th, int two_th)
{
	int	i;

	i = 0;
	while (i < data->argc - 1 && data->a_size > 5)
	{
		if (data->a_tab->num == data->mas[0] || data->a_tab->num == max
			|| data->a_tab->num <= th)
			ft_ra(&data->a_tab), write(1, "ra\n", 3), i++;
		else if ((data->a_tab->num != max || data->a_tab->num != two_th)
			&& data->a_tab->num > th)
		{
			ft_pb(&data->a_tab, &data->b_tab);
			write(1, "pb\n", 3), i++;
			data->b_tab->flag_p = 0;
			data->b_tab->flag_m = 0, data->a_size--;
			if (data->b_tab->num > two_th && data->b_tab != data->b_tab->next)
				ft_ra(&data->b_tab), write(1, "rb\n", 3);
		}
	}
}

void	ft_sort_b(t_data *data)
{
	int	i;
	int	max;
	int	th;
	int	two_th;

	i = 1;
	max = data->mas[data->argc - 1];
	th = data->mas[data->argc / 3];
	two_th = data->mas[data->argc / 3 * 2];
	ft_sort_b_first(data, max, th, two_th);
	while (data->a_size > 5)
	{
		if (data->a_tab->num == data->mas[0] || data->a_tab->num == max)
			ft_ra(&data->a_tab), write(1, "ra\n", 3);
		else
		{
			ft_pb(&data->a_tab, &data->b_tab);
			write(1, "pb\n", 3), i++, data->b_tab->flag_m = 0;
			data->a_size--, data->b_tab->flag_p = 0;
		}
	}
	ft_us_sort_5(data);
}
