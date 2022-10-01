/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:01:00 by hdale             #+#    #+#             */
/*   Updated: 2021/10/04 14:01:03 by hdale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	n;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(sizeof(char) * (i));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	n = 0;
	while (s2[n] != '\0')
	{
		str[i + n] = s2[n];
		n++;
	}
	str[i + n] = '\0';
	return (str);
}

int	ft_new_strjoin(char **line, char **ost)
{
	char	*tmp;
	char	*new;

	new = *ost;
	tmp = *line;
	*line = ft_strjoin(*line, new);
	if (!(*line))
	{
		free(tmp);
		free(new);
		*ost = NULL;
		return (-1);
	}
	free(tmp);
	if (!(new))
		return (-1);
	free(new);
	*ost = NULL;
	return (0);
}
