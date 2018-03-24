/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:13:23 by amazurok          #+#    #+#             */
/*   Updated: 2018/03/23 11:14:23 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		ft_is_sort(t_stek *stek, char c)
{
	if (c == '+')
	{
		while (stek && stek->next)
		{
			if (stek->data > stek->next->data)
				return (0);
			stek = stek->next;
		}
	}
	else if (c == '-')
	{
		while (stek && stek->next)
		{
			if (stek->data < stek->next->data)
				return (0);
			stek = stek->next;
		}
	}
	return (1);
}

int		ft_is_n_sort(t_stek *stek, char c, int n)
{
	int i;

	i = 0;
	if (c == '+')
	{
		while (stek->next && i < n)
		{
			if (stek->data > stek->next->data)
				return (0);
			stek = stek->next;
			i++;
		}
	}
	else if (c == '-')
	{
		while (stek->next && i < n)
		{
			if (stek->data < stek->next->data)
				return (0);
			stek = stek->next;
			i++;
		}
	}
	return (1);
}
