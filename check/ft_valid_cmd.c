/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:34:52 by amazurok          #+#    #+#             */
/*   Updated: 2018/03/23 12:38:02 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_checker.h"

int		ft_valid_cmd(char *cmd, t_kkey *key, t_data *data)
{
	if (ft_strequ(cmd, "sa") || ft_strequ(cmd, "sb") || ft_strequ(cmd, "ss"))
		return (1);
	else if (ft_strequ(cmd, "pa") || ft_strequ(cmd, "pb"))
		return (1);
	else if (ft_strequ(cmd, "ra") || ft_strequ(cmd, "rb") || \
			ft_strequ(cmd, "rr"))
		return (1);
	else if (ft_strequ(cmd, "rra") || ft_strequ(cmd, "rrb") || \
			ft_strequ(cmd, "rrr"))
		return (1);
	else if (!cmd || cmd[0] == '\0')
		return (1);
	free(data);
	ft_del_err(key);
	return (0);
}
