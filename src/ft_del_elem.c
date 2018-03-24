/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:12:23 by amazurok          #+#    #+#             */
/*   Updated: 2018/03/23 11:12:27 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_del_last(t_stek **stek)
{
	t_stek *tmp;

	tmp = *stek;
	if (tmp && tmp->next)
	{
		tmp = tmp->next;
		free(tmp->prev);
		tmp->prev = NULL;
	}
	else
	{
		free(tmp);
		tmp = NULL;
	}
	*stek = tmp;
}

void	ft_del_block(t_block **block)
{
	t_block *new;
	t_block *tmp;

	new = *block;
	if (new->next)
		tmp = new->next;
	else
		tmp = NULL;
	free(new);
	*block = tmp;
}
