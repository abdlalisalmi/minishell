/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:56:23 by aes-salm          #+#    #+#             */
/*   Updated: 2021/05/25 21:20:10 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void collect_env(char **env)
{
	int i;

	g_all.env = malloc(sizeof(t_env) * 1000);
	i = 0;
	g_all.n_env = 0;
	while (*env++ != 0)
	{
		g_all.env[i].name = ft_split(*env, '=')[0];
		g_all.env[i].value = ft_split(*env, '=')[1];
		g_all.n_env++;
		i++;
	}
}

char *get_env(char *name)
{
	int i;

	i = -1;
	while (++i <= g_all.n_env)
		if (ft_strcmp(name, g_all.env[i].name))
			return (g_all.env[i].value);
	return (NULL);
}

int	set_env(char *name, char *value)
{
	int i;

	i = -1;
	while (++i <= g_all.n_env)
	{
		if (ft_strcmp(name, g_all.env[i].name))
		{
			g_all.env[i].value = ft_strdup(value);
			return (1);
		}
	}
	g_all.n_env++;
	g_all.env[g_all.n_env].name = ft_strdup(name);
	g_all.env[g_all.n_env].value = ft_strdup(value);
	return (1);
}
