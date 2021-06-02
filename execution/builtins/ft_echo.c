/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:13:35 by aes-salm          #+#    #+#             */
/*   Updated: 2021/05/31 10:55:44 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int remove_new_line_check(char *arg)
{
	int i;
	if (arg[0] == '-' && arg[1] == '-')
		return (0);
	if (ft_strcmp(arg, "-n"))
		return (1);
	if (arg[0] == '-')
	{
		i = 0;
		while (arg[++i])
			if (arg[i] != 'n')
				return (0);
		return (1);
	}
	return (0);
}

void ft_echo(char **args, int fd)
{
	int i;
	int j;
	int remove_nl;

	remove_nl = 0;
	i = -1;
	while (remove_new_line_check(args[++i]))
		remove_nl++;
	i = remove_nl - 1;
	while (args[++i] != 0)
	{
		j = -1;
		while (args[i][++j])
			write(fd, &args[i][j], 1);
		if (args[i + 1])
			write(fd, " ", 1);
	}
	if (!remove_nl)
		write(fd, "\n", 1);
	set_env("?", "0");
}