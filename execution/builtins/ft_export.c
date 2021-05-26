/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:39:09 by aes-salm          #+#    #+#             */
/*   Updated: 2021/05/26 13:08:08 by aes-salm         ###   ########.fr       */
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
	return (value);
}

int ft_export(char **args)
{
	int i;

	i = -1;
	while (args[++i] != 0)
	{
		if (ft_isdigit(args[i][0]))
		{
			ft_putstr_fd("bash: export: `", 1);
			ft_putstr_fd(args[i], 1);
			ft_putstr_fd("': not a valid identifier\n", 1);
		}
		else
			if (ft_strchr(args[i], '='))
				set_env(get_env_name(args[i]), get_env_value(args[i]));
	}
	return (1);
}
