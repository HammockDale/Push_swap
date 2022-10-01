/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:01:06 by hdale             #+#    #+#             */
/*   Updated: 2021/09/26 15:01:11 by hdale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_atoi_next(char **copy, int *tmp, int i)
{
	if (!ft_isdigit(**copy))
		write(1, "Error\n", 6), exit (1);
	while (ft_isdigit(**copy))
	{
		if (i > 0)
		{
			if (*tmp * 10 < *tmp)
				write(1, "Error\n", 6), exit (1);
			*tmp = (*tmp * 10) + (**copy - '0');
		}
		else
		{
			if (*tmp * 10 > *tmp)
				write(1, "Error\n", 6), exit (1);
			*tmp = (*tmp * 10) - (**copy - '0');
		}
		(*copy)++;
	}
}

int	ft_atoi(const char *str)
{
	int		i;
	int		tmp;
	char	*copy;

	copy = (char *)str;
	i = 1;
	tmp = 0;
	while (*copy != 0 && ((*copy >= 9 && *copy <= 13) || *copy == 32))
		copy++;
	if (*copy == '-')
		i = -i;
	if ((copy + 1) && (*copy == '-' || *copy == '+')
		&& (ft_isdigit(*(copy + 1))))
		copy++;
	ft_atoi_next(&copy, &tmp, i);
	if (*copy && !ft_isdigit(*copy) && ((*copy < 9
				&& *copy > 13) || *copy != 32))
		write(1, "Error\n", 6), exit (1);
	return (tmp);
}
