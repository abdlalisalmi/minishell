/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:33:08 by aes-salm          #+#    #+#             */
/*   Updated: 2021/06/08 09:41:08 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char exception_args(char **path, int fd)
{
	if (ft_strcmp(*path, "-"))
	{
		if (!get_env("OLDPWD"))
		{
			ft_putstr_fd("cd: OLDPWD not set\n", fd);
			set_env("?", "1");
			return (1);
		}
		else
		{
			*path = ft_strdup(get_env("OLDPWD"));
			ft_putstr_fd(get_env("PWD"), fd);
			ft_putstr_fd("\n", fd);
		}
	}
	else
		*path = ft_strdup("..");
	return (0);
}

int ft_cd(char *path, int fd)
{
	if (ft_strcmp(path, "-") || ft_strcmp(path, "--"))
		if (exception_args(&path, fd))
			return (1);
	if (chdir(path) == -1)
	{
		ft_putstr_fd("cd: no such file or directory: ", fd);
		ft_putstr_fd(path, fd);
		ft_putstr_fd("\n", fd);
		set_env("?", "1");
		return (1);
	}
	set_env("OLDPWD", get_env("PWD"));
	set_env("PWD", ft_pwd());
	set_env("?", "0");
	return (0);
}