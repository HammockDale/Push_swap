/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 11:45:18 by hdale             #+#    #+#             */
/*   Updated: 2021/10/03 11:45:21 by hdale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sa(t_list **p)
{
	if (*p != (*p)->next)
	{
		(*p)->num = (*p)->num ^ (*p)->next->num;
		(*p)->next->num = (*p)->num ^ (*p)->next->num;
		(*p)->num = (*p)->num ^ (*p)->next->num;
	}
}

void	ft_pb(t_list **one, t_list **two)
{
	t_list	*tmp;
	t_list	*b;

	if (!*one)
		write(1, "Error\n", 6), exit (1);
	b = NULL;
	if (!(*one) || (*one)->next == *one)
		tmp = NULL;
	else
	{
		tmp = (*one)->next;
		tmp->last = (*one)->last;
		tmp->last->next = tmp;
	}
	ft_pb_next(two, one, b);
	*one = tmp;
}

void	ft_pb_next(t_list **two, t_list **one, t_list *b)
{
	if (!(*two))
	{
		*two = *one;
		(*two)->next = *two;
		(*two)->next->last = *two;
	}
	else
	{
		b = (*two);
		(*two) = *one;
		(*one)->last = (b)->last;
		(*one)->next = b;
		(*two)->next->last = *two;
		(*two)->last->next = *two;
	}
}

void	ft_ra(t_list **x)
{
	*x = (*x)->next;
}

void	ft_rra(t_list **x)
{
	*x = (*x)->last;
}
