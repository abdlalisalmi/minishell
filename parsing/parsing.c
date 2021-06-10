/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:50:02 by atahiri           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/06/10 16:27:42 by atahiri          ###   ########.fr       */
=======
<<<<<<< HEAD
/*   Updated: 2021/06/10 09:33:00 by aes-salm         ###   ########.fr       */
=======
/*   Updated: 2021/06/10 15:38:17 by atahiri          ###   ########.fr       */
>>>>>>> 3bdb3257060a95b35e7d21c468cf0260c4753a86
>>>>>>> 3c7bd1e515b74d51e109c825c037d3890eaaadd7
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

int			check_semicolon(char *line)
{
	int i = -1;
	int found = 0;

	if (line[0] == ';')
		ft_putstr_fd("syntax error near unexpected token `;'\n", 1);
	while (line[++i])
	{
		if (line[i] == ';' && line[i+1] == ';')
			ft_putstr_fd("syntax error near unexpected token `;;'\n", 1);
	}
	return 0;
}

int			starts_with(char *line)
{
	if (*line == '|')
		ft_putstr_fd("syntax error near unexpected token `|'\n", 1);
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
	while (to_print[j] != '\0')
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

int			count_number_of_args(char **str)
{
	int i = -1;
	int count = 0;
	while (str[++i])
	{
		count++;
	}
	return count;
}

void		start_parsing(char *line)
{
	// trim spaces from line
	if (line[0] != '\0')
	{
		char *trimed;
		char **split_commands;
		int nb = 0;
		nb = number_of_semicolons(line) + 1;
		write(1, &nb, 1);
		char **trim_commands = malloc(sizeof(char *) * (nb + 1));

		
		trimed = trim_spaces(line);
		// write(1, &nb, 1);
		if (verif_quotes(trimed) == -1)
			ft_putstr_fd("Error : quote not closed\n", 2);
		if (starts_with(trimed) || check_semicolon(trimed))
			return;



		split_commands = splitting_by_semicolon(trimed);

		
		int i = 0;
		while (i < nb)
		{
			trim_commands[i] = remove_whitespaces(split_commands[i]);
			i++;
		}
		// write(1, &nb, 1);
		// g_all.commands->args[0] = "echo";
		char **split_spaces = ft_split(trim_commands[0], ' ');

		int count = count_number_of_args(split_spaces);
		g_all.commands = malloc(sizeof(t_command) * nb);
		for (i = 0; i < nb; i++)
		{
			g_all.commands[i].args = (char **)malloc(sizeof(char *) * count);
		}


		for(i = 0; i < count; i++)
		{
			g_all.commands[0].args[i] = split_spaces[i];
		}
		// char *hh = trim_spaces(split_commands[0]);
		// print_out(trim_commands);
		/* printing trimed whitespaces */
					// for (i = 0; i <= nb; i++)
					// {
					// 	write(1, trim_commands[i], ft_strlen(trim_commands[i]));
					// 	write(1, "\n", 1);
					// }
		/* printing trimed whitespaces */
		for (i = 0; i < count; i++)
		{
			write(1, g_all.commands[0].args[i], ft_strlen(g_all.commands[0].args[i]));
			write(1, "\n", 1);
		}
		// for (i = 0; i < 3; i++)
		// {
		// 	write(1, g_all.commands[1].args[i], ft_strlen(g_all.commands[1].args[i]));
		// 	write(1, "\n", 1);
		// }
	}
}
