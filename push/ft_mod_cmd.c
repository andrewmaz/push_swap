/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:03:29 by amazurok          #+#    #+#             */
/*   Updated: 2018/03/23 11:03:34 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static char	*ft_new_cmd_line(char *cmd)
{
	size_t	len;
	int		i;
	char	*res;

	len = 0;
	i = 0;
	while (cmd && cmd[i])
	{
		if (cmd[i] != '*')
			len++;
		i++;
	}
	res = ft_strnew(len);
	len = 0;
	i = 0;
	while (cmd && cmd[i])
	{
		if (cmd[i] != '*')
			res[len++] = cmd[i++];
		else
			i++;
	}
	ft_strdel(&cmd);
	return (res);
}

static int	ft_str_replace(char **str, char *rep, const char *fin)
{
	char	*new;
	int		i;

	i = 0;
	if ((new = ft_strstr(*str, rep)))
	{
		while (fin[i])
		{
			new[i] = fin[i];
			i++;
		}
	}
	return (i);
}

char		*ft_mod_cmd(char *cmd)
{
	int		k;

	k = 1;
	while (cmd && k)
	{
		k = 0;
		k += ft_str_replace(&cmd, "\npa\npb\n", "\n******");
		k += ft_str_replace(&cmd, "\npb\npa\n", "\n******");
		k += ft_str_replace(&cmd, "\nra\nrb\n", "\nrr\n***");
		k += ft_str_replace(&cmd, "\nrb\nra\n", "\nrr\n***");
		k += ft_str_replace(&cmd, "\nsa\nsb\n", "\nss\n***");
		k += ft_str_replace(&cmd, "\nsb\nsa\n", "\nss\n***");
		k += ft_str_replace(&cmd, "\nrra\nrrb\n", "\nrrr\n****");
		k += ft_str_replace(&cmd, "\nrrb\nrra\n", "\nrrr\n****");
		k += ft_str_replace(&cmd, "\nra\nrra\n", "\n*******");
		k += ft_str_replace(&cmd, "\nrra\nra\n", "\n*******");
		k += ft_str_replace(&cmd, "\nrb\nrrb\n", "\n*******");
		k += ft_str_replace(&cmd, "\nrrb\nrb\n", "\n*******");
		k += ft_str_replace(&cmd, "\nrb\npa\nrrb\n", "\nsb\npa\n****");
		k += ft_str_replace(&cmd, "\nra\npb\nrra\n", "\nsa\npb\n****");
		cmd = ft_new_cmd_line(cmd);
	}
	return (cmd);
}
