/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitting_by_semicolon.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:52:34 by atahiri           #+#    #+#             */
/*   Updated: 2021/06/09 21:19:34 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		number_of_semicolons(char *buff)
{
	int i = -1;
	int nb = 0;
	while (buff[++i])
	{
		if (buff[i] == ';')
			nb++;
	}
	return nb;
}

char        **splitting_by_semicolon(char *buff)
{
    char **splitted;
    int		nb;
	int		i = -1;
    
	nb = number_of_semicolons(buff);
	splitted = malloc(sizeof(char *) * (nb));
    splitted = ft_split(buff, ';');
	return splitted;
}