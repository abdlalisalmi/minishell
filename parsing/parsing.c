/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:50:02 by atahiri           #+#    #+#             */
/*   Updated: 2021/05/27 00:27:25 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		start_parsing(char *line)
{
	// trim spaces from line

	// trim_spaces(line);
	
	// g_all.cmds = ft_split(line, ' ');
	// int i = 0;
	// while (g_all.cmds[i])
	// {
	// 	// write(1, g_all.cmds[i], ft_strlen(g_all.cmds[i]));
	// 	// write(1, "\n", 1);
	// 	if (g_all.cmds[i][0] == '>' || g_all.cmds[i][0] == '<')
	// 		write(1, "TOKEN: REDIRECTION\n", 19);
	// 	else if (g_all.cmds[i][0] == '$')
	// 		write(1, "TOKEN: ENV\n", 11);
	// 	else if (g_all.cmds[i][0] == '|')
	// 		write(1, "TOKEN: PIPE\n", 12);
	// 	else if (g_all.cmds[i][0] == ';')
	// 		write(1, "TOKEN: SEMICOLON\n", 17);
	// 	else
	// 	{
	// 		write(1, "COMMAND: ", 9);
	// 		write(1, g_all.cmds[i], ft_strlen(g_all.cmds[i]));
	// 		write(1, "\n", 1);
	// 	}
	// 	i++;
	// }
}
