/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:13:03 by aes-salm          #+#    #+#             */
/*   Updated: 2021/05/26 13:01:29 by aes-salm         ###   ########.fr       */
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

	// char *env = get_env("PWD");
	// printf("PWD = %s\n", env);


	// set_env("ARG", "hello world");
	// env = get_env("ARG");
	// printf("%s\n", env);

	// ft_pwd();
	// ft_cd("..", 1);

	// env = get_env("PWD");
	// printf("PWD = %s\n", env);

	/* Testing Export */
	char **var = malloc(sizeof(char*) * 3);
	var[0] = ft_strdup("abdlali=hello world");
	var[1] = ft_strdup("amine===hello world");
	var[2] = ft_strdup("test===hello world");
	ft_export(var);

	*var = ft_strdup("abdlali");
	ft_export(var);

	int i = -1;
	while (++i <= g_all.n_env)
	{
		ft_putstr_fd(g_all.env[i].name, 1);
		ft_putstr_fd("\t = \t", 1);
		ft_putstr_fd(g_all.env[i].value, 1);
		ft_putstr_fd("\n", 1);
	}

	/* End Testing Export */

	return (0);
}