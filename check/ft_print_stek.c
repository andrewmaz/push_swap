/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stek.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:21:59 by amazurok          #+#    #+#             */
/*   Updated: 2018/03/23 12:38:02 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_checker.h"

static void	ft_print_a(t_stek *a, int c, int col)
{
	int		l;
	int		sl;

	l = ft_steklen(a);
	sl = l;
	while (a)
	{
		if (c)
		{
			if ((col == 1 + 'a' * 10 || col == 1 + 's' * 10) && l > sl - 2)
				ft_printf("{blue}");
			else if (col == 2 + 'a' * 10 || col == 2 + 'r' * 10)
				ft_printf("{yellow}");
			else if (col == 3 + 'a' * 10 || col == 3 + 'r' * 10)
				ft_printf("{cyan}");
			else if (col == 4 + 'a' * 10 && l == sl)
				ft_printf("{green}");
		}
		ft_printf(" %d{eoc}", a->data);
		a = a->next;
		l--;
	}
	ft_printf("{eoc}\n");
}

static void	ft_print_b(t_stek *b, int c, int col)
{
	int		l;
	int		sl;

	l = ft_steklen(b);
	sl = l;
	while (b)
	{
		if (c)
		{
			if ((col == 1 + 'b' * 10 || col == 1 + 's' * 10) && l > sl - 2)
				ft_printf("{blue}");
			else if (col == 2 + 'b' * 10 || col == 2 + 'r' * 10)
				ft_printf("{yellow}");
			else if (col == 3 + 'b' * 10 || col == 3 + 'r' * 10)
				ft_printf("{cyan}");
			else if (col == 4 + 'b' * 10 && l == sl)
				ft_printf("{green}");
		}
		ft_printf(" %d{eoc}", b->data);
		b = b->next;
		l--;
	}
	ft_printf("{eoc}\n\n");
}

static void	ft_hel_pr(t_kkey *key, char *cm, int col, int w)
{
	if (key && key->k)
	{
		cm = col == 1 + 'a' * 10 || col == 1 + 's' * 10 ? "->sa" : cm;
		cm = col == 2 + 'a' * 10 || col == 2 + 'r' * 10 ? "->rra" : cm;
		cm = col == 3 + 'a' * 10 || col == 3 + 'r' * 10 ? "->ra" : cm;
		cm = col == 4 + 'a' * 10 ? "->pa" : cm;
	}
	ft_printf("[ a %*-s] |", w ? 5 : 0, cm ? cm : "");
}

void		ft_pr_res(t_data *data, int col, t_kkey *key)
{
	char	*cm;
	int		w;

	cm = NULL;
	w = key ? key->k : 0;
	col == -1 ? ft_printf("START\n") : 0;
	col == -2 ? ft_printf("FINAL\n") : 0;
	ft_hel_pr(key, cm, col, w);
	ft_print_a(data->a, (key ? key->c : 0), col);
	cm = NULL;
	if (key && key->k)
	{
		cm = col == 1 + 'b' * 10 || col == 1 + 's' * 10 ? "->sb" : cm;
		cm = col == 2 + 'b' * 10 || col == 2 + 'r' * 10 ? "->rrb" : cm;
		cm = col == 3 + 'b' * 10 || col == 3 + 'r' * 10 ? "->rb" : cm;
		cm = col == 4 + 'b' * 10 ? "->pb" : cm;
	}
	ft_printf("[ b %*-s] |", w ? 5 : 0, cm ? cm : "");
	ft_print_b(data->b, (key ? key->c : 0), col);
}
