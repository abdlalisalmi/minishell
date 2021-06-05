/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:13:03 by aes-salm          #+#    #+#             */
/*   Updated: 2021/06/04 11:58:27 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void init_struct(void)
{
	g_all.history.n_commands = 0;
}

int main(int argc, char **argv, char **envp)
{
	init_struct();
	collect_env(envp);
	// set_env("?", "123456789");
	// printf("%s\n", get_env("?"));
	/* Print the env variables */
	// int i = 0;
	// while (i < g_all.n_env)
	// {
	// 	ft_putstr_fd(g_all.env[i].name, 1);
	// 	ft_putstr_fd("\t = \t", 1);
	// 	ft_putstr_fd(g_all.env[i].value, 1);
	// 	ft_putstr_fd("\n", 1);
	// 	i++;
	// }
	
	/* Init History */
	// add_to_history("hello world");
	// printf("--------\n");
	// add_to_history("hello abdlali");
	// printf("--------\n");
	// add_to_history("hello ncj");
	// printf("--------\n");
	// add_to_history("hello amine");
	// printf("--------\n");
	// add_to_history("hello amincdcd");
	// add_to_history("hello ncgtgjnc");

	// int i = -1;
	// while (++i < g_all.history.n_commands)
	// 	printf("%s\n", g_all.history.commands[i]);
	

	/* End Init History */

	// char *env = get_env("PWD");
	// printf("PWD = %s\n", env);


	// set_env("ARG", "hello world");
	// env = get_env("ARG");
	// printf("%s\n", env);

	// ft_pwd();
	// printf("$? = %s\n", get_env("?"));
	
	// ft_cd("vfvf", 1);
	// printf("$? = %s\n", get_env("?"));

	// env = get_env("PWD");
	// printf("PWD = %s\n", env);

	/* Testing Export */
	// char **var = malloc(sizeof(char*) * 1);
	// var[0] = ft_strdup("abdlali=hello world");
	// ft_export(var);
	// printf("$? = %s\n", get_env("?"));

	// *var = ft_strdup("1abdlali");
	// ft_export(var);
	// printf("$? = %s\n", get_env("?"));

	// printf("--------------------------------------\n");
	// int i = -1;
	// while (++i <= g_all.n_env)
	// {
	// 	ft_putstr_fd(g_all.env[i].name, 1);
	// 	ft_putstr_fd("\t = \t", 1);
	// 	ft_putstr_fd(g_all.env[i].value, 1);
	// 	ft_putstr_fd("\n", 1);
	// }
	// printf("--------------------------------------\n");

	/* End Testing Export */


	/* Testing Unset */
	// char **unset = malloc(sizeof(char*) * 1);
	// unset[0] = ft_strdup("abdlali");
	// ft_unset(unset);
	// printf("$? = %s\n", get_env("?"));


	// printf("--------------------------------------\n");
	// i = -1;
	// while (++i <= g_all.n_env)
	// {
	// 	ft_putstr_fd(g_all.env[i].name, 1);
	// 	ft_putstr_fd("\t = \t", 1);
	// 	ft_putstr_fd(g_all.env[i].value, 1);
	// 	ft_putstr_fd("\n", 1);
	// }
	// printf("--------------------------------------\n");
	/* End Testing Unsett */

	/* Testing env */
	// ft_env();
	/* End Testing env */

	/* Testing exit */
	// ft_exit(0);
	/* End Testing exit */

	/* Testing echo */
	// char **echo = malloc(sizeof(char*) * 5);
	// echo[0] = ft_strdup("-n");
	// echo[1] = ft_strdup("-nnn");
	// echo[2] = ft_strdup("abdlali:");
	// echo[3] = ft_strdup("-n");
	// ft_echo(echo, 1);
	/* End Testing echo */

	if (execve("/bin/echo", argv, envp) == -1)
    	printf("ERROR\n");

	return (0);
}