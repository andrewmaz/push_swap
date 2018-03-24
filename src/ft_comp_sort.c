/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comp_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:11:32 by amazurok          #+#    #+#             */
/*   Updated: 2018/03/24 12:45:35 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void		ft_comp_sort(t_data *data, int nb)
{
	if (nb == 1)
	{
		if (ft_in_list(data->b, 1) > ft_in_list(data->b, 0))
			ft_swap(data, 'b', 9);
	}
	else if (nb == 2)
	{
		if (ft_in_list(data->b, 0) < ft_in_list(data->b, -1))
			ft_rotate(data, 'b', 9);
	}
	else if (nb == 3)
	{
		if (ft_in_list(data->b, 0) < ft_in_list(data->b, -1))
			ft_rev_rotate(data, 'b', 9);
	}
}
