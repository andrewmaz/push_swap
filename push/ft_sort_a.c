/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:04:43 by amazurok          #+#    #+#             */
/*   Updated: 2018/03/23 11:04:43 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static t_block	*ft_newlen(t_block *block, int len)
{
	t_block *new;

	new = ft_new_block();
	new->len = len;
	new->next = block;
	return (new);
}

static void		ft_wh(t_data *data, int *rot, int *push)
{
	while (*rot > 0)
	{
		ft_rev_rotate(data, 'a', 9);
		ft_set_val(push, rot, *push + 1, *rot - 1);
	}
	*push <= 3 ? ft_sort_up_three(data) : 0;
}

static void		ft_sorta(t_data *data, t_block **block, int *push)
{
	int ser;
	int ret;
	int rot;

	ft_set_val(&ret, &rot, 0, 0);
	ser = ft_n_ser(data->a, *push);
	while (!ft_check(data->a, ser, '+') && push > 0)
	{
		if (ft_in_list(data->a, 0) < ser && \
				ft_in_list(data->a, 0) < ft_in_list(data->a, 1))
		{
			ft_push(data, 'b');
			ft_set_val(&ret, push, ret + 1, *push - 1);
		}
		else if (ft_in_list(data->a, 1) < ser && \
				ft_in_list(data->a, 1) < ft_in_list(data->a, 0))
			ft_swap(data, 'a', 1);
		else
		{
			ft_set_val(&rot, push, rot + 1, *push - 1);
			ft_rotate(data, 'a', 9);
		}
	}
	*block = ft_newlen(*block, ret);
	ft_wh(data, &rot, push);
}

void			ft_sort_a(t_data *data, t_block **block, int push)
{
	while (!ft_is_sort(data->a, '+') && push > 3)
		ft_sorta(data, block, &push);
	ft_sort_up_three(data);
}
