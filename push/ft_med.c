/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_med.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 12:32:35 by amazurok          #+#    #+#             */
/*   Updated: 2018/03/23 12:38:02 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	ft_swap_int(int *a, int *b)
{
	int c;

	if (a && b)
	{
		c = *a;
		*a = *b;
		*b = c;
	}
	else
		return ;
}

static void	ft_bubl_sort(int *arr, int n)
{
	int i;
	int j;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
				ft_swap_int(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}

int			*ft_st2arr(t_stek *stek, size_t *l, int n)
{
	size_t	len;
	int		*arr;
	int		i;

	i = 0;
	if (!stek)
		return (NULL);
	len = n > 0 ? n : ft_steklen(stek);
	arr = ft_newarr(len);
	*l = len;
	while (stek && i < (int)len)
	{
		arr[i++] = stek->data;
		stek = stek->next;
	}
	if (len > 1)
		ft_bubl_sort(arr, (int)len);
	return (arr);
}

static int	ft_m_ser(t_stek *stek, int n)
{
	int		len;
	int		*arr;
	int		i;

	len = ft_steklen(stek);
	n = -n;
	i = 0;
	arr = ft_newarr(n);
	while (stek)
	{
		if (len <= n)
			arr[i++] = stek->data;
		stek = stek->next;
		len--;
	}
	ft_bubl_sort(arr, n);
	i = arr[n / 2];
	free(arr);
	return (i);
}

int			ft_n_ser(t_stek *stek, int n)
{
	int		*arr;
	size_t	len;
	int		ret;

	if (!stek)
		return (0);
	arr = ft_st2arr(stek, &len, n);
	if (n > 0)
		ret = arr[n / 2];
	else
		ret = ft_m_ser(stek, n);
	free(arr);
	return (ret);
}
