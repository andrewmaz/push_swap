/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:14:39 by amazurok          #+#    #+#             */
/*   Updated: 2018/03/23 11:15:00 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stek		*ft_new_elem(void)
{
	t_stek *a;

	a = (t_stek*)malloc(sizeof(t_stek));
	a->data = 0;
	a->next = NULL;
	a->prev = NULL;
	return (a);
}

t_data		*ft_new_data(t_data *data)
{
	data = (t_data*)malloc(sizeof(t_data));
	data->a = NULL;
	data->b = NULL;
	data->cmd = NULL;
	return (data);
}

t_block		*ft_new_block(void)
{
	t_block *block;

	block = (t_block*)malloc(sizeof(t_block));
	block->len = 0;
	block->ser = 0;
	block->rot = 0;
	block->next = NULL;
	return (block);
}
