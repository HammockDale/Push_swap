/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 11:48:17 by hdale             #+#    #+#             */
/*   Updated: 2021/10/03 11:48:19 by hdale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *)str;
	while (n > 0)
	{
		*temp = (unsigned char) c;
		n--;
		temp++;
	}
	return (str);
}
