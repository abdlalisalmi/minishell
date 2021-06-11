/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:13:03 by aes-salm          #+#    #+#             */
/*   Updated: 2021/06/11 19:12:26 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void test(void)
{
	// set_env("?", "123456789");
	// printf("%s\n", get_env("?"));
	/* Print the env variables */
	// printf("--------------------------------------\n");
	// ft_env();
	// printf("--------------------------------------\n");

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

	char **args = malloc(sizeof(char*) * 2);
	args[0] = ft_strdup("cd");
	args[1] = ft_strdup("-");
	ft_cd(args, 2);
	// g_all.commands[0].args[2] = ft_strdup("world");
	// g_all.commands[0].n_args = 2;
	
	// ft_cd(g_all.commands[0].args, g_all.commands[0].n_args);
	// printf("%s\n", ft_pwd());
	// printf("$? = %s\n", get_env("?"));
	// printf("$? = %s\n", get_env("?"));

	// env = get_env("PWD");
	// printf("PWD = %s\n", env);

	/* Testing Export */
	// char **var = malloc(sizeof(char*) * 1);
	// char **var = NULL;
	// var[0] = ft_strdup("abdlali=hello world");
	// ft_export(var, 1);
	// printf("$? = %s\n", get_env("abdlali"));

	// *var = ft_strdup("1abdlali");
	// ft_export(var, 1);
	// printf("$? = %s\n", get_env("?"));

	// printf("--------------------------------------\n");
	// ft_env();
	// printf("--------------------------------------\n");

	/* End Testing Export */


	/* Testing Unset */
	// char **unset = malloc(sizeof(char*) * 1);
	// unset[0] = ft_strdup("abdlali");
	// ft_unset(unset);
	// printf("$? = %s\n", get_env("?"));


	// printf("--------------------------------------\n");
	// ft_env();
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

	// if (execve("/bin/echo", argv, envp) == -1)
    // 	printf("ERROR\n");

	// pid_t pid;
	// int status;
	// pid = fork();

	// if (pid == 0)
	// {
	// 	printf("I'm the child\n");
	// }
	// else if (pid < 0)
	// 	printf("FORK ERROR\n");
	// else
	// 	waitpid(pid, &status, 0);

	// printf("status : %d\n", status);
}

void start_execution(int n_commands, char **envp)
{
	if (n_commands == 1)
		exec_single_cmd(g_all.commands[0].args, g_all.commands[0].n_args, envp);
	else
	{
		printf("n_commands = %d\n", n_commands);
	}
}

// int main(int argc, char **args, char **envp)
// {
// 	init_struct();
// 	collect_env(envp);

// 	/*Tests*/
// 	// test();

// 	start_execution(args, envp);
// }