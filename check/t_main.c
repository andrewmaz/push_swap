/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:41:26 by amazurok          #+#    #+#             */
/*   Updated: 2018/03/24 13:05:49 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_checker.h"

void		ft_print_sort(t_kkey *key, t_data *data, int len)
{
	if (key->n)
		ft_printf("%d\n", len, key->c);
	if (ft_is_sort(data->a, '+') && !data->b)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

int			ft_fd(t_kkey *key, t_data *data)
{
	int fd;

	fd = key->f ? open(key->filename, O_RDWR) : 0;
	if (fd < 0)
	{
		ft_printf("File doesn't open, fd = 0!\n");
		fd = 0;
	}
	if (key->h)
	{
		ft_help(0);
		free(key);
		exit(9);
	}
	key->v ? ft_pr_res(data, -1, NULL) : 0;
	return (fd);
}

void		ft_del_err(t_kkey *key)
{
	free(key);
	ft_error();
}

int			ft_gnl(int fd, t_data *data, t_kkey *key)
{
	char	*str;
	int		len;
	int		nv;

	len = 0;
	while (get_next_line(fd, &str))
	{
		len++;
		ft_valid_cmd(str, key, data);
		nv = (str[0] == 's') ? ft_swp(data, str) : 0;
		nv = (str[0] == 'r') ? ft_rrt(data, str) : nv;
		nv = (str[0] == 'p') ? ft_psh(data, str) : nv;
		key->v ? ft_pr_res(data, nv, key) : 0;
		ft_strdel(&str);
	}
	return (len);
}

int			main(int argc, char *argv[])
{
	t_data	*data;
	t_kkey	*key;
	int		nv;
	int		fd;

	key = ft_new_c_key();
	nv = ft_read_key(argv, key);
	if (argc - nv <= 1 && !key->h)
		return (1);
	!(data = ft_read_a(argc - nv, argv + nv)) ? ft_del_err(key) : 0;
	argc = 0;
	fd = ft_fd(key, data);
	argc = ft_gnl(fd, data, key);
	key->v ? ft_pr_res(data, -2, NULL) : 0;
	ft_print_sort(key, data, argc);
	ft_del_data(data);
	free(key);
}
