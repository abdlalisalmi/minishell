/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:07:46 by aes-salm          #+#    #+#             */
/*   Updated: 2021/06/08 09:44:28 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void ft_env(void)
{
	int i = -1;
	while (++i < g_all.n_env)
	{
		if (g_all.env[i].name)
		{
			ft_putstr_fd(g_all.env[i].name, 1);
			ft_putstr_fd("=", 1);
			ft_putstr_fd(g_all.env[i].value, 1);
			ft_putstr_fd("\n", 1);
		}
	}
	set_env("?", "0");
}