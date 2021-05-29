/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:50:02 by atahiri           #+#    #+#             */
/*   Updated: 2021/05/29 15:14:17 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		verif_backslash_squote(char *line, int i)
{
	int backslash;

	backslash = 0;
	while (i >= 0 && line[i] == '\\')
	{
		backslash++;
		i--;
	}
	backslash = backslash % 2;
	if (backslash == 0 && g_all.s_quote == 0)
	{
		g_all.s_quote = 1;
		return ;
	}
	if (backslash == 0 && g_all.s_quote == 1)
	{
		g_all.s_quote = 0;
		return ;
	}
}

void		verif_backslash_dquote(char *line, int i)
{
	int backslash;

	backslash = 0;
	while (i >= 0 && line[i] == '\\')
	{
		backslash++;
		i--;
	}
	backslash = backslash % 2;
	if (backslash == 0 && g_all.d_quote == 0)
	{
		g_all.d_quote = 1;
		return ;
	}
	if (backslash == 0 && g_all.d_quote == 1)
	{
		g_all.d_quote = 0;
		return ;
	}
}

int			starts_with(char *line)
{
	if (*line == '|')
		ft_putstr_fd("syntax error near unexpected token `|'\n", 1);
	else if (*line == ';')
		ft_putstr_fd("syntax error near unexpected token `;'\n", 1);
	else if (*line == '\\' && *(line+1) != '\\')
		ft_putstr_fd(">\n", 1);
	return (0);
}

int			verif_quotes(char *line)
{
	int i;

	i = -1;
	g_all.d_quote = 0;
	g_all.s_quote = 0;
	while (line[++i])
	{
		if ((line[i] == '\"' && g_all.d_quote == 0 && i == 0) || (line[i] ==
'\"' && g_all.d_quote == 0 && line[i - 1] != '\\' && g_all.s_quote == 0))
			g_all.d_quote = 1;
		else if (line[i] == '\"' && g_all.d_quote == 1 && line[i - 1] != '\\')
			g_all.d_quote = 0;
		if ((line[i] == '\'' && g_all.s_quote == 0 && i == 0) || (line[i] ==
'\'' && g_all.s_quote == 0 && line[i - 1] != '\\' && g_all.d_quote == 0))
			g_all.s_quote = 1;
		else if (line[i] == '\'' && g_all.s_quote == 1 && line[i - 1] != '\\')
			g_all.s_quote = 0;
		if (i != 0 && line[i] == '\'' && line[i - 1] == '\\')
			verif_backslash_squote(line, i - 1);
		if (i != 0 && line[i] == '\"' && line[i - 1] == '\\')
			verif_backslash_dquote(line, i - 1);
	}
	if (g_all.s_quote == 1 || g_all.d_quote == 1)
		return (-1);
	return (0);
}

void		start_parsing(char *line)
{
	// trim spaces from line
	char *trimed = trim_spaces(line);
	// verif_quotes(trimed);
	
	if (verif_quotes(trimed) == -1)
		ft_putstr_fd("Error : quote not closed\n", 2);
	starts_with(trimed);
	// else 
	// {
	// 	write(1, trimed, ft_strlen(trimed));
	// 	write(1, "\n", 1);
	// }
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
