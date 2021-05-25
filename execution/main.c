/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:13:03 by aes-salm          #+#    #+#             */
/*   Updated: 2021/05/25 21:44:14 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int main(int argc, char **argv, char **envp)
{

	collect_env(envp);
	/* Print the env variables */
		// int i = -1;
		// while (++i <= g_all.n_env)
		// {
		// 	ft_putstr_fd(g_all.env[i].name, 1);
		// 	ft_putstr_fd("\t = \t", 1);
		// 	ft_putstr_fd(g_all.env[i].value, 1);
		// 	ft_putstr_fd("\n", 1);
		// }

	char *env = get_env("PWD");
	printf("PWD = %s\n", env);


	// set_env("ARG", "hello world");
	// env = get_env("ARG");
	// printf("%s\n", env);

	ft_pwd();
	ft_cd("..", 1);

	env = get_env("PWD");
	printf("PWD = %s\n", env);



	
	
	return (0);
}