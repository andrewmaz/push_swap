/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:33:42 by amazurok          #+#    #+#             */
/*   Updated: 2018/03/24 12:41:44 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_checker.h"

int		ft_set_key(t_kkey *key, int i, char **v)
{
	if (v[i][1] == 'c')
		key->c = 1;
	else if (v[i][1] == 'v')
		key->v = 1;
	else if (v[i][1] == 'n')
		key->n = 1;
	else if (v[i][1] == 'h')
		key->h = 1;
	else if (v[i][1] == 'k')
		key->k = 1;
	else if (v[i][1] == 'f')
	{
		key->f = 1;
		key->filename = v[++i];
	}
	else
	{
		free(key);
		ft_help(1);
		exit(6);
	}
	return (i);
}

int		ft_read_key(char **v, t_kkey *key)
{
	int i;

	i = 1;
	while (v[i])
	{
		if (v[i][0] == '-' && ft_isalpha(v[i][1]))
			i = ft_set_key(key, i, v);
		else
			break ;
		i++;
	}
	return (i - 1);
}
