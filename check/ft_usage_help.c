/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <amazurok@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:34:32 by amazurok          #+#    #+#             */
/*   Updated: 2018/03/24 12:26:40 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_checker.h"

void	ft_help(int us)
{
	us ? ft_printf("________________Usage________________\n") : \
		ft_printf("________________HELP_________________\n");
	ft_printf("| %-14s %-19s|\n", "-h", "<help>");
	ft_printf("| %-14s %-19s|\n", "-v", "<visualization>");
	ft_printf("| %-14s %-19s|\n", "-n", "<number of command>");
	ft_printf("| %-14s %-19s|\n", "-k", "<print command>");
	ft_printf("| %-14s %-19s|\n", "-f [file name]", "<input from file>");
	ft_printf("| %-14s %-19s|\n", "-c", "<colour of command>");
	ft_printf("| %-14s {green}%-19s{eoc}|\n", "", "<push>");
	ft_printf("| %-14s {blue}%-19s{eoc}|\n", "", "<swap>");
	ft_printf("| %-14s {cyan}%-19s{eoc}|\n", "", "<rotate>");
	ft_printf("| %-14s {yellow}%-19s{eoc}|\n", "", "<reverse rotate>");
	ft_printf("|___________________________________|\n");
}
