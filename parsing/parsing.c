/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:50:02 by atahiri           #+#    #+#             */
/*   Updated: 2021/05/24 14:02:02 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		start_parsing(char *line)
{
	g_all.cmds = ft_split(line, ' ');
	write(1, g_all.cmds[0], ft_strlen(g_all.cmds[0]));
}
