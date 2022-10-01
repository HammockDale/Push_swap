/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:40:01 by hdale             #+#    #+#             */
/*   Updated: 2021/10/04 14:40:03 by hdale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	argv++;
	argc--;
	if (argc <= 1)
		argc = ft_arg2(&data, &argv, &argc);
	else
		ft_init(&data, argc);
	ft_full_a(&data, argv), ft_qwic_sort(&data, &data.mas);
	if (argc <= 5)
		return (ft_ar_men6(&data, argc));
	i = 1;
	while (i < argc + 1)
		data.a_tab = data.a_tab->next, i++;
	ft_sort_b(&data), i = 0, ft_sort_to_a(&data);
	while (data.a_tab->num != data.mas[0])
	{
		if (data.a_tab->num > data.mas[data.argc / 2])
			ft_ra(&data.a_tab), write(1, "ra\n", 3);
		else
			ft_rra(&data.a_tab), write(1, "rra\n", 4);
	}
	i = 1, ft_free_all(&data);
	return (0);
}
