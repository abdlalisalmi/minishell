/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:33:08 by aes-salm          #+#    #+#             */
/*   Updated: 2021/06/09 10:52:34 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char exception_args(char **args)
{
	if (ft_strcmp(*args, "-"))
	{
		if (!get_env("OLDPWD"))
		{
			printf("cd: OLDPWD not set\n");
			set_env("?", "1");
			return (1);
		}
		else
		{
			*args = ft_strdup(get_env("OLDPWD"));
			printf("%s\n", get_env("PWD"));
		}
	}
	else
		*args = ft_strdup("..");
	return (0);
}

int ft_cd(char **args, int n_args)
{
	if (n_args >= 3)
	{
		if (n_args == 3)
			printf("cd: string not in pwd: %s\n", args[1]);
		else
			printf("cd: too many arguments\n");
		set_env("?", "1");
	}
	else
	{
		if (ft_strcmp(args[1], "-") || ft_strcmp(args[1], "--"))
			if (exception_args(&args[1]))
				return (1);
		if (chdir(args[1]) == -1)
		{
			printf("cd: no such file or directory: %s\n", args[1]);
			set_env("?", "1");
			return (1);
		}
		set_env("OLDPWD", get_env("PWD"));
		set_env("PWD", ft_pwd());
		set_env("?", "0");
	}
	return (0);
}