/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:50:02 by atahiri           #+#    #+#             */
/*   Updated: 2021/06/14 19:45:10 by atahiri          ###   ########.fr       */
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
	while (str[++i] != NULL)
	{
		count++;
	}
	return count;
}


// void		handle_redirections(char **command)
// {
// 	char **splitted_by_red;
// 	// red lbal m3a strstr lah isster

// 	// g_all.commands[0].r_right = 0;
// 	if (ft_strchr(*command, '>') || strstr(*command, ">>"))
// 	{
// 		splitted_by_red = ft_split(*command, '>');
// 		free(*command);
// 		*command = ft_strdup(splitted_by_red[0]);
// 		if (strstr(*command, ">>"))
// 			g_all.commands[0].r_right = 2;
// 		// function to return name of file
// 	}
// }

int		count_number_of_redirections(char *command)
{
	int i = -1;
	int nb = 0;

	while (command[++i])
	{
		if (command[i] == '>')
		{
			nb++;
		}
	}
	return nb;
}


void		start_parsing(char *line, char **envp)
{
	// trim spaces from line
	if (line[0] != '\0')
	{
		char *trimed;
		char **split_commands;
		int nb = 0;
		nb = number_of_semicolons(line) + 1;
		
		char **trim_commands = malloc(sizeof(char *) * (nb + 1));

		
		trimed = trim_spaces(line);
		
		if (verif_quotes(trimed) == -1)
			ft_putstr_fd("Error : quote not closed\n", 2);
		if (starts_with(trimed) || check_semicolon(trimed))
			return;



		split_commands = splitting_by_semicolon(trimed);

		
		int i = -1;
		while (++i < nb)
			trim_commands[i] = remove_whitespaces(split_commands[i]);
		trim_commands[i] = NULL;
		int nb_command = count_number_of_args(trim_commands);
		g_all.commands = malloc(sizeof(t_command) * nb_command);
		// function of redirections
		//TODO:Create a function to parse redirections
		print_out(trim_commands);
		// handle_redirections(&trim_commands[0]);


		
		i = -1;
		int j = 0;
		while (++i < nb_command)
		{
			char **split_spaces = ft_split(trim_commands[i], ' ');
			int count = count_number_of_args(split_spaces);
			g_all.commands[i].n_args = count;
			g_all.commands[i].args = (char **)malloc(sizeof(char *) * (count + 1));
			j = 0;
			while (j < count)
			{
				g_all.commands[i].args[j] = ft_strdup(split_spaces[j]);
				j++;
			}
			g_all.commands[i].args[j] = NULL;
		}
		// print_out(g_all.commands[1].args);
		


		
		start_execution(nb_command, envp);
		// write(1, g_all.commands[0].args[0], ft_strlen(g_all.commands[0].args[0]));
		// write(1, g_all.commands[0].args[1], ft_strlen(g_all.commands[0].args[1]));
		// write(1, g_all.commands[0].args[2], ft_strlen(g_all.commands[0].args[2]));

		

		// for(i = 0; i < nb_command; i++)
		// {
			
		// }
		

		// char *hh = trim_spaces(split_commands[0]);
		// print_out(g_all.commands[0].args);
		/* printing trimed whitespaces */
					// for (int i = 0; i < nb; i++)
					// {
					// 	write(1, trim_commands[i], ft_strlen(trim_commands[i]));
					// 	write(1, "\n", 1);
					// }
		/* printing trimed whitespaces */
		// for (i = 0; i < count; i++)
		// {
		// 	write(1, g_all.commands[2].args[i], ft_strlen(g_all.commands[2].args[i]));
		// 	write(1, "\n", 1);
		// }
		// for (i = 0; i < 3; i++)
		// {
		// 	write(1, g_all.commands[1].args[i], ft_strlen(g_all.commands[1].args[i]));
		// 	write(1, "\n", 1);
		// }
	}
}
