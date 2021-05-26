/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:02:06 by atahiri           #+#    #+#             */
/*   Updated: 2021/05/27 00:31:20 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>

# define PROMPT "minishell-1.0$ "
# define COLOR "\033[0;33m"

/* ABDELAALI STRUCT */
typedef struct 	s_env 
{
	char 		*name;
	char 		*value;
}				t_env;






/* AMINE STRUCT */
typedef struct s_all {
	char	*buff;
	char	**cmds;
	char	**args;
	
	int		n_env;
	t_env	*env;
}				t_all;

t_all	g_all;





/* ABDELAALI PROTOTYPES */
char	*ft_pwd(void);
int		ft_cd(char *path, int fd);
int		ft_export(char **args);
void	ft_unset(char **args);
void	ft_env(void);
void	ft_exit(void);
void 	ft_echo(char **args, int fd);

void	collect_env(char **envp);
char	*get_env(char *name);
int		set_env(char *name, char *value);

void	ft_putstr_fd(char *s, int fd);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_strcmp(char *str1, char *str2);
char	*ft_strdup(const char *str);
char	*ft_strchr(const char *str, int c);
int		ft_isdigit(int arg);










/* AMINE PROTOTYPES */
int			ft_gnl(char **line);
int			ft_strlen(char *s);
char		*ft_strjoin(char *s, char c);
void		start_parsing(char *line);
char		**ft_split(const char *ss, char c);
char		*trim_spaces(char *str);
void		init_signals();

#endif