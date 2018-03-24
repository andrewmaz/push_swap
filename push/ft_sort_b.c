/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 12:38:18 by amazurok          #+#    #+#             */
/*   Updated: 2018/03/14 17:53:18 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	ft_helwh(t_block **block, t_data *data)
{
	int ser;

	while ((*block)->rot > 0)
	{
		ft_rev_rotate(data, 'b', 9);
		(*block)->rot--;
		(*block)->len++;
	}
	while (!(*block)->len && !(*block)->rot)
		ft_del_block(block);
	while ((*block)->rot > 0)
	{
		ft_rev_rotate(data, 'b', 9);
		(*block)->rot--;
		(*block)->len++;
	}
	ser = ft_n_ser(data->b, (*block)->len);
	return (ser);
}

static void	ft_els_push(t_block *block, t_data *data, int *push)
{
	ft_set_val(push, &block->len, *push + 1, block->len - 1);
	ft_push(data, 'a');
}

static void	ft_els_rot(t_block *block, t_data *data)
{
	ft_set_val(&block->rot, &block->len, block->rot + 1, block->len - 1);
	ft_rotate(data, 'b', 9);
}

static void	ft_if_help(t_block **block, t_data *data, int *push, int *ser)
{
	if ((*block)->len > 0 && (*block)->rot > 0)
	{
		while ((*block)->len > 0)
		{
			ft_rotate(data, 'b', 9);
			(*block)->rot++;
			(*block)->len--;
		}
		*ser = ft_n_ser(data->b, -(*block)->rot);
		while ((*block)->rot > 0)
		{
			ft_rev_rotate(data, 'b', 9);
			if (data->b->data >= *ser)
			{
				ft_push(data, 'a');
				++*push;
				(*block)->len--;
			}
			(*block)->rot--;
			(*block)->len++;
		}
	}
	else
		*ser = ft_helwh(block, data);
}

t_block		*ft_sort_b(t_data *data, t_block *block)
{
	int ser;
	int push;

	ser = ft_n_ser(data->b, block->len);
	push = 0;
	while (data->b)
	{
		if (ft_check(data->b, ser, '-'))
		{
			ft_sort_a(data, &block, push);
			while (!block->len && !block->rot)
				ft_del_block(&block);
			push = 0;
			ft_if_help(&block, data, &push, &ser);
		}
		else if (ft_in_list(data->b, 0) >= ser)
			ft_els_push(block, data, &push);
		else
			ft_els_rot(block, data);
	}
	ft_sort_up_three(data);
	return (block);
}
