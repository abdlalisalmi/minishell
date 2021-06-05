/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:01:52 by atahiri           #+#    #+#             */
/*   Updated: 2021/06/05 15:35:55 by atahiri          ###   ########.fr       */
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
	g_all.ret = 1;
	init_signals();
	// init_struct();
	while (g_all.ret > 0)
	{
		write(1, COLOR PROMPT, ft_strlen(PROMPT) + ft_strlen(COLOR));
		g_all.ret = ft_gnl(&g_all.buff);
		start_parsing(g_all.buff);
	}
	return (0);
}
