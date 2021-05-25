/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:02:06 by atahiri           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/05/24 10:51:21 by aes-salm         ###   ########.fr       */
=======
/*   Updated: 2021/05/24 14:01:45 by atahiri          ###   ########.fr       */
>>>>>>> 153047ff83e3202844243e341f55a9fc924d0c3a
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










/* AMINE PROTOTYPES */
int			ft_gnl(char **line);
int			ft_strlen(char *s);
char		*ft_strjoin(char *s, char c);
<<<<<<< HEAD
=======
void		start_parsing(char *line);
char		**ft_split(const char *ss, char c);
>>>>>>> 153047ff83e3202844243e341f55a9fc924d0c3a

#endif