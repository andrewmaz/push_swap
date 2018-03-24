/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ad_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:02:59 by amazurok          #+#    #+#             */
/*   Updated: 2018/03/23 11:09:16 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int			ft_check(t_stek *stek, int med, char zn)
{
	if (zn == '+')
		while (stek)
		{
			if (stek->data < med)
				return (0);
			stek = stek->next;
		}
	else if (zn == '-')
		while (stek)
		{
			if (stek->data >= med)
				return (0);
			stek = stek->next;
		}
	return (1);
}

void		ft_set_val(int *a, int *b, int na, int nb)
{
	*a = na;
	*b = nb;
}

int			ft_sum_num(t_block *block)
{
	int sum;

	sum = 0;
	while (block)
	{
		sum += block->len;
		block = block->next;
	}
	return (sum);
}

t_block		*ft_ser_a(t_data *data, t_block *block)
{
	t_block	*new;
	int		*arr;
	size_t	len;

	new = ft_new_block();
	arr = ft_st2arr(data->a, &len, -1);
	new->ser = arr[len / 2];
	if (block)
		block->len = ft_steklen(data->b) - ft_sum_num(block);
	new->next = block;
	if (arr)
		free(arr);
	return (new);
}

int			*ft_newarr(int len)
{
	int *arr;
	int i;

	i = 0;
	arr = (int *)malloc(sizeof(int) * (len));
	while (i < len)
		arr[i++] = 0;
	return (arr);
}
