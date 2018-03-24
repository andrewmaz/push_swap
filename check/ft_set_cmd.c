/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:37:00 by amazurok          #+#    #+#             */
/*   Updated: 2018/03/23 11:37:00 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_checker.h"

int		ft_swp(t_data *data, char *str)
{
	ft_swap(data, str[1], 0);
	return (1 + str[1] * 10);
}

int		ft_rrt(t_data *data, char *str)
{
	if (str[1] == 'r' && str[2] != '\0')
	{
		ft_rev_rotate(data, str[2], 0);
		return (2 + str[2] * 10);
	}
	else
	{
		ft_rotate(data, str[1], 0);
		return (3 + str[1] * 10);
	}
}

int		ft_psh(t_data *data, char *str)
{
	ft_push(data, str[1]);
	return (4 + str[1] * 10);
}
