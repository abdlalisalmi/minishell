/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:06:27 by aes-salm          #+#    #+#             */
/*   Updated: 2021/06/02 14:42:39 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// int	read_history(char **operation, int fd)
// {
// 	char	*buffer;
// 	int		ret;

// 	buffer = (char *)malloc(2);
// 	*operation = (char *)malloc(1);
// 	*operation[0] = '\0';
// 	ret = 1;
// 	while (ret)
// 	{
// 		ret = read(fd, buffer, 1);
// 		if (ret)
// 		{
// 			if (buffer[0] == '\n' || ret == EOF)
// 				break ;
// 			*operation = ft_strjoin(*operation, buffer[0]);
// 		}
// 	}
// 	free(buffer);
// 	return (ret);
// }

void free_double_pointer(char **ptr)
{
	int i;

	i = -1;
	while (ptr[++i])
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
		
		g_all.history.commands = malloc(sizeof(char*) * (n_commands + 1));
		i = -1;
		while (history_copy[++i])
			g_all.history.commands[i] = ft_strdup(history_copy[i]);
		g_all.history.commands[i] = ft_strdup(command);
		g_all.history.n_commands++;

		// free_double_pointer(history_copy);
	}
	i = -1;
	while (++i <= n_commands)
		printf("%s\n", g_all.history.commands[i]);

}

// void update_history(void)
// {
	
// }

// void save_history(void)
// {
	
// }