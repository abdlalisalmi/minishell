/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:01:52 by atahiri           #+#    #+#             */
/*   Updated: 2021/06/11 10:44:56 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	init_struct()
// {
	
// }


int	main(int argc, char **argv, char **envp)
{

	(void)argc;
	(void)argv;
	(void)envp;
	int		ret;

	ret = 1;
	init_signals();
	// init_struct();
	while (ret > 0)
	{
		write(1, COLOR PROMPT, ft_strlen(PROMPT) + ft_strlen(COLOR));
		ret = ft_gnl(&g_all.buff);
		start_parsing(g_all.buff, argv, envp);
	}
	return (0);
}
