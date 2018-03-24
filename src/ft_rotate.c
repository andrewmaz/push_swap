/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:16:46 by amazurok          #+#    #+#             */
/*   Updated: 2018/03/23 11:16:51 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void			ft_rotate(t_data *data, char st, int cmd)
{
	int		tmp;
	t_stek	*tmp_s;

	if (st == 'r')
	{
		ft_rotate(data, 'a', 0);
		ft_rotate(data, 'b', 0);
		return ;
	}
	if (!(tmp_s = (st == 'a' ? data->a : data->b)) && ft_steklen(tmp_s) < 2)
		return ;
	tmp = tmp_s->data;
	while (tmp_s && tmp_s->next)
	{
		tmp_s->data = tmp_s->next->data;
		tmp_s = tmp_s->next;
	}
	tmp_s->data = tmp;
	if (cmd)
	{
		st == 'a' ? ft_comp_sort(data, cmd) : 0;
		data->cmd = ft_realloc(data->cmd, ft_strlen(data->cmd) + 3);
		data->cmd = st == 'a' ? ft_strcat(data->cmd, "ra\n") : \
			ft_strcat(data->cmd, "rb\n");
	}
}

static int		ft_helprevrot(t_data *data, char st)
{
	int		tmp;
	t_stek	*tmp_s;

	tmp_s = (st == 'a' ? data->a : data->b);
	if (ft_steklen(tmp_s) < 2)
		return (0);
	while (tmp_s && tmp_s->next)
		tmp_s = tmp_s->next;
	if (tmp_s)
		tmp = tmp_s->data;
	while (tmp_s && tmp_s->prev)
	{
		tmp_s->data = tmp_s->prev->data;
		tmp_s = tmp_s->prev;
	}
	if (tmp_s)
		tmp_s->data = tmp;
	return (1);
}

void			ft_rev_rotate(t_data *data, char st, int cmd)
{
	if (st == 'r')
	{
		ft_rev_rotate(data, 'a', 0);
		ft_rev_rotate(data, 'b', 0);
		return ;
	}
	if (ft_helprevrot(data, st) && cmd)
	{
		st == 'a' ? ft_comp_sort(data, cmd) : 0;
		data->cmd = ft_realloc(data->cmd, ft_strlen(data->cmd) + 4);
		if (st == 'a')
			data->cmd = ft_strcat(data->cmd, "rra\n");
		else if (st == 'b')
			data->cmd = ft_strcat(data->cmd, "rrb\n");
	}
}
