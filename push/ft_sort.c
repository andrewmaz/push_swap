/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:03:53 by amazurok          #+#    #+#             */
/*   Updated: 2018/03/23 11:04:26 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void		ft_sort_three(t_data *data)
{
	while (!ft_is_sort(data->a, '+'))
	{
		if (ft_in_list(data->a, 0) > ft_in_list(data->a, -1) && \
			ft_in_list(data->a, 0) > ft_in_list(data->a, 1))
			ft_rotate(data, 'a', 9);
		else if (ft_in_list(data->a, 0) > ft_in_list(data->a, 1))
			ft_swap(data, 'a', 1);
		else
			ft_rev_rotate(data, 'a', 9);
	}
}

void		ft_sort_up_three(t_data *data)
{
	int rot;

	rot = 0;
	while (!ft_is_n_sort(data->a, '+', 3) || rot)
	{
		if (ft_in_list(data->a, 0) > ft_in_list(data->a, 1))
			ft_swap(data, 'a', 1);
		else if ((ft_in_list(data->a, -1) < ft_in_list(data->a, 0) || \
				ft_in_list(data->a, -1) < ft_in_list(data->a, 1)) && rot > 0)
		{
			rot--;
			ft_rev_rotate(data, 'a', 9);
		}
		else
		{
			ft_rotate(data, 'a', 9);
			rot++;
		}
	}
}

void		ft_sort(t_data *data)
{
	t_block *block;

	if (ft_is_sort(data->a, '+'))
		return ;
	block = ft_ser_a(data, NULL);
	while (ft_steklen(data->a) > 3)
	{
		if (ft_check(data->a, block->ser, '+'))
			block = ft_ser_a(data, block);
		else if (ft_in_list(data->a, -1) < block->ser &&\
				ft_in_list(data->a, -1) < ft_in_list(data->a, 0))
			ft_rev_rotate(data, 'a', 9);
		else if (ft_in_list(data->a, 0) < block->ser)
			ft_push(data, 'b');
		else
			ft_rotate(data, 'a', 2);
	}
	ft_sort_three(data);
	block = ft_ser_a(data, block);
	while (block && !block->len)
		ft_del_block(&block);
	if (data->b && block)
		block = ft_sort_b(data, block);
	if (block)
		ft_del_block(&block);
}
