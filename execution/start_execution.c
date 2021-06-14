/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:13:03 by aes-salm          #+#    #+#             */
/*   Updated: 2021/06/15 00:13:35 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

void start_execution(int n_commands, char **envp)
{
	if (n_commands == 1)
		exec_single_cmd(g_all.commands[0], envp);
	else
	{
		printf("Multiple commands : n_commands = %d\n", n_commands);
	}
}