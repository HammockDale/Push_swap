/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 11:45:28 by hdale             #+#    #+#             */
/*   Updated: 2021/10/03 11:45:30 by hdale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free_all(t_data *data)
{
	int		i;
	t_list	*tmp;

	data->a_tab->last->next = NULL;
	data->a_tab->last = NULL;
	i = 0;
	while (i < data->argc)
	{
		tmp = data->a_tab;
		data->a_tab = data->a_tab->next, i++;
		if (data->a_tab && data->a_tab->last)
			data->a_tab->last = NULL;
		if (tmp)
		{
			if (tmp->last)
			{
				tmp->last = NULL;
				tmp->next = NULL;
			}
			free(tmp);
		}
	}
	free(data->mas);
	if (data->str)
		exit(0);
}
