/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_steklen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:17:59 by amazurok          #+#    #+#             */
/*   Updated: 2018/03/23 11:17:59 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

size_t		ft_steklen(t_stek *stek)
{
	size_t len;

	len = 0;
	if (stek)
	{
		while (stek)
		{
			stek = stek->next;
			len++;
		}
	}
	return (len);
}
