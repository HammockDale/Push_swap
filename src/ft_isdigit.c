/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 11:45:50 by hdale             #+#    #+#             */
/*   Updated: 2021/10/03 11:45:53 by hdale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_isdigit(int c)
{
	unsigned char	ch;

	ch = (unsigned char) c;
	if (ch >= '0' && ch <= '9')
	{
		return (1);
	}
	return (0);
}