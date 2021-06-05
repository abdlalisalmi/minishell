/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:50:02 by atahiri           #+#    #+#             */
/*   Updated: 2021/06/05 12:13:27 by atahiri          ###   ########.fr       */
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

void		print_out(char **to_print)
{
	int j = 0;
	while (to_print[j])
	{
		write(1, to_print[j], ft_strlen(to_print[j]));
		write(1, "\n", 1);
		j++;
	}
}

char		*remove_whitespaces(char *buff)
{
	int i = -1;
	char	*trimmed;
	trimmed = trim_spaces(buff);
	return trimmed;
}

void		start_parsing(char *line)
{
	// trim spaces from line
	char *trimed;
	char **split_commands;
	int nb = number_of_semicolons(line);
	char **trim_commands = malloc(sizeof(char *) * nb);

	
	trimed = trim_spaces(line);
	// write(1, &nb, 1);
	if (verif_quotes(trimed) == -1)
		ft_putstr_fd("Error : quote not closed\n", 2);
	starts_with(trimed);
	split_commands = splitting_by_semicolon(trimed);
	int i = -1;
	while (split_commands[++i])
		trim_commands[i] = remove_whitespaces(split_commands[i]);
	// char *hh = trim_spaces(split_commands[0]);
	// print_out(trim_commands);
}
