/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qwic_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 11:46:14 by hdale             #+#    #+#             */
/*   Updated: 2021/10/03 11:46:16 by hdale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_qwic_sort(t_data *data, int **mas)
{
	int	i;
	int	j;

	j = 1;
	while (j == 1)
	{
		j = 0;
		i = 0;
		while (i < data->a_size - 1)
		{
			if ((*mas)[i] == (*mas)[i + 1])
				write(1, "Error\n", 6), exit(1);
			if ((*mas)[i] > (*mas)[i + 1])
			{
				(*mas)[i + 1] = (*mas)[i + 1] ^ (*mas)[i];
				(*mas)[i] = (*mas)[i + 1] ^ (*mas)[i];
				(*mas)[i + 1] = (*mas)[i + 1] ^ (*mas)[i];
				j = 1;
			}
			i++;
		}
	}
}
