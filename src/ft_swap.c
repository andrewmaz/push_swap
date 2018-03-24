/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:18:09 by amazurok          #+#    #+#             */
/*   Updated: 2018/03/23 11:18:09 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_swap(t_data *data, char st, int cmd)
{
	t_stek	*tmp_s;
	int		tmp;

	if (st == 's')
	{
		ft_swap(data, 'a', 0);
		ft_swap(data, 'b', 0);
		return ;
	}
	tmp_s = (st == 'a' ? data->a : data->b);
	if (tmp_s && tmp_s->next)
	{
		tmp = tmp_s->data;
		tmp_s->data = tmp_s->next->data;
		tmp_s->next->data = tmp;
		if (cmd)
		{
			ft_comp_sort(data, cmd);
			data->cmd = ft_realloc(data->cmd, ft_strlen(data->cmd) + 3);
			if (st == 'a')
				data->cmd = ft_strcat(data->cmd, "sa\n");
			else if (st == 'b')
				data->cmd = ft_strcat(data->cmd, "sb\n");
		}
	}
}
