/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:13:35 by aes-salm          #+#    #+#             */
/*   Updated: 2021/05/26 21:59:25 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int remove_new_line_check(char *arg)
{
	if (arg[0] == '-' && arg[1] == '-')
		return (0);
	if (ft_strcmp(arg, "-n"))
		return (1);
	if (arg[0] == '-' && arg[1] == 'n' && arg[2] == 'n')
		return (1);
	return (0);
}

void ft_echo(char **args, int fd)
{
	int i;
	int j;
	int remove_nl;

	remove_nl = 0;
	if (remove_new_line_check(args[0]))
		remove_nl = 1;
	i = remove_nl;
	while (args[i] != 0)
	{
		if (remove_new_line_check(args[i]))
			continue;
		j = -1;
		while (args[i][++j])
			write(fd, &args[i][j], 1);
		if (args[i + 1])
			write(fd, " ", 1);
		i++;
	}
	if (!remove_nl)
		write(fd, "\n", 1);
}