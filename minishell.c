/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:01:52 by atahiri           #+#    #+#             */
/*   Updated: 2021/06/11 17:45:13 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{

	(void)argc;
	(void)argv;
	int		ret;

	init_all_struct();
	collect_env(envp);
	init_signals();
	ret = 1;
	while (ret > 0)
	{
		write(1, COLOR PROMPT, ft_strlen(PROMPT) + ft_strlen(COLOR));
		ret = ft_gnl(&g_all.buff);
		start_parsing(g_all.buff, envp);
	}
	return (0);
}
