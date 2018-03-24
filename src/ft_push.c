/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:15:20 by amazurok          #+#    #+#             */
/*   Updated: 2018/03/23 11:15:20 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	ft_push_b(t_data *data)
{
	t_stek *tmp;

	if (data->b)
	{
		tmp = data->b;
		data->b->prev = ft_new_elem();
		data->b = data->b->prev;
		data->b->next = tmp;
	}
	else
		data->b = ft_new_elem();
	data->b->data = data->a->data;
	ft_del_last(&data->a);
	data->cmd = ft_strcat(data->cmd, "pb\n");
}

void		ft_push(t_data *data, char stek)
{
	t_stek *tmp;

	data->cmd = ft_realloc(data->cmd, ft_strlen(data->cmd) + 3);
	if (stek == 'a' && data->b)
	{
		if (data->a)
		{
			tmp = data->a;
			data->a->prev = ft_new_elem();
			data->a = data->a->prev;
			data->a->next = tmp;
		}
		else
			data->a = ft_new_elem();
		data->a->data = data->b->data;
		ft_del_last(&data->b);
		data->cmd = ft_strcat(data->cmd, "pa\n");
	}
	else if (stek == 'b' && data->a)
		ft_push_b(data);
}
