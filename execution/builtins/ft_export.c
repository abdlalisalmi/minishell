/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:39:09 by aes-salm          #+#    #+#             */
/*   Updated: 2021/06/08 09:55:23 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char *get_env_name(char *str)
{
	int i;
	char *name;

	i = -1;
	while (str[++i] != '=')
	name = malloc(sizeof(char) * i);
	i = -1;
	while (str[++i] != '=')
		name[i] = str[i];
	return (name);
}

char *get_env_value(char *str)
{
	int i;
	int j;
	char *value;

	i = -1;
	while (str[++i] != '=')
	value = malloc(sizeof(char) * ft_strlen(str) - i);
	j = 0;
	while (str[++i])
		value[j++] = str[i];
	value[j] = '\0';
	return (value);
}

void	print_env(int fd)
{
	int i = -1;

	while (++i < g_all.n_env)
	{
		if (g_all.env[i].name)
		{
			ft_putstr_fd("declare -x ", fd);
			ft_putstr_fd(g_all.env[i].name, fd);
			ft_putstr_fd("=", fd);
			ft_putstr_fd("\"", fd);
			ft_putstr_fd(g_all.env[i].value, fd);
			ft_putstr_fd("\"", fd);
			ft_putstr_fd("\n", fd);
		}
	}
	set_env("?", "0");
}

int ft_export(char **args, int fd)
{
	int i;

	if (args == NULL)
		print_env(fd);
	else
	{
		i = -1;
		while (args[++i] != 0)
		{
			if (ft_isdigit(args[i][0]))
			{
				ft_putstr_fd("minishell-1.0: export: `", 1);
				ft_putstr_fd(args[i], 1);
				ft_putstr_fd("': not a valid identifier\n", 1);
				set_env("?", "1");
			}
			else
				if (ft_strchr(args[i], '='))
				{
					set_env(get_env_name(args[i]), get_env_value(args[i]));
					set_env("?", "0");
				}
		}
	}
	return (1);
}
