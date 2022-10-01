/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 11:49:22 by hdale             #+#    #+#             */
/*   Updated: 2021/10/03 11:49:24 by hdale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;
	size_t	n;

	n = count * size;
	str = (void *)malloc(n);
	if (!str)
		return (NULL);
	ft_bzero(str, n);
	return (str);
}
