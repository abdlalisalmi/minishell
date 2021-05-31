/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:03:15 by aes-salm          #+#    #+#             */
/*   Updated: 2021/05/31 10:58:07 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	update_env(char *name)
{
	int i;
	int index;
	

	i = -1;
	index = 0;
	while (++i <= g_all.n_env)
	{
		if (!ft_strcmp(g_all.env[i].name, name))
		{
			g_all.env[index].name = g_all.env[i].name;
			g_all.env[index].value = g_all.env[i].value;
			index++;
		}
		else
		{
			g_all.env[index].name = "";
			g_all.env[index].value = "";
		}
	}
}

void	ft_unset(char **args)
{
	int i;

	i = -1;
	while (args[++i] != 0)
	{
		if (ft_isdigit(args[i][0]) || ft_strchr(args[i], '='))
		{
			ft_putstr_fd("bash: unset:: `", 1);
			ft_putstr_fd(args[i], 1);
			ft_putstr_fd("': not a valid identifier\n", 1);
			set_env("?", "1");
		}
		else
		{
			update_env(args[i]);
			set_env("?", "0");
		}
	}
}