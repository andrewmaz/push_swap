/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_c_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:18:40 by amazurok          #+#    #+#             */
/*   Updated: 2018/03/23 11:20:28 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_checker.h"

t_kkey	*ft_new_c_key(void)
{
	t_kkey *key;

	key = (t_kkey*)malloc(sizeof(t_kkey));
	key->c = 0;
	key->n = 0;
	key->v = 0;
	key->h = 0;
	key->f = 0;
	key->k = 0;
	key->filename = NULL;
	return (key);
}
