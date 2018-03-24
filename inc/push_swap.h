/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 16:58:03 by amazurok          #+#    #+#             */
/*   Updated: 2018/03/24 11:02:06 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libftprintf/libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_stek
{
	int				data;
	struct s_stek	*prev;
	struct s_stek	*next;
}				t_stek;

typedef struct	s_data
{
	t_stek	*a;
	t_stek	*b;
	char	*cmd;
}				t_data;

typedef struct	s_block
{
	int				len;
	int				ser;
	int				rot;
	struct s_block	*next;
}				t_block;

void			ft_push(t_data *data, char stek);
void			ft_swap(t_data *data, char st, int cmd);
void			ft_rotate(t_data *data, char st, int cmd);
void			ft_rev_rotate(t_data *data, char st, int cmd);

t_data			*ft_new_data(t_data *data);
t_stek			*ft_new_elem(void);
t_block			*ft_new_block(void);
int				*ft_newarr(int len);
void			ft_del_last(t_stek **stek);
void			ft_del_block(t_block **block);
t_data			*ft_read_a(int argc, char *argv[]);
void			ft_sort(t_data *data);
void			ft_sort_a(t_data *data, t_block **block, int push);
t_block			*ft_sort_b(t_data *data, t_block *block);
void			ft_sort_three(t_data *data);
void			ft_sort_up_three(t_data *data);
void			ft_comp_sort(t_data *data, int nb);
int				ft_is_sort(t_stek *stek, char c);
int				ft_is_n_sort(t_stek *stek, char c, int n);
int				ft_check(t_stek *stek, int med, char zn);
int				ft_in_list(t_stek *stek, int num);
t_block			*ft_ser_a(t_data *data, t_block *block);
int				ft_n_ser(t_stek *stek, int n);
size_t			ft_steklen(t_stek *stek);
void			ft_set_val(int *a, int *b, int na, int nb);
char			*ft_mod_cmd(char *cmd);
void			ft_error(void);
void			ft_del_data(t_data *data);
int				*ft_st2arr(t_stek *stek, size_t *l, int n);
void			ft_deldstr(char **str);
int				ft_dstrlen(char **str);

#endif
