/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 11:46:01 by hdale             #+#    #+#             */
/*   Updated: 2021/10/03 11:46:03 by hdale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_mod(int flag)
{
	if (flag >= 0)
		return (flag);
	else
		return (-flag);
}

int	ft_re_mod(int flag, int znac)
{
	if (znac >= 0)
		return (flag);
	else
		return (-flag);
}
