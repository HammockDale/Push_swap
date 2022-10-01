/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_ps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:39:37 by hdale             #+#    #+#             */
/*   Updated: 2021/10/04 14:39:39 by hdale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_rez(t_data *data)
{
	t_list	*k;
	t_list	*j;

	if (data->b_tab)
		write(1, "KO\n", 3), exit(1);
	k = data->a_tab;
	j = k;
	while (j->next != k)
	{
		j = j->next;
	}
	write(1, "OK\n", 3), exit (1);
	ft_free_all(data);
}

static void	ft_gnl(t_data *data, char **ln)
{
	if ((*ln)[0] == 's' && (*ln)[1] == 'a' && !(*ln)[2])
		ft_sa(&data->a_tab);
	else if ((*ln)[0] == 's' && (*ln)[1] == 'b' && !(*ln)[2])
		ft_sa(&data->b_tab);
	else if ((*ln)[0] == 's' && (*ln)[1] == 's' && !(*ln)[2])
		ft_sa(&data->b_tab), ft_sa(&data->a_tab);
	else if ((*ln)[0] == 'r' && (*ln)[1] == 'a' && !(*ln)[2])
		ft_ra(&data->a_tab);
	else if ((*ln)[0] == 'r' && (*ln)[1] == 'b' && !(*ln)[2])
		ft_ra(&data->b_tab);
	else if ((*ln)[0] == 'r' && (*ln)[1] == 'r' && !(*ln)[2])
		ft_ra(&data->a_tab), ft_ra(&data->b_tab);
	else if ((*ln)[0] == 'p' && (*ln)[1] == 'b' && !(*ln)[2])
		ft_pb(&data->a_tab, &data->b_tab);
	else if ((*ln)[0] == 'p' && (*ln)[1] == 'a' && !(*ln)[2])
		ft_pb(&data->b_tab, &data->a_tab);
	else if ((*ln)[0] == 'r' && (*ln)[1] == 'r' && (*ln)[2] == 'a' && !(*ln)[3])
		ft_rra(&data->a_tab);
	else if ((*ln)[0] == 'r' && (*ln)[1] == 'r' && (*ln)[2] == 'b' && !(*ln)[3])
		ft_rra(&data->a_tab);
	else if ((*ln)[0] == 'r' && (*ln)[1] == 'r' && (*ln)[2] == 'r' && !(*ln)[3])
		ft_rra(&data->a_tab), ft_rra(&data->b_tab);
	else if ((*ln)[0])
		write(1, "Error\n", 6), exit (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	char	*ln;

	ln = NULL;
	if (argc == 1)
		write(1, "Error\n", 6), exit(1);
	argc--;
	argv++;
	if (argc <= 1)
		argc = ft_arg2(&data, &argv, &argc);
	else
		ft_init(&data, argc), data.check = 1;
	ft_full_a(&data, argv), ft_qwic_sort(&data, &data.mas);
	while ((get_next_line(0, &ln)))
		ft_gnl(&data, &ln);
	ft_rez(&data);
	return (0);
}
