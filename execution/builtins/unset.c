/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:03:15 by aes-salm          #+#    #+#             */
/*   Updated: 2021/05/26 17:27:30 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// void	update_env(char *name)
// {
	
// }

void	ft_unset(char **args)
{
	int i;

	i = -1;
	while (args[++i] != 0)
	{
		if (ft_isdigit(args[i][0]) || ft_strchr(args[i], '='))
		{
			ft_putstr_fd("bash: unset:: `", 1);
			ft_putstr_fd(args[i], 1);
			ft_putstr_fd("': not a valid identifier\n", 1);
		}
		else
			set_env(get_env_name(args[i]), get_env_value(args[i]));
	}
	return (1);
}