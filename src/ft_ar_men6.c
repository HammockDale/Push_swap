/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ar_men6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 11:44:58 by hdale             #+#    #+#             */
/*   Updated: 2021/10/03 11:45:00 by hdale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_arg2(t_data *data, char ***argv, int *argc)
{
	char	**str;
	int		i;

	i = 0;
	if (*argc == 0)
		exit (1);
	str = ft_split((*argv)[0], ' ');
	while (str[i])
	{
		i++;
	}
	if (i <= 1)
		exit (1);
	ft_init(data, i);
	data->str = 1;
	*argv = str;
	*argc = i;
	return (i);
}

int	ft_ar_men6(t_data *data, int argc)
{
	if (argc == 2)
	{
		if (data->a_tab->num > data->a_tab->next->num)
			ft_sa(&data->a_tab), write(1, "sa\n", 3);
		ft_free_all(data);
		return (0);
	}
	if (argc == 3)
	{
		ft_us_sort_3(&data->a_tab, data);
		if (data->a_tab->num > data->a_tab->next->num)
			ft_ra(&data->a_tab), write(1, "ra\n", 3);
		else if (data->a_tab->num > data->a_tab->last->num)
			ft_rra(&data->a_tab), write(1, "rra\n", 4);
		ft_free_all(data);
		return (0);
	}
	if (argc <= 5)
	{
		ft_us_sort_5(data), ft_free_all(data);
		return (0);
	}
	return (0);
}

void	ft_us_sort_5_next(t_data *data)
{
	ft_us_sort_3(&data->a_tab, data);
	if (data->a_tab->num > data->a_tab->next->num)
		ft_ra(&data->a_tab), write(1, "ra\n", 3);
	else if (data->a_tab->num > data->a_tab->last->num)
	{
		ft_rra(&data->a_tab), write(1, "rra\n", 4);
	}
	if (data->b_tab->num < data->b_tab->next->num)
		ft_sa(&data->b_tab), write(1, "sb\n", 3);
	ft_pb(&data->b_tab, &data->a_tab), write(1, "pa\n", 3), data->a_size++;
	if (data->a_tab->num > data->a_tab->next->num)
		ft_sa(&data->a_tab), write(1, "sa\n", 3);
	ft_pb(&data->b_tab, &data->a_tab), write(1, "pa\n", 3), data->a_size++;
	if (data->a_tab->num > data->a_tab->next->num)
		ft_sa(&data->a_tab), write(1, "sa\n", 3);
}

void	ft_us_sort_5(t_data *data)
{
	int	*buf;
	int	i;

	i = 0;
	buf = (int *)malloc(sizeof(int) * (data->a_size));
	if (!buf)
		write(1, "Error\n", 6), exit (1);
	while (i < data->a_size)
	{
		buf[i++] = data->a_tab->num;
		data->a_tab = data->a_tab->next;
	}
	ft_qwic_sort(data, &buf), i = 0;
	while (i < 2)
	{
		if (data->a_tab->num == buf[3]
			|| (buf[4] && data->a_tab->num == buf[4]))
			ft_ra(&data->a_tab), write(1, "ra\n", 3);
		else
		{
			ft_pb(&data->a_tab, &data->b_tab);
			write(1, "pb\n", 3), data->a_size--, i++;
		}
	}
	ft_us_sort_5_next(data), free(buf);
}

void	ft_us_sort_3(t_list **p, t_data *data)
{
	if ((*p)->num > (*p)->next->num)
	{
		if ((*p)->next->num > (*p)->last->num
			&& (*p)->num == data->mas[data->argc - 1])
		{
			ft_sa(p), write(1, "sa\n", 3);
		}
		else if ((*p)->next->num < (*p)->last->num
			&& (*p)->last->num == data->mas[data->argc - 1])
		{
			ft_sa(p), write(1, "sa\n", 3);
		}
	}
	else if ((*p)->next->num > (*p)->last->num
		&& (*p)->num == data->mas[data->argc - 1])
		ft_sa(p), write(1, "sa\n", 3);
	else if ((*p)->num < (*p)->last->num
		&& (*p)->next->num == data->mas[data->argc - 1])
		ft_sa(p), write(1, "sa\n", 3);
}
