/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:00:46 by amazurok          #+#    #+#             */
/*   Updated: 2018/03/24 11:02:07 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECKER_H
# define FT_CHECKER_H

# include <stdio.h>
# include <string.h>
# include "push_swap.h"
# include "../libftprintf/ft_printf/ft_printf.h"

typedef struct	s_kkey
{
	int		v;
	int		c;
	int		n;
	int		h;
	int		f;
	int		k;
	char	*filename;
}				t_kkey;

int				ft_valid_cmd(char *cmd, t_kkey *kkey, t_data *data);
void			ft_help(int us);
int				ft_read_key(char **v, t_kkey *key);
void			ft_pr_res(t_data *data, int col, t_kkey *key);
t_kkey			*ft_new_c_key();
int				ft_swp(t_data *data, char *str);
int				ft_rrt(t_data *data, char *str);
int				ft_psh(t_data *data, char *str);
void			ft_del_err(t_kkey *key);

#endif
