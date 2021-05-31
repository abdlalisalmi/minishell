/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:33:08 by aes-salm          #+#    #+#             */
/*   Updated: 2021/05/31 10:54:19 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int ft_cd(char *path, int fd)
{
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