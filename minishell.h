#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <fcntl.h>
#include <errno.h>
#include <limits.h>

# define PROMPT			"minishell-1.0$ "
# define COLOR			"\033[0;33m"
# define PIPE			99
# define SEMICOLON		88
# define ARG			77
# define CMD			66
# define RIGHT			55
# define DOUBLERIGHT	44
# define LEFT			33

# define HISTSIZE		1000

/* ABDELAALI STRUCT */
typedef struct 	s_env 
{
	char 		*name;
	char 		*value;
}				t_env;

typedef struct	s_history
{
	char		**commands;
	int			n_commands;
}				t_history;




/* AMINE STRUCT */

typedef struct 			s_command {
	// char				*cmd;
	char 				**args;
	int					n_args;
	char				*outfile;
	char				*inputfile;
}						t_command;

typedef struct s_all {
	int			ret;
	char		*buff;
	int			s_quote;
	int			d_quote;
	
	int		n_env;
	t_env	*env;
	t_history	history;
	t_command	*commands;
}				t_all;

t_all	g_all;





/* ABDELAALI PROTOTYPES */

/*
** Builtins commands
*/
char	*ft_pwd(void);
int		ft_cd(char **args, int n_args);
int		ft_export(char **args, int n_args);
void	ft_unset(char **args);
void	ft_env(void);
void	ft_exit(char **args, int n_args);
void 	ft_echo(char **args);

/*
** Manage EnvVar functions
*/
void	collect_env(char **envp);
char	*get_env(char *name);
int		set_env(char *name, char *value);

/*
** Manage History functions
*/
void	add_to_history(char *command);

void	start_execution();
void	exec_single_cmd(char **args, int n_args, char **envp);
char	*get_cmd_path(char *cmd);

/*
** Help functions
*/
void	ft_putstr_fd(char *s, int fd);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_strcmp(char *str1, char *str2);
char	*ft_strdup(const char *str);
char	*ft_strchr(const char *str, int c);
int		ft_isdigit(int arg);
char	*ft_strappend(char *s1, char *s2);
void	free_d_pointer(char **ptr);
int		ft_dplen(char **ptr);










/* AMINE PROTOTYPES */
int			ft_gnl(char **line);
int			ft_strlen(char *s);
char		*ft_strjoin(char *s, char c);
void		start_parsing(char *line);
char		**ft_split(const char *ss, char c);
char		*trim_spaces(char *str);
void		init_signals(void);
char		**splitting_by_semicolon(char *buff);
int			number_of_semicolons(char *buff);

#endif