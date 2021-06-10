/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_single_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:10:02 by aes-salm          #+#    #+#             */
/*   Updated: 2021/06/09 21:06:46 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

int is_builtins(char *cmd)
{
	if (ft_strcmp(cmd, "cd") || ft_strcmp(cmd, "echo") ||
		ft_strcmp(cmd, "env") || ft_strcmp(cmd, "exit") ||
		ft_strcmp(cmd, "export") || ft_strcmp(cmd, "pwd") ||
		ft_strcmp(cmd, "unset"))
		return (1);
	return (0);
}

void exec_builtins(char **args, int n_args)
{
	if (ft_strcmp(args[0], "cd"))
		ft_cd(args, n_args);
	else if (ft_strcmp(args[0], "echo"))
		ft_echo(args);
	else if (ft_strcmp(args[0], "env"))
		ft_env();
	else if (ft_strcmp(args[0], "exit"))
		ft_exit(args, n_args);
	else if (ft_strcmp(args[0], "export"))
		ft_export(args, n_args);
	else if (ft_strcmp(args[0], "pwd"))
		printf("pwd\n");
	else if (ft_strcmp(args[0], "unset"))
		printf("unset\n");
}

void	exec_single_cmd(char **args, int n_args, char **envp)
{
	char **paths;
	char *cmd_path;

	if (is_builtins(args[0]))
		exec_builtins(args, n_args);
	else
	{
		cmd_path = get_cmd_path(args[0]);
		if (!cmd_path)
			printf("minishell: %s command not found\n", args[0]);
		else
			if (execve(cmd_path, args, envp) == -1)
				printf("execve: %s\n", strerror(errno));
	}
}
