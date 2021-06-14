/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:13:03 by aes-salm          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/06/14 15:51:08 by atahiri          ###   ########.fr       */
=======
/*   Updated: 2021/06/14 17:50:23 by aes-salm         ###   ########.fr       */
>>>>>>> 696108819b1c44ff21323d70bee3e311d34d81a5
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