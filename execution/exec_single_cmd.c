/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_single_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:10:02 by aes-salm          #+#    #+#             */
/*   Updated: 2021/06/09 10:32:54 by aes-salm         ###   ########.fr       */
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

// void exec_builtins(char *cmd, char *args)
// {
// 	if (ft_strcmp(cmd, "cd"))
// 		ft_cd()
// }

void	exec_single_cmd(char *cmd, char **args, char **envp)
{
	char **paths;
	char *cmd_path;

	if (is_builtins(cmd))
		printf("HH");
	else
	{
		cmd_path = get_cmd_path(cmd);
		if (!cmd_path)
			printf("minishell: %s command not found\n", cmd);
		else
		{
			if (execve(cmd_path, args, envp) == -1)
				printf("ERROR\n");
		}
	}
}