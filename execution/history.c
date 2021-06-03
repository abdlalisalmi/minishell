/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:06:27 by aes-salm          #+#    #+#             */
/*   Updated: 2021/06/02 21:00:09 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void free_double_pointer(char **ptr, int len)
{
	int i;

	i = -1;
	while (++i < len)
		free(ptr[i]);
	free(ptr);
}

void add_to_history(char *command)
{
	int i;
	int n_commands;
	char **history_copy;

	n_commands = g_all.history.n_commands;
	if (n_commands == 0)
	{
		g_all.history.commands = malloc(sizeof(char*) * 1);
		g_all.history.commands[0] = ft_strdup(command);
		g_all.history.n_commands++;
	}
	else
	{
		history_copy = malloc(sizeof(char **) * n_commands);
		i = -1;
		while (++i < n_commands)
			history_copy[i] = ft_strdup(g_all.history.commands[i]);
		free_double_pointer(g_all.history.commands, n_commands);
		g_all.history.commands = malloc(sizeof(char*) * (n_commands + 1));
		i = -1;
		while (++i < n_commands)
			g_all.history.commands[i] = ft_strdup(history_copy[i]);
		g_all.history.commands[i] = ft_strdup(command);
		g_all.history.n_commands++;
		free_double_pointer(history_copy, n_commands);
	}
}
