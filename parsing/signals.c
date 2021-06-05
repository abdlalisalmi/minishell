/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 00:20:19 by atahiri           #+#    #+#             */
/*   Updated: 2021/06/04 12:11:47 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* SIGINT is for Ctrl-C, SIGSTP is for Ctrl-Z, SIGQUIT is for Ctrl-\ */

void		signal_handlers(int sig)
{
	if (sig == SIGINT)
	{
		if (g_all.buff != NULL)
		{
			free(g_all.buff);
			write(1, "\n", 1);
			write(1, COLOR PROMPT, ft_strlen(PROMPT) + ft_strlen(COLOR));
		}
	}
}

void		init_signals(void)
{
	signal(SIGINT, signal_handlers);
}