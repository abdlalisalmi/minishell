/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:02:06 by atahiri           #+#    #+#             */
/*   Updated: 2021/05/24 10:07:44 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define PROMPT "minishell-1.0$ "
#define COLOR "\033[0;33m"

/* ABDELAALI STRUCT */







/* AMINE STRUCT */
typedef	struct	s_all {
	char	*buff;
	
}				t_all;

t_all	g_all;





/* ABDELAALI PROTOTYPES */
























/* AMINE PROTOTYPES */
int			ft_gnl(char **line);
int			ft_strlen(char *s);

#endif