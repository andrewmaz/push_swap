/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:13:11 by amazurok          #+#    #+#             */
/*   Updated: 2018/03/23 11:13:13 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		ft_in_list(t_stek *stek, int num)
{
	int i;

	i = 0;
	if (stek && num >= 0)
	{
		while (i++ < num && stek)
			stek = stek->next;
		if (stek)
			return (stek->data);
	}
	if (stek && num < 0)
	{
		while (stek->next)
			stek = stek->next;
		if (stek)
			return (stek->data);
	}
	return (0);
}
