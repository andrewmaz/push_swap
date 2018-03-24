/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:11:54 by amazurok          #+#    #+#             */
/*   Updated: 2018/03/23 11:12:05 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_del_stek(t_stek *stek)
{
	t_stek *tmp;

	if (!stek)
		return ;
	while (stek)
	{
		tmp = stek->next;
		free(stek);
		stek = tmp;
	}
}

void	ft_del_data(t_data *data)
{
	ft_del_stek(data->a);
	ft_del_stek(data->b);
	ft_strdel(&data->cmd);
	free(data);
}
