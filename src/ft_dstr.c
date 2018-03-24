/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 14:08:39 by amazurok          #+#    #+#             */
/*   Updated: 2018/03/24 11:02:07 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void		ft_deldstr(char **str)
{
	int i;

	i = 0;
	while (str && str[i])
		ft_strdel(&str[i++]);
	free(str);
}

int			ft_dstrlen(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
