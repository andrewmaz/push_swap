/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:05:13 by amazurok          #+#    #+#             */
/*   Updated: 2018/03/24 12:35:40 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		main(int argc, char *argv[])
{
	t_data	*data;

	if (argc > 1)
	{
		if (!(data = ft_read_a(argc, argv)))
			ft_error();
		ft_sort(data);
		data->cmd = ft_mod_cmd(data->cmd);
		data->cmd ? ft_putstr(data->cmd) : 0;
		ft_del_data(data);
	}
	return (0);
}
