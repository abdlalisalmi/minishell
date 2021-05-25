/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:02:06 by atahiri           #+#    #+#             */
/*   Updated: 2021/05/25 15:39:44 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define PROMPT "minishell-1.0$ "
# define COLOR "\033[0;33m"

/* ABDELAALI STRUCT */







/* AMINE STRUCT */
typedef struct s_all {
	char	*buff;
	char	**cmds;
	char	**args;

}				t_all;

t_all	g_all;





/* ABDELAALI PROTOTYPES */
void		ft_pwd(void);










/* AMINE PROTOTYPES */
int			ft_gnl(char **line);
int			ft_strlen(char *s);
char		*ft_strjoin(char *s, char c);
void		start_parsing(char *line);
char		**ft_split(const char *ss, char c);

#endif