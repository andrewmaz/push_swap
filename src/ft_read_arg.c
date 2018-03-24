/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:15:36 by amazurok          #+#    #+#             */
/*   Updated: 2018/03/24 12:54:40 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	ft_non_duplic(t_stek *stek)
{
	int		i;
	t_stek	*new;

	while (stek && stek->next)
	{
		i = stek->data;
		new = stek->next;
		while (new)
		{
			if (i == new->data)
				return (0);
			new = new->next;
		}
		stek = stek->next;
	}
	return (1);
}

static int	ft_valid(int argc, char *v[])
{
	int i;
	int j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (v[i][j])
		{
			if (ft_isdigit(v[i][j]) || ((v[i][j] == '-' || v[i][j] == '+') && \
					ft_isdigit(v[i][j + 1])))
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int			ft_d_er(t_data *data)
{
	ft_del_data(data);
	ft_error();
	return (0);
}

static void	ft_wh(char **new, int argc, t_data *data, int i)
{
	int		j;
	ssize_t	k;

	j = 0;
	while (new && new[j])
	{
		k = ft_atoi(new[j++]);
		data->a->data = (k > 2147483647 || k < -2147483648) ? ft_d_er(data) :\
			(int)k;
		if (new[j] || i + 1 < argc)
		{
			data->a->next = ft_new_elem();
			data->a->next->prev = data->a;
		}
		data->a = data->a->next;
	}
}

t_data		*ft_read_a(int argc, char *argv[])
{
	t_stek	*a;
	t_data	*data;
	int		i;
	char	**new;

	i = 1;
	data = NULL;
	data = ft_new_data(data);
	data->a = ft_new_elem();
	a = data->a;
	while (i < argc)
	{
		new = ft_strsplit(argv[i], ' ');
		if (!ft_valid(ft_dstrlen(new), new))
			return (NULL);
		ft_wh(new, argc, data, i);
		new ? ft_deldstr(new) : 0;
		i++;
	}
	data->a = a;
	if (!ft_non_duplic(data->a))
		ft_d_er(data);
	return (data);
}
