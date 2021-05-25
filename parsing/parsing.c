/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:50:02 by atahiri           #+#    #+#             */
/*   Updated: 2021/05/25 11:00:01 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		start_parsing(char *line)
{
	g_all.cmds = ft_split(line, ' ');
	int i = 0;
	while (g_all.cmds[i])
	{
		// write(1, g_all.cmds[i], ft_strlen(g_all.cmds[i]));
		// write(1, "\n", 1);
		if (g_all.cmds[i][0] == '>' || g_all.cmds[i][0] == '<')
			write(1, "TOKEN: REDIRECTION\n", 19);
		else if (g_all.cmds[i][0] == '$')
			write(1, "TOKEN: ENVIRONMENT VARIABLE\n", 28);
		else
		{
			write(1, g_all.cmds[i], ft_strlen(g_all.cmds[i]));
			write(1, "\n", 1);
		}
		i++;
	}
}