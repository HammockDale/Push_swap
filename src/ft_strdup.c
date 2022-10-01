/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 11:47:03 by hdale             #+#    #+#             */
/*   Updated: 2021/10/03 11:47:09 by hdale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	size_t	s;
	size_t	d;

	d = 0;
	s = ft_strlen(src);
	str = (char *)malloc(sizeof(char) * (s + 1));
	if (!str)
		return (NULL);
	while (d < s && src[d])
	{
		str[d] = src[d];
		d++;
	}
	str[d] = 0;
	return (str);
}
